%option noyywrap
%{
#include "compilator.tab.h"
#include <stdlib.h>
#include <string.h>

int lineNo = 1;
int colNo = 1;
%}

DIGIT       [0-9]
LETTER      [a-zA-Z]
ID          {LETTER}({LETTER}|{DIGIT})*
INTEGER     {DIGIT}+
FLOAT       {INTEGER}"."{DIGIT}+f
DOUBLE      {INTEGER}"."{DIGIT}+
WHITESPACE  [ \t\r]

%%


"//"([^'\n'])*							{ colNo += strlen(yytext); }
"/*"([^*]|\*+[^*/])*\*+"/"				{ 
											int len = strlen(yytext);
											int newlines = 0;
											for (int i = 0; i < len; i++) {
												if (yytext[i] == '\n') {
													newlines++;
												}
											}
											lineNo += newlines;
											if (newlines > 0) {
												colNo = len - (yytext + len - 1 - strrchr(yytext, '\n'));
											} else {
												colNo += len;
											}
                                        }  
"int"       { colNo += yyleng; return TOK_DECLARE_INT; }
"double"    { colNo += yyleng; return TOK_DECLARE_DOUBLE; }
"float"     { colNo += yyleng; return TOK_DECLARE_FLOAT; }
"if"        { return TOK_IF; }
"else"      { return TOK_ELSE; }

"+"         { colNo += yyleng; return TOK_PLUS; }
"-"         { colNo += yyleng; return TOK_MINUS; }
"*"         { colNo += yyleng; return TOK_MULTIPLY; }
"/"         { colNo += yyleng; return TOK_DIVIDE; }
"("         { colNo += yyleng; return TOK_LPAREN; }
")"         { colNo += yyleng; return TOK_RPAREN; }

"="         { colNo += yyleng; return TOK_ASSIGN; }
";"         { colNo += yyleng; return TOK_SEMICOLON; }
","         { colNo += yyleng; return TOK_COMMA; }
"&"         { colNo += yyleng; yylval.str_val = strdup(yytext); return TOK_AMPERSAND; }


"{"        { return TOK_LBRACE; }
"}"        { return TOK_RBRACE; }
"=="       { return TOK_EQUAL; }
">"        { return TOK_GREATER; }
"<"        { return TOK_LESS; }
"<="       { return TOK_LESS_EQUAL; }
">="       { return TOK_GREATER_EQUAL; }
"!="       { return TOK_NOT_EQUAL; }

"printf"    { colNo += yyleng; return TOK_PRINT; }
"scanf"     { colNo += yyleng; return TOK_SCANF; }

{INTEGER}   { colNo += yyleng; yylval.int_val = atoi(yytext); return TOK_INT; }
{FLOAT}     { colNo += yyleng; yylval.str_val = strndup(yytext, strlen(yytext) - 1); return TOK_FLOAT; }
{DOUBLE}    { colNo += yyleng; yylval.double_val = atof(yytext); return TOK_DOUBLE; }
{ID}        { colNo += yyleng; yylval.str_val = strdup(yytext); return TOK_ID; }

\"([^"\\]|\\.)*\"   {
                    colNo += yyleng;
                    int len = strlen(yytext); 
                    yylval.str_val = strndup(yytext + 1, len - 2);
                    return TOK_STRING;  //elimin ce era intre "" pentru afisare la consola
                    }

{WHITESPACE}+ { colNo += yyleng; }
\n          { lineNo++; colNo = 1; }
.           { printf("Caracter necunoscut la linia %d, coloana %d: '%s'\n", lineNo, colNo, yytext); colNo += yyleng; }

%%
