#include "parser_runtime.h"

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

struct Param {
    char *name;
    DataType type;
    struct Param *next;
};

struct ArgList {
    ASTNode *expr;
    struct ArgList *next;
};

struct ASTNode {
    NodeType type;
    DataType declared_type;
    Value literal;
    char *name;
    OperatorType op;
    ASTNode *left;
    ASTNode *right;
    ASTNode *expr;
    ASTNode *condition;
    ASTNode *then_branch;
    ASTNode *else_branch;
    ASTNode *body;
    ASTNode *init;
    ASTNode *update;
    ASTNode *first;
    ASTNode *next;
    Param *params;
    ArgList *args;
};

typedef struct Variable {
    char *name;
    DataType type;
    Value value;
    struct Variable *next;
} Variable;

typedef struct Scope {
    Variable *vars;
    struct Scope *parent;
} Scope;

typedef struct FunctionDef {
    char *name;
    Param *params;
    ASTNode *body;
    struct FunctionDef *next;
} FunctionDef;

typedef enum {
    FLOW_NORMAL,
    FLOW_RETURN,
    FLOW_BREAK,
    FLOW_CONTINUE
} FlowType;

typedef struct {
    FlowType flow;
    Value value;
} ExecResult;

FILE *outFile = NULL;
ASTNode *root = NULL;

static Scope *global_scope = NULL;
static Scope *current_scope = NULL;
static FunctionDef *functions = NULL;
static int error_count = 0;
static int loop_depth = 0;
static int function_depth = 0;

static char *xstrdup(const char *text);
static void fail_memory(void);
static void report_issue(const char *fmt, ...);
static char *normalize_name_dup(const char *raw);
static char *strip_quotes(const char *text);
static Value make_string_value(const char *text);
static Value make_void_value(void);
static Value make_error_value(void);
static Value copy_value(Value value);
static void free_value(Value value);
static Value default_value(DataType type);
static int is_numeric_type(DataType type);
static int is_integral_value(Value value);
static int truthy(Value value);
static void print_value(Value value);
static ASTNode *make_node(NodeType type);
static ASTNode *make_decl_node(DataType type, char *name, ASTNode *expr);
static Param *make_param(char *name, DataType type);
static Scope *make_scope(Scope *parent);
static Variable *find_local(Scope *scope, const char *name);
static Variable *find_variable(const char *name);
static int declare_variable(const char *name, DataType type, Value value);
static int assign_variable(const char *name, Value value);
static Value read_variable(const char *name);
static Value convert_value(Value value, DataType target, const char *name, int *ok);
static FunctionDef *find_function(const char *name);
static void register_function(ASTNode *node);
static void register_functions(ASTNode *program);
static Value eval_expr(ASTNode *node);
static Value apply_unary(OperatorType op, Value value);
static Value apply_binary(OperatorType op, Value left, Value right);
static Value call_function_runtime(const char *name, ArgList *args);
static ExecResult make_result(FlowType flow, Value value);
static ExecResult execute_statement(ASTNode *node);
static ExecResult execute_block(ASTNode *block);
static ExecResult execute_program(ASTNode *program);

static void fail_memory(void)
{
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
}

static char *xstrdup(const char *text)
{
    size_t len;
    char *copy;

    if (text == NULL) {
        return NULL;
    }

    len = strlen(text);
    copy = (char *)malloc(len + 1);
    if (copy == NULL) {
        fail_memory();
    }

    memcpy(copy, text, len + 1);
    return copy;
}

static void report_issue(const char *fmt, ...)
{
    va_list args;
    FILE *target = outFile ? outFile : stderr;

    error_count++;
    va_start(args, fmt);
    vfprintf(target, fmt, args);
    va_end(args);
    fprintf(target, "\n");
}

void runtime_note_error(void)
{
    error_count++;
}

static char *normalize_name_dup(const char *raw)
{
    while (*raw == '_') {
        raw++;
    }
    if (*raw == '.') {
        raw++;
    }
    return xstrdup(raw);
}

char *normalize_name_take(char *raw)
{
    char *name = normalize_name_dup(raw);
    free(raw);
    return name;
}

