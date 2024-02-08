%{
/* Declartions Section */
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "source.tab.hpp"
#include "tokens.hpp"
using std::string;
void (string);

%}

%option yylineno
%option noyywrap
digit ([0-9])
letter ([a-zA-Z])
whitespace ([ \t\n\r])
%%
"void" { yylval= ;return VOID;}
"int" { return INT;}
"byte" { return BYTE;}
"b" { return B;}
"bool" { return BOOL;}
"and" { return AND;}
"or" { return OR;}
"not" { return NOT;}
"true" {return TRUE;}
"false" { return FALSE;}
"return" { return RETURN;}
"if" { return IF;}
"else" { return ELSE;}
"while" {return WHILE;}
"break" { return BREAK;}
"continue" { return CONTINUE;}
";" { return SC;}
"(" { return LPAREN;}
")" { return RPAREN;}
"{" { return LBRACE;}
"}" { return RBRACE;}
"=" {return ASSIGN;}
"++|--" {return DOUBLEOP;}
"=="|"!="|"<"|">"|"<="|">=" { return RELOP;}
"+"|"-"|"*"|"/" { return BINOP;}
[a-zA-Z][a-zA-Z0-9]*  { return ID;}
0|[1-9][0-9]* { return NUM;}
\"([^\n\r\"\\]|\\[rnt"\\])+\" { return STRING;}
"(int)" | "(void)" | "(bool)" | "(byte) {return CAST}
{whitespace}+     ;  // ignore whitespace

. {return UNKNOWN;};
%%
//validhex ((\x0[9AD])| \x[2-6][0-9A-Fa-f] | x[7][0-9A-Ea-e])
//  should print in the following foramt <line number> <token name> <value>
// note that line number refers to the line number where the token ENDS not where it starts
// value refers to the lexeme excluding comments and strings
void (string tokenName)
{
    printf("%d %s %s\n", yylineno, tokenName.c_str(), yytext);
}
