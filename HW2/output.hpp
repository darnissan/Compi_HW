#ifndef _236360_1_
#define _236360_1_

#include <string>
namespace output
{
    extern const std::string rules[];
    void printProductionRule(const int ruleno);
    void errorLex(const int lineno);
    void errorSyn(const int lineno);
}

enum class TOKENS
{
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
    ADDITION_SUBTRACTION,
    MULTIPLICATION_DIVISION,
    ID,
    NUM,
    STRING,
    EQ_NEQ
};

#endif