static char *strip_quotes(const char *text)
{
    size_t len;
    char *plain;

    if (text == NULL) {
        return xstrdup("");
    }

    len = strlen(text);
    if (len >= 2 && text[0] == '"' && text[len - 1] == '"') {
        plain = (char *)malloc(len - 1);
        if (plain == NULL) {
            fail_memory();
        }
        memcpy(plain, text + 1, len - 2);
        plain[len - 2] = '\0';
        return plain;
    }

    return xstrdup(text);
}

Value make_int_value(long long n)
{
    Value value;
    value.type = TYPE_INT;
    value.number = (double)n;
    value.boolean = (n != 0);
    value.string_value = NULL;
    return value;
}

Value make_float_value(double n)
{
    Value value;
    value.type = TYPE_FLOAT;
    value.number = n;
    value.boolean = fabs(n) > 1e-9;
    value.string_value = NULL;
    return value;
}

Value make_bool_value(int b)
{
    Value value;
    value.type = TYPE_BOOL;
    value.number = b ? 1.0 : 0.0;
    value.boolean = b ? 1 : 0;
    value.string_value = NULL;
    return value;
}

static Value make_string_value(const char *text)
{
    Value value;
    value.type = TYPE_STRING;
    value.number = 0.0;
    value.boolean = (text != NULL && text[0] != '\0');
    value.string_value = xstrdup(text ? text : "");
    return value;
}

static Value make_void_value(void)
{
    Value value;
    value.type = TYPE_VOID;
    value.number = 0.0;
    value.boolean = 0;
    value.string_value = NULL;
    return value;
}

static Value make_error_value(void)
{
    Value value;
    value.type = TYPE_ERROR;
    value.number = 0.0;
    value.boolean = 0;
    value.string_value = NULL;
    return value;
}

static Value copy_value(Value value)
{
    if (value.type == TYPE_STRING) {
        return make_string_value(value.string_value);
    }
    if (value.type == TYPE_INT) {
        return make_int_value((long long)round(value.number));
    }
    if (value.type == TYPE_FLOAT) {
        return make_float_value(value.number);
    }
    if (value.type == TYPE_BOOL) {
        return make_bool_value(value.boolean);
    }
    if (value.type == TYPE_VOID) {
        return make_void_value();
    }
    return make_error_value();
}

static void free_value(Value value)
{
    if (value.type == TYPE_STRING) {
        free(value.string_value);
    }
}

static Value default_value(DataType type)
{
    if (type == TYPE_INT) return make_int_value(0);
    if (type == TYPE_FLOAT) return make_float_value(0.0);
    if (type == TYPE_STRING) return make_string_value("");
    if (type == TYPE_BOOL) return make_bool_value(0);
    return make_void_value();
}

static int is_numeric_type(DataType type)
{
    return type == TYPE_INT || type == TYPE_FLOAT || type == TYPE_BOOL;
}

static int is_integral_value(Value value)
{
    double rounded = round(value.number);
    return fabs(value.number - rounded) < 1e-9;
}

static int truthy(Value value)
{
    if (value.type == TYPE_STRING) {
        return value.string_value != NULL && value.string_value[0] != '\0';
    }
    if (value.type == TYPE_BOOL) {
        return value.boolean;
    }
    if (is_numeric_type(value.type)) {
        return fabs(value.number) > 1e-9;
    }
    return 0;
}

static void print_value(Value value)
{
    FILE *target = outFile ? outFile : stdout;

    if (value.type == TYPE_STRING) {
        fprintf(target, "%s\n", value.string_value ? value.string_value : "");
    } else if (value.type == TYPE_BOOL) {
        fprintf(target, "%s\n", value.boolean ? "true" : "false");
    } else if (value.type == TYPE_INT) {
        fprintf(target, "%lld\n", (long long)round(value.number));
    } else if (value.type == TYPE_FLOAT) {
        fprintf(target, is_integral_value(value) ? "%.1f\n" : "%.6g\n", value.number);
    } else {
        fprintf(target, "void\n");
    }
}

