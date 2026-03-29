%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.tab.h"

extern FILE *outFile;
%}

DIGIT      [0-9]
LETTER     [a-zA-Z]
ID         {LETTER}({LETTER}|{DIGIT}|_)*
INTNUM     {DIGIT}+
FLOATNUM   ({DIGIT}+"."{DIGIT}+)|({DIGIT}+"."{DIGIT}*)|("."{DIGIT}+)
STRING     \"([^\\\"\n]|\\.)*\"

%%

[ \t\r]+                    ;
\n                          ;

"//".*                      ;
"/*"([^*]|\*+[^*/])*\*+"/"  ;

"function"                  return FUNCTION;
"when"                      return WHEN;
"otherwise"                 return OTHERWISE;
"loop"                      return LOOP;
"reply"                     return REPLY;
"stop"                      return STOP;
"moveon"                    return MOVEON;
"take"                      return TAKE;
"show"                      return SHOW;

"true"                      return TRUE;
"false"                     return FALSE;

"++"                        return INC;
"--"                        return DEC;
"=="                        return EQ;
"!="                        return NEQ;
">="                        return GTE;
"<="                        return LTE;
"&&"                        return AND;
"||"                        return OR;

"+"                         return PLUS;
"-"                         return MINUS;
"*"                         return MUL;
"/"                         return DIV;
"%"                         return MOD;
"="                         return ASSIGN;
">"                         return GT;
"<"                         return LT;
"!"                         return NOT;

"("                         return LPAREN;
")"                         return RPAREN;
"{"                         return LBRACE;
"}"                         return RBRACE;
";"                         return SEMICOLON;
","                         return COMMA;

"___"{ID}                   { yylval.str = strdup(yytext); return BOOL_ID; }
"__"{ID}                    { yylval.str = strdup(yytext); return STRING_ID; }
"_."{ID}                    { yylval.str = strdup(yytext); return FLOAT_ID; }
"_"{ID}                     { yylval.str = strdup(yytext); return INT_ID; }

{FLOATNUM}                  { yylval.num = atof(yytext); return FLOAT_LITERAL; }
{INTNUM}                    { yylval.num = atof(yytext); return INT_LITERAL; }
{STRING}                    { yylval.str = strdup(yytext); return STRING_LITERAL; }
{ID}                        { yylval.str = strdup(yytext); return IDENTIFIER; }

.                           {
                                FILE *target = outFile ? outFile : stderr;
                                fprintf(target, "Invalid token '%s' at line %d\n", yytext, yylineno);
                            }

%%
