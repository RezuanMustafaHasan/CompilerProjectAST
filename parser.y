%{
#include <stdio.h>

#include "parser_runtime.h"

int yylex(void);
int yyerror(const char *s);
extern int yylineno;
extern FILE *yyin;
%}

%union {
    double num;
    char *str;
    void *ptr;
}

%token FUNCTION WHEN OTHERWISE LOOP REPLY STOP MOVEON TAKE SHOW
%token TRUE FALSE
%token <num> INT_LITERAL FLOAT_LITERAL
%token <str> STRING_LITERAL
%token <str> IDENTIFIER INT_ID FLOAT_ID STRING_ID BOOL_ID
%token PLUS MINUS MUL DIV MOD
%token ASSIGN
%token EQ NEQ GT LT GTE LTE
%token AND OR NOT
%token INC DEC
%token LPAREN RPAREN LBRACE RBRACE
%token SEMICOLON COMMA

%type <ptr> program top_list top_item stmt_list statement simple_stmt block
%type <ptr> declaration_stmt assignment_stmt show_stmt take_stmt if_stmt else_tail
%type <ptr> loop_stmt function_def return_stmt function_call_stmt break_stmt continue_stmt
%type <ptr> declaration_core assignment_core loop_init_opt loop_update_opt update_core
%type <ptr> expr function_call literal
%type <ptr> param_list_opt param_list param_decl
%type <ptr> arg_list_opt arg_list
%type <str> var_ref name_token

%expect 4
%left OR
%left AND
%left EQ NEQ
%left GT LT GTE LTE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%right UMINUS

%%

program
    : top_list { root = make_block($1); $$ = root; }
    ;

top_list
    : top_list top_item { $$ = append_statement($1, $2); }
    | { $$ = NULL; }
    ;

top_item
    : function_def
    | statement
    ;

stmt_list
    : stmt_list statement { $$ = append_statement($1, $2); }
    | { $$ = NULL; }
    ;

statement : simple_stmt | block ;

simple_stmt
    : declaration_stmt
    | assignment_stmt
    | show_stmt
    | take_stmt
    | if_stmt
    | loop_stmt
    | function_call_stmt
    | return_stmt
    | break_stmt
    | continue_stmt
    ;

name_token : IDENTIFIER | INT_ID | FLOAT_ID | STRING_ID | BOOL_ID ;

literal
    : INT_LITERAL { $$ = make_literal_node(make_int_value((long long)$1)); }
    | FLOAT_LITERAL { $$ = make_literal_node(make_float_value($1)); }
    | STRING_LITERAL { $$ = make_string_literal_node($1); }
    | TRUE { $$ = make_literal_node(make_bool_value(1)); }
    | FALSE { $$ = make_literal_node(make_bool_value(0)); }
    ;

block : LBRACE stmt_list RBRACE { $$ = make_block($2); } ;

declaration_stmt : declaration_core SEMICOLON { $$ = $1; } ;

declaration_core
    : INT_ID { $$ = make_decl_from_raw($1, TYPE_INT, NULL); }
    | INT_ID ASSIGN expr { $$ = make_decl_from_raw($1, TYPE_INT, $3); }
    | FLOAT_ID { $$ = make_decl_from_raw($1, TYPE_FLOAT, NULL); }
    | FLOAT_ID ASSIGN expr { $$ = make_decl_from_raw($1, TYPE_FLOAT, $3); }
    | STRING_ID { $$ = make_decl_from_raw($1, TYPE_STRING, NULL); }
    | STRING_ID ASSIGN expr { $$ = make_decl_from_raw($1, TYPE_STRING, $3); }
    | BOOL_ID { $$ = make_decl_from_raw($1, TYPE_BOOL, NULL); }
    | BOOL_ID ASSIGN expr { $$ = make_decl_from_raw($1, TYPE_BOOL, $3); }
    ;

assignment_stmt : assignment_core SEMICOLON { $$ = $1; } ;

assignment_core : var_ref ASSIGN expr { $$ = make_assign_node($1, $3); } ;

show_stmt : SHOW LPAREN expr RPAREN SEMICOLON { $$ = make_show_node($3); } ;

take_stmt : TAKE LPAREN var_ref RPAREN SEMICOLON { $$ = make_take_node($3); } ;

if_stmt : WHEN LPAREN expr RPAREN block else_tail { $$ = make_if_node($3, $5, $6); } ;

else_tail
    : OTHERWISE if_stmt { $$ = $2; }
    | OTHERWISE block { $$ = $2; }
    | { $$ = NULL; }
    ;

loop_stmt
    : LOOP LPAREN expr RPAREN block { $$ = make_while_node($3, $5); }
    | LOOP LPAREN loop_init_opt SEMICOLON expr SEMICOLON loop_update_opt RPAREN block
        { $$ = make_for_node($3, $5, $7, $9); }
    ;