static ASTNode *make_node(NodeType type)
{
    ASTNode *node = (ASTNode *)calloc(1, sizeof(ASTNode));
    if (node == NULL) {
        fail_memory();
    }
    node->type = type;
    return node;
}

ASTNode *append_statement(ASTNode *list, ASTNode *stmt)
{
    ASTNode *cursor;

    if (stmt == NULL) {
        return list;
    }
    stmt->next = NULL;

    if (list == NULL) {
        return stmt;
    }

    cursor = list;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = stmt;
    return list;
}

ASTNode *make_block(ASTNode *first)
{
    ASTNode *node = make_node(NODE_BLOCK);
    node->first = first;
    return node;
}

ASTNode *make_literal_node(Value value)
{
    ASTNode *node = make_node(NODE_LITERAL);
    node->literal = value;
    return node;
}

ASTNode *make_string_literal_node(char *text)
{
    char *plain = strip_quotes(text);
    ASTNode *node = make_literal_node(make_string_value(plain));
    free(plain);
    free(text);
    return node;
}

ASTNode *make_var_node(char *name)
{
    ASTNode *node = make_node(NODE_VAR);
    node->name = name;
    return node;
}

ASTNode *make_binary_node(OperatorType op, ASTNode *left, ASTNode *right)
{
    ASTNode *node = make_node(NODE_BINARY);
    node->op = op;
    node->left = left;
    node->right = right;
    return node;
}

ASTNode *make_unary_node(OperatorType op, ASTNode *expr)
{
    ASTNode *node = make_node(NODE_UNARY);
    node->op = op;
    node->expr = expr;
    return node;
}

static ASTNode *make_decl_node(DataType type, char *name, ASTNode *expr)
{
    ASTNode *node = make_node(NODE_DECL);
    node->declared_type = type;
    node->name = name;
    node->expr = expr;
    return node;
}

ASTNode *make_decl_from_raw(char *raw, DataType type, ASTNode *expr)
{
    return make_decl_node(type, normalize_name_take(raw), expr);
}

ASTNode *make_assign_node(char *name, ASTNode *expr)
{
    ASTNode *node = make_node(NODE_ASSIGN);
    node->name = name;
    node->expr = expr;
    return node;
}

ASTNode *make_show_node(ASTNode *expr)
{
    ASTNode *node = make_node(NODE_SHOW);
    node->expr = expr;
    return node;
}

ASTNode *make_take_node(char *name)
{
    ASTNode *node = make_node(NODE_TAKE);
    node->name = name;
    return node;
}

ASTNode *make_if_node(ASTNode *condition, ASTNode *then_branch, ASTNode *else_branch)
{
    ASTNode *node = make_node(NODE_IF);
    node->condition = condition;
    node->then_branch = then_branch;
    node->else_branch = else_branch;
    return node;
}

ASTNode *make_while_node(ASTNode *condition, ASTNode *body)
{
    ASTNode *node = make_node(NODE_WHILE);
    node->condition = condition;
    node->body = body;
    return node;
}

ASTNode *make_for_node(ASTNode *init, ASTNode *condition, ASTNode *update, ASTNode *body)
{
    ASTNode *node = make_node(NODE_FOR);
    node->init = init;
    node->condition = condition;
    node->update = update;
    node->body = body;
    return node;
}

ASTNode *make_function_def_node(char *name, Param *params, ASTNode *body)
{
    ASTNode *node = make_node(NODE_FUNC_DEF);
    node->name = name;
    node->params = params;
    node->body = body;
    return node;
}

ASTNode *make_return_node(ASTNode *expr)
{
    ASTNode *node = make_node(NODE_RETURN);
    node->expr = expr;
    return node;
}

ASTNode *make_flow_node(NodeType type)
{
    return make_node(type);
}

ASTNode *make_expr_stmt_node(ASTNode *expr)
{
    ASTNode *node = make_node(NODE_EXPR_STMT);
    node->expr = expr;
    return node;
}

ASTNode *make_function_call_node(char *name, ArgList *args)
{
    ASTNode *node = make_node(NODE_FUNC_CALL);
    node->name = name;
    node->args = args;
    return node;
}

