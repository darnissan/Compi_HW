%{

#include "parser.tab.hpp"
#include "output.hpp"
%}

%option yylineno
%option noyywrap
digit ([0-9])
letter ([a-zA-Z])
whitespace ([ \t\n\r])
%%

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
">"|"<"|"<="|">=" { return RELOP;}
"=="|"!=" { return EQ_NEQ;}
"*"|"/" { return MULTIPLICATION_DIVISION;}
"-"|"+" {return ADDITION_SUBSTRACTION;}
[a-zA-Z][a-zA-Z0-9]*  { return ID;}
0|[1-9][0-9]* { return NUM;}
\"([^\n\r\"\\]|\\[rnt"\\])+\" { return STRING;}
\/\/[^\r\n]*[\r|\n|\r\n]? 
{whitespace}+     ;  // ignore whitespace
. {output::errorLex(yylineno);
exit (1);};
%%