loop_init_opt : declaration_core | assignment_core | { $$ = NULL; } ;
loop_update_opt : assignment_core | update_core | { $$ = NULL; } ;

update_core
    : var_ref INC { $$ = make_update_node($1, OP_INC); }
    | var_ref DEC { $$ = make_update_node($1, OP_DEC); }
    ;

function_def
    : FUNCTION IDENTIFIER LPAREN param_list_opt RPAREN block
        { $$ = make_function_def_node($2, $4, $6); }
    ;

param_list_opt : param_list | { $$ = NULL; } ;

param_list
    : param_list COMMA param_decl { $$ = append_param($1, $3); }
    | param_decl { $$ = $1; }
    ;

param_decl
    : INT_ID { $$ = make_param_from_raw($1, TYPE_INT); }
    | FLOAT_ID { $$ = make_param_from_raw($1, TYPE_FLOAT); }
    | STRING_ID { $$ = make_param_from_raw($1, TYPE_STRING); }
    | BOOL_ID { $$ = make_param_from_raw($1, TYPE_BOOL); }
    ;

function_call_stmt : function_call SEMICOLON { $$ = make_expr_stmt_node($1); } ;
return_stmt : REPLY expr SEMICOLON { $$ = make_return_node($2); } ;
break_stmt : STOP SEMICOLON { $$ = make_flow_node(NODE_BREAK); } ;
continue_stmt : MOVEON SEMICOLON { $$ = make_flow_node(NODE_CONTINUE); } ;

arg_list_opt : arg_list | { $$ = NULL; } ;

arg_list
    : arg_list COMMA expr { $$ = append_arg($1, $3); }
    | expr { $$ = make_arg($1); }
    ;

function_call : IDENTIFIER LPAREN arg_list_opt RPAREN { $$ = make_function_call_node($1, $3); } ;
var_ref : name_token { $$ = normalize_name_take($1); } ;

expr
    : literal
    | var_ref { $$ = make_var_node($1); }
    | function_call { $$ = $1; }
    | expr PLUS expr { $$ = make_binary_node(OP_ADD, $1, $3); }
    | expr MINUS expr { $$ = make_binary_node(OP_SUB, $1, $3); }
    | expr MUL expr { $$ = make_binary_node(OP_MUL, $1, $3); }
    | expr DIV expr { $$ = make_binary_node(OP_DIV, $1, $3); }
    | expr MOD expr { $$ = make_binary_node(OP_MOD, $1, $3); }
    | expr EQ expr { $$ = make_binary_node(OP_EQ, $1, $3); }
    | expr NEQ expr { $$ = make_binary_node(OP_NEQ, $1, $3); }
    | expr GT expr { $$ = make_binary_node(OP_GT, $1, $3); }
    | expr LT expr { $$ = make_binary_node(OP_LT, $1, $3); }
    | expr GTE expr { $$ = make_binary_node(OP_GTE, $1, $3); }
    | expr LTE expr { $$ = make_binary_node(OP_LTE, $1, $3); }
    | expr AND expr { $$ = make_binary_node(OP_AND, $1, $3); }
    | expr OR expr { $$ = make_binary_node(OP_OR, $1, $3); }
    | NOT expr { $$ = make_unary_node(OP_NOT, $2); }
    | MINUS expr %prec UMINUS { $$ = make_unary_node(OP_NEG, $2); }
    | LPAREN expr RPAREN { $$ = $2; }
    ;

%%

int main(void)
{
    int choice;
    char filename[256];

    printf("Mini Compiler\n");
    printf("1) Type code\n");
    printf("2) Read file\n");
    printf("Choose: ");

    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Invalid choice\n");
        return 1;
    }
    getchar();

    if (choice == 2) {
        printf("File name: ");
        if (scanf("%255s", filename) != 1) {
            fprintf(stderr, "Invalid file name\n");
            return 1;
        }
        getchar();

        yyin = fopen(filename, "r");
        if (yyin == NULL) {
            fprintf(stderr, "Cannot open file\n");
            return 1;
        }

        outFile = fopen("output.txt", "w");
        if (outFile == NULL) {
            fclose(yyin);
            fprintf(stderr, "Cannot open output.txt\n");
            return 1;
        }
    } else {
        yyin = stdin;
        outFile = stdout;
    }

    runtime_init();
    yyparse();
    runtime_execute_root();

    if (choice == 2) {
        fclose(yyin);
        fclose(outFile);
        printf("Output saved in output.txt\n");
    }

    return runtime_has_errors() ? 1 : 0;
}

int yyerror(const char *s)
{
    FILE *target = outFile ? outFile : stderr;
    runtime_note_error();
    fprintf(target, "Syntax Error at line %d: %s\n", yylineno, s);
    return 0;
}