ASTNode *make_update_node(char *name, OperatorType op)
{
    ASTNode *node = make_node(NODE_UPDATE);
    node->name = name;
    node->op = op;
    return node;
}

Param *append_param(Param *list, Param *item)
{
    Param *cursor;

    if (item == NULL) {
        return list;
    }
    if (list == NULL) {
        return item;
    }

    cursor = list;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = item;
    return list;
}

static Param *make_param(char *name, DataType type)
{
    Param *param = (Param *)calloc(1, sizeof(Param));
    if (param == NULL) {
        fail_memory();
    }
    param->name = name;
    param->type = type;
    return param;
}

Param *make_param_from_raw(char *raw, DataType type)
{
    return make_param(normalize_name_take(raw), type);
}

ArgList *make_arg(ASTNode *expr)
{
    ArgList *arg = (ArgList *)calloc(1, sizeof(ArgList));
    if (arg == NULL) {
        fail_memory();
    }
    arg->expr = expr;
    return arg;
}

ArgList *append_arg(ArgList *list, ASTNode *expr)
{
    ArgList *cursor;
    ArgList *item = make_arg(expr);

    if (list == NULL) {
        return item;
    }

    cursor = list;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = item;
    return list;
}

static Scope *make_scope(Scope *parent)
{
    Scope *scope = (Scope *)calloc(1, sizeof(Scope));
    if (scope == NULL) {
        fail_memory();
    }
    scope->parent = parent;
    return scope;
}

static Variable *find_local(Scope *scope, const char *name)
{
    Variable *var = scope ? scope->vars : NULL;

    while (var != NULL) {
        if (strcmp(var->name, name) == 0) {
            return var;
        }
        var = var->next;
    }
    return NULL;
}

static Variable *find_variable(const char *name)
{
    Scope *scope = current_scope;

    while (scope != NULL) {
        Variable *var = find_local(scope, name);
        if (var != NULL) {
            return var;
        }
        scope = scope->parent;
    }
    return NULL;
}

static Value convert_value(Value value, DataType target, const char *name, int *ok)
{
    *ok = 1;

    if (value.type == TYPE_ERROR) {
        *ok = 0;
        return make_error_value();
    }

    if (target == TYPE_INT) {
        if (!is_numeric_type(value.type)) {
            report_issue("Type Error: variable '%s' expects int", name);
            *ok = 0;
            free_value(value);
            return make_error_value();
        }
        free_value(value);
        return make_int_value((long long)round(value.number));
    }

    if (target == TYPE_FLOAT) {
        if (!is_numeric_type(value.type)) {
            report_issue("Type Error: variable '%s' expects float", name);
            *ok = 0;
            free_value(value);
            return make_error_value();
        }
        free_value(value);
        return make_float_value(value.number);
    }

    if (target == TYPE_BOOL) {
        if (value.type == TYPE_STRING) {
            report_issue("Type Error: variable '%s' expects bool", name);
            *ok = 0;
            free_value(value);
            return make_error_value();
        }
        free_value(value);
        return make_bool_value(truthy(value));
    }

    if (target == TYPE_STRING) {
        if (value.type != TYPE_STRING) {
            report_issue("Type Error: variable '%s' expects string", name);
            *ok = 0;
            free_value(value);
            return make_error_value();
        }
        return value;
    }

    free_value(value);
    return make_void_value();
}

static int declare_variable(const char *name, DataType type, Value value)
{
    Variable *var;

    if (find_local(current_scope, name) != NULL) {
        report_issue("Semantic Error: redeclaration of variable '%s'", name);
        free_value(value);
        return 0;
    }

    var = (Variable *)calloc(1, sizeof(Variable));
    if (var == NULL) {
        fail_memory();
    }
    var->name = xstrdup(name);
    var->type = type;
    var->value = value;
    var->next = current_scope->vars;
    current_scope->vars = var;
    return 1;
}

static int assign_variable(const char *name, Value value)
{
    Variable *var = find_variable(name);
    Value converted;
    int ok = 1;

    if (var == NULL) {
        report_issue("Semantic Error: variable '%s' used before declaration", name);
        free_value(value);
        return 0;
    }

    converted = convert_value(value, var->type, name, &ok);
    if (!ok) {
        return 0;
    }

    free_value(var->value);
    var->value = converted;
    return 1;
}

