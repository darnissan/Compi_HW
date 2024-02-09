#ifndef _236360_1_
#define _236360_1_

#include <string>
#include <vector>

namespace output
{
    extern const std::string rules[];
    void printProductionRule(const int ruleno);
    void errorLex(const int lineno);
    void errorSyn(const int lineno);
}

enum class TOKENS
{
    VOID,
    INT,
    BYTE,
    B,
    BOOL,
    AND,
    OR,
    NOT,
    TRUE,
    FALSE,
    RETURN,
    IF,
    ELSE,
    WHILE,
    BREAK,
    CONTINUE,
    SC,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    ASSIGN,
    RELOP,
    BINOP,
    ID,
    NUM,
    STRING,
    COMMENT,
    DOUBLEO,
    CAST
};

#endif
