%{
/* Declartions Section */
#include <stdio.h>
#include <iostream>
#include "tokens.hpp"
using std::string;
void showToken(string);
%}

%option yylineno
%option noyywrap
digit ([0-9])
letter ([a-zA-Z])
whitespace ([ \t\n])
%%
"void" {showToken("VOID"); return VOID;}
"int" {showToken("INT"); return INT;}
"byte" {showToken("BYTE"); return BYTE;}
"b" {showToken("B"); return B;}
"bool" {showToken("BOOL"); return BOOL;}
"override" {showToken("OVERRIDE"); return OVERRIDE;}
"and" {showToken("AND"); return AND;}
"or" {showToken("OR"); return OR;}
"not" {showToken("NOT"); return NOT;}
"true" {showToken("TRUE"); return TRUE;}
"false" {showToken("FALSE"); return FALSE;}
"return" {showToken("RETURN"); return RETURN;}
"if" {showToken("IF"); return IF;}
"else" {showToken("ELSE"); return ELSE;}
"while" {showToken("WHILE"); return WHILE;}
"break" {showToken("BREAK"); return BREAK;}
"continue" {showToken("CONTINUE"); return CONTINUE;}
";" {showToken("SC"); return SC;}
"," {showToken("COMMA"); return COMMA;}
"(" {showToken("LPAREN"); return LPAREN;}
")" {showToken("RPAREN"); return RPAREN;}
"{" {showToken("LBRACE"); return LBRACE;}
"}" {showToken("RBRACE"); return RBRACE;}
"=" {showToken("ASSIGN"); return ASSIGN;}
"=="|"!="|"<"|">"|"<="|">=" {showToken("RELOP"); return RELOP;}
"+"|"-"|"*"|"/" {showToken("BINOP"); return BINOP;}
"//"[^\n]\r*  { return COMMENT;}
[a-zA-Z]({letter}|{digit})* {showToken("ID"); return ID;}
0|[1-9]{digit}* {showToken("NUM"); return NUM;}
\"(\\\"|[^\"])*\"$  {return STRING;}
\"(\\\"|[^\"])*  {return UNCLOSED;}

[ \t\n\r]+     ;  // ignore whitespace

. { return UNKNOWN;}
%%
// showToken should print in the following foramt <line number> <token name> <value>
// note that line number refers to the line number where the token ENDS not where it starts
// value refers to the lexeme excluding comments and strings
void showToken(string tokenName)
{
    printf("%d %s %s\n", yylineno, tokenName.c_str(), yytext);
}