static Value read_variable(const char *name)
{
    Variable *var = find_variable(name);

    if (var == NULL) {
        report_issue("Semantic Error: variable '%s' used before declaration", name);
        return make_error_value();
    }

    return copy_value(var->value);
}

static FunctionDef *find_function(const char *name)
{
    FunctionDef *func = functions;

    while (func != NULL) {
        if (strcmp(func->name, name) == 0) {
            return func;
        }
        func = func->next;
    }
    return NULL;
}

static void register_function(ASTNode *node)
{
    FunctionDef *func;

    if (find_function(node->name) != NULL) {
        report_issue("Semantic Error: function '%s' already defined", node->name);
        return;
    }

    func = (FunctionDef *)calloc(1, sizeof(FunctionDef));
    if (func == NULL) {
        fail_memory();
    }
    func->name = xstrdup(node->name);
    func->params = node->params;
    func->body = node->body;
    func->next = functions;
    functions = func;
}

static void register_functions(ASTNode *program)
{
    ASTNode *stmt;

    if (program == NULL || program->type != NODE_BLOCK) {
        return;
    }

    stmt = program->first;
    while (stmt != NULL) {
        if (stmt->type == NODE_FUNC_DEF) {
            register_function(stmt);
        }
        stmt = stmt->next;
    }
}

static Value apply_unary(OperatorType op, Value value)
{
    if (op == OP_NOT) {
        int flag = !truthy(value);
        free_value(value);
        return make_bool_value(flag);
    }

    if (!is_numeric_type(value.type)) {
        report_issue("Type Error: unary '-' requires numeric value");
        free_value(value);
        return make_error_value();
    }

    if (value.type == TYPE_FLOAT) {
        double number = -value.number;
        free_value(value);
        return make_float_value(number);
    }

    {
        long long number = (long long)round(-value.number);
        free_value(value);
        return make_int_value(number);
    }
}

static Value apply_binary(OperatorType op, Value left, Value right)
{
    Value result = make_error_value();
    int left_float = left.type == TYPE_FLOAT;
    int right_float = right.type == TYPE_FLOAT;

    if (op == OP_AND || op == OP_OR) {
        result = make_bool_value(op == OP_AND ? truthy(left) && truthy(right)
                                              : truthy(left) || truthy(right));
        free_value(left);
        free_value(right);
        return result;
    }

    if (op == OP_EQ || op == OP_NEQ) {
        int equal = 0;

        if (left.type == TYPE_STRING && right.type == TYPE_STRING) {
            equal = strcmp(left.string_value ? left.string_value : "",
                           right.string_value ? right.string_value : "") == 0;
        } else if (is_numeric_type(left.type) && is_numeric_type(right.type)) {
            equal = fabs(left.number - right.number) < 1e-9;
        } else if (left.type == TYPE_BOOL && right.type == TYPE_BOOL) {
            equal = left.boolean == right.boolean;
        } else {
            report_issue("Type Error: invalid equality comparison");
            free_value(left);
            free_value(right);
            return make_error_value();
        }

        result = make_bool_value(op == OP_EQ ? equal : !equal);
        free_value(left);
        free_value(right);
        return result;
    }

    if (!is_numeric_type(left.type) || !is_numeric_type(right.type)) {
        report_issue("Type Error: numeric values are required here");
        free_value(left);
        free_value(right);
        return make_error_value();
    }

    if (op == OP_ADD) {
        result = (left_float || right_float)
            ? make_float_value(left.number + right.number)
            : make_int_value((long long)round(left.number + right.number));
    } else if (op == OP_SUB) {
        result = (left_float || right_float)
            ? make_float_value(left.number - right.number)
            : make_int_value((long long)round(left.number - right.number));
    } else if (op == OP_MUL) {
        result = (left_float || right_float)
            ? make_float_value(left.number * right.number)
            : make_int_value((long long)round(left.number * right.number));
    } else if (op == OP_DIV) {
        if (fabs(right.number) < 1e-9) {
            report_issue("Runtime Error: division by zero");
            free_value(left);
            free_value(right);
            return make_error_value();
        }
        result = make_float_value(left.number / right.number);
    } else if (op == OP_MOD) {
        if (fabs(right.number) < 1e-9) {
            report_issue("Runtime Error: modulus by zero");
            free_value(left);
            free_value(right);
            return make_error_value();
        }
        result = make_int_value((long long)left.number % (long long)right.number);
    } else if (op == OP_GT) {
        result = make_bool_value(left.number > right.number);
    } else if (op == OP_LT) {
        result = make_bool_value(left.number < right.number);
    } else if (op == OP_GTE) {
        result = make_bool_value(left.number >= right.number);
    } else if (op == OP_LTE) {
        result = make_bool_value(left.number <= right.number);
    }

    free_value(left);
    free_value(right);
    return result;
}

