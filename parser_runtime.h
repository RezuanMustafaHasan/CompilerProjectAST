#ifndef PARSER_RUNTIME_H
#define PARSER_RUNTIME_H

#include <stdio.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_BOOL,
    TYPE_VOID,
    TYPE_ERROR
} DataType;

typedef enum {
    NODE_BLOCK,
    NODE_DECL,
    NODE_ASSIGN,
    NODE_SHOW,
    NODE_TAKE,
    NODE_IF,
    NODE_WHILE,
    NODE_FOR,
    NODE_FUNC_DEF,
    NODE_RETURN,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_EXPR_STMT,
    NODE_LITERAL,
    NODE_VAR,
    NODE_BINARY,
    NODE_UNARY,
    NODE_FUNC_CALL,
    NODE_UPDATE
} NodeType;

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_EQ,
    OP_NEQ,
    OP_GT,
    OP_LT,
    OP_GTE,
    OP_LTE,
    OP_AND,
    OP_OR,
    OP_NEG,
    OP_NOT,
    OP_INC,
    OP_DEC
} OperatorType;

typedef struct Value {
    DataType type;
    double number;
    int boolean;
    char *string_value;
} Value;

typedef struct ASTNode ASTNode;
typedef struct Param Param;
typedef struct ArgList ArgList;

extern FILE *outFile;
extern ASTNode *root;

char *normalize_name_take(char *raw);

Value make_int_value(long long n);
Value make_float_value(double n);
Value make_bool_value(int b);
ASTNode *append_statement(ASTNode *list, ASTNode *stmt);
ASTNode *make_block(ASTNode *first);
ASTNode *make_literal_node(Value value);
ASTNode *make_string_literal_node(char *text);
ASTNode *make_var_node(char *name);
ASTNode *make_binary_node(OperatorType op, ASTNode *left, ASTNode *right);
ASTNode *make_unary_node(OperatorType op, ASTNode *expr);
ASTNode *make_decl_from_raw(char *raw, DataType type, ASTNode *expr);
ASTNode *make_assign_node(char *name, ASTNode *expr);
ASTNode *make_show_node(ASTNode *expr);
ASTNode *make_take_node(char *name);
ASTNode *make_if_node(ASTNode *condition, ASTNode *then_branch, ASTNode *else_branch);
ASTNode *make_while_node(ASTNode *condition, ASTNode *body);
ASTNode *make_for_node(ASTNode *init, ASTNode *condition, ASTNode *update, ASTNode *body);
ASTNode *make_function_def_node(char *name, Param *params, ASTNode *body);
ASTNode *make_return_node(ASTNode *expr);
ASTNode *make_flow_node(NodeType type);
ASTNode *make_expr_stmt_node(ASTNode *expr);
ASTNode *make_function_call_node(char *name, ArgList *args);
ASTNode *make_update_node(char *name, OperatorType op);
Param *append_param(Param *list, Param *item);
Param *make_param_from_raw(char *raw, DataType type);
ArgList *append_arg(ArgList *list, ASTNode *expr);
ArgList *make_arg(ASTNode *expr);

void runtime_init(void);
void runtime_execute_root(void);
void runtime_note_error(void);
int runtime_has_errors(void);

#endif
