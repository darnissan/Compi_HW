
// my goal - develop lexical analyzer to handle FanC - as subset of C lang.
#include "tokens.hpp"
#include <string>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

string backslashN_handler(string str)
{
}
string backslashR_handler(string str)
{
}
string backslashT_handler(string str)
{
}

string doubleBackslash_handler(string str)
{
}

string backslashQuote_handler(string str)
{
}

string AsciiEscape_handler(string str)
{
}

int main()
{
	int token;
	while ((token = yylex()))
	{
		switch (token)
		{
		case STRING:
		{
			string str_token = yytext;
		}
		break;
		case COMMENT:

		default:
			break;
		}
		// Your code here
	}
	return 0;
}