static Value eval_expr(ASTNode *node)
{
    Value left;
    Value right;

    if (node == NULL) {
        return make_void_value();
    }

    switch (node->type) {
        case NODE_LITERAL:
            return copy_value(node->literal);

        case NODE_VAR:
            return read_variable(node->name);

        case NODE_FUNC_CALL:
            return call_function_runtime(node->name, node->args);

        case NODE_UNARY:
            return apply_unary(node->op, eval_expr(node->expr));

        case NODE_BINARY:
            if (node->op == OP_AND) {
                left = eval_expr(node->left);
                if (!truthy(left)) {
                    free_value(left);
                    return make_bool_value(0);
                }
                right = eval_expr(node->right);
                free_value(left);
                return make_bool_value(truthy(right));
            }
            if (node->op == OP_OR) {
                left = eval_expr(node->left);
                if (truthy(left)) {
                    free_value(left);
                    return make_bool_value(1);
                }
                right = eval_expr(node->right);
                free_value(left);
                return make_bool_value(truthy(right));
            }
            left = eval_expr(node->left);
            right = eval_expr(node->right);
            return apply_binary(node->op, left, right);

        default:
            report_issue("Runtime Error: invalid expression");
            return make_error_value();
    }
}

static Value call_function_runtime(const char *name, ArgList *args)
{
    FunctionDef *func = find_function(name);
    Scope *saved_scope = current_scope;
    Scope *local_scope;
    Param *param;
    ArgList *arg;
    ExecResult result;

    if (func == NULL) {
        report_issue("Semantic Error: undefined function '%s'", name);
        return make_error_value();
    }

    param = func->params;
    arg = args;
    while (param != NULL && arg != NULL) {
        param = param->next;
        arg = arg->next;
    }
    if (param != NULL || arg != NULL) {
        report_issue("Semantic Error: wrong number of arguments in call to '%s'", name);
        return make_error_value();
    }

    local_scope = make_scope(global_scope);
    current_scope = local_scope;

    param = func->params;
    arg = args;
    while (param != NULL && arg != NULL) {
        Value value = eval_expr(arg->expr);
        Value converted;
        int ok = 1;

        converted = convert_value(value, param->type, param->name, &ok);
        if (!ok) {
            current_scope = saved_scope;
            return make_error_value();
        }
        declare_variable(param->name, param->type, converted);
        param = param->next;
        arg = arg->next;
    }

    function_depth++;
    result = execute_block(func->body);
    function_depth--;
    current_scope = saved_scope;

    if (result.flow == FLOW_RETURN) {
        return result.value;
    }

    free_value(result.value);
    return make_void_value();
}

static ExecResult make_result(FlowType flow, Value value)
{
    ExecResult result;
    result.flow = flow;
    result.value = value;
    return result;
}

static ExecResult execute_statement(ASTNode *node)
{
    if (node == NULL) {
        return make_result(FLOW_NORMAL, make_void_value());
    }

    switch (node->type) {
        case NODE_BLOCK:
            return execute_block(node);

        case NODE_DECL: {
            Value value = node->expr ? eval_expr(node->expr) : default_value(node->declared_type);
            Value converted;
            int ok = 1;

            converted = convert_value(value, node->declared_type, node->name, &ok);
            if (ok) {
                declare_variable(node->name, node->declared_type, converted);
            }
            return make_result(FLOW_NORMAL, make_void_value());
        }

        case NODE_ASSIGN:
            assign_variable(node->name, eval_expr(node->expr));
            return make_result(FLOW_NORMAL, make_void_value());

        case NODE_SHOW: {
            Value value = eval_expr(node->expr);
            if (value.type != TYPE_ERROR) {
                print_value(value);
            }
            free_value(value);
            return make_result(FLOW_NORMAL, make_void_value());
        }

        case NODE_TAKE: {
            Variable *var = find_variable(node->name);
            char buffer[512];

            if (var == NULL) {
                report_issue("Semantic Error: variable '%s' used before declaration", node->name);
                return make_result(FLOW_NORMAL, make_void_value());
            }

            fprintf(stdout, "Input %s: ", node->name);
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                report_issue("Runtime Error: failed to read input for '%s'", node->name);
                return make_result(FLOW_NORMAL, make_void_value());
            }

            if (var->type == TYPE_STRING) {
                size_t len = strlen(buffer);
                if (len > 0 && buffer[len - 1] == '\n') {
                    buffer[len - 1] = '\0';
                }
                assign_variable(node->name, make_string_value(buffer));
            } else if (var->type == TYPE_BOOL) {
                assign_variable(node->name,
                                make_bool_value(strncmp(buffer, "true", 4) == 0 ||
                                                strncmp(buffer, "1", 1) == 0));
            } else if (var->type == TYPE_FLOAT) {
                assign_variable(node->name, make_float_value(strtod(buffer, NULL)));
            } else {
                assign_variable(node->name, make_int_value(strtoll(buffer, NULL, 10)));
            }
            return make_result(FLOW_NORMAL, make_void_value());
        }

        case NODE_IF: {
            Value cond = eval_expr(node->condition);
            int is_true = truthy(cond);
            free_value(cond);
            if (is_true) {
                return execute_statement(node->then_branch);
            }
            if (node->else_branch != NULL) {
                return execute_statement(node->else_branch);
            }
            return make_result(FLOW_NORMAL, make_void_value());
        }

        case NODE_WHILE: {
            ExecResult result = make_result(FLOW_NORMAL, make_void_value());

            if (loop_depth > 0) {
                report_issue("Semantic Error: nested loops are not supported in this beginner version");
                return result;
            }

            loop_depth++;
            while (1) {
                Value cond = eval_expr(node->condition);
                int is_true = truthy(cond);
                free_value(cond);
                if (!is_true) {
                    break;
                }

                result = execute_statement(node->body);
                if (result.flow == FLOW_RETURN) {
                    loop_depth--;
                    return result;
                }
                if (result.flow == FLOW_BREAK) {
                    loop_depth--;
                    return make_result(FLOW_NORMAL, make_void_value());
                }
                if (result.flow == FLOW_CONTINUE) {
                    result.flow = FLOW_NORMAL;
                }
                free_value(result.value);
                result.value = make_void_value();
            }
            loop_depth--;
            return result;
        }

        case NODE_FOR: {
            ExecResult result = make_result(FLOW_NORMAL, make_void_value());

            if (loop_depth > 0) {
                report_issue("Semantic Error: nested loops are not supported in this beginner version");
                return result;
            }

            if (node->init != NULL) {
                free_value(execute_statement(node->init).value);
            }

            loop_depth++;
            while (1) {
                int is_true = 1;

                if (node->condition != NULL) {
                    Value cond = eval_expr(node->condition);
                    is_true = truthy(cond);
                    free_value(cond);
                }
                if (!is_true) {
                    break;
                }

                result = execute_statement(node->body);
                if (result.flow == FLOW_RETURN) {
                    loop_depth--;
                    return result;
                }
                if (result.flow == FLOW_BREAK) {
                    loop_depth--;
                    return make_result(FLOW_NORMAL, make_void_value());
                }
                if (node->update != NULL) {
                    free_value(execute_statement(node->update).value);
                }
                if (result.flow == FLOW_CONTINUE) {
                    result.flow = FLOW_NORMAL;
                }
                free_value(result.value);
                result.value = make_void_value();
            }
            loop_depth--;
            return result;
        }

        case NODE_FUNC_DEF:
            return make_result(FLOW_NORMAL, make_void_value());

        case NODE_RETURN:
            if (function_depth == 0) {
                report_issue("Semantic Error: 'reply' used outside function");
                return make_result(FLOW_NORMAL, make_void_value());
            }
            return make_result(FLOW_RETURN, eval_expr(node->expr));

        case NODE_BREAK:
            if (loop_depth == 0) {
                report_issue("Semantic Error: 'stop' used outside loop");
                return make_result(FLOW_NORMAL, make_void_value());
            }
            return make_result(FLOW_BREAK, make_void_value());

        case NODE_CONTINUE:
            if (loop_depth == 0) {
                report_issue("Semantic Error: 'moveon' used outside loop");
                return make_result(FLOW_NORMAL, make_void_value());
            }
            return make_result(FLOW_CONTINUE, make_void_value());

        case NODE_EXPR_STMT: {
            Value value = eval_expr(node->expr);
            free_value(value);
            return make_result(FLOW_NORMAL, make_void_value());
        }

        case NODE_UPDATE: {
            Variable *var = find_variable(node->name);
            double number;

            if (var == NULL) {
                report_issue("Semantic Error: variable '%s' used before declaration", node->name);
                return make_result(FLOW_NORMAL, make_void_value());
            }
            if (!is_numeric_type(var->type)) {
                report_issue("Type Error: '%s' must be numeric for ++ or --", node->name);
                return make_result(FLOW_NORMAL, make_void_value());
            }

            number = var->value.number + (node->op == OP_INC ? 1.0 : -1.0);
            if (var->type == TYPE_FLOAT) {
                assign_variable(node->name, make_float_value(number));
            } else {
                assign_variable(node->name, make_int_value((long long)round(number)));
            }
            return make_result(FLOW_NORMAL, make_void_value());
        }

        default:
            report_issue("Runtime Error: unsupported statement");
            return make_result(FLOW_NORMAL, make_void_value());
    }
}

static ExecResult execute_block(ASTNode *block)
{
    ASTNode *stmt;
    ExecResult result = make_result(FLOW_NORMAL, make_void_value());

    if (block == NULL || block->type != NODE_BLOCK) {
        return result;
    }

    stmt = block->first;
    while (stmt != NULL) {
        free_value(result.value);
        result = execute_statement(stmt);
        if (result.flow != FLOW_NORMAL) {
            return result;
        }
        stmt = stmt->next;
    }
    return result;
}

static ExecResult execute_program(ASTNode *program)
{
    ASTNode *stmt;
    ExecResult result = make_result(FLOW_NORMAL, make_void_value());

    register_functions(program);
    if (program == NULL || program->type != NODE_BLOCK) {
        return result;
    }

    stmt = program->first;
    while (stmt != NULL) {
        if (stmt->type != NODE_FUNC_DEF) {
            free_value(result.value);
            result = execute_statement(stmt);
            if (result.flow == FLOW_RETURN) {
                report_issue("Semantic Error: 'reply' used outside function");
                free_value(result.value);
                result = make_result(FLOW_NORMAL, make_void_value());
            } else if (result.flow == FLOW_BREAK || result.flow == FLOW_CONTINUE) {
                report_issue("Semantic Error: loop control used outside loop");
                free_value(result.value);
                result = make_result(FLOW_NORMAL, make_void_value());
            }
        }
        stmt = stmt->next;
    }
    return result;
}

void runtime_init(void)
{
    root = NULL;
    functions = NULL;
    error_count = 0;
    loop_depth = 0;
    function_depth = 0;
    global_scope = make_scope(NULL);
    current_scope = global_scope;
}

void runtime_execute_root(void)
{
    if (root != NULL) {
        ExecResult result = execute_program(root);
        free_value(result.value);
    }
}

int runtime_has_errors(void)
{
    return error_count > 0;
}
