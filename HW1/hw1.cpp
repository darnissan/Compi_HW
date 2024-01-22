#include "tokens.hpp"
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void string_handler(string str);
string trimFirst_N_Last(string str);
void backslashN_handler();
void backslashR_handler();
void backslashT_handler();
void doubleBackslash_handler();
void backslashQuote_handler();
void AsciiEscape_handler(string num);

string trimFirst_N_Last(string str)
{
	if (str.length() > 2)
	{
		return str.substr(1, str.length() - 2);
	}
	else
	{
		return "";
	}
}

void backslashN_handler()
{
	printf("\n");
}

void backslashR_handler()
{
	printf("\r");
}

void backslashT_handler()
{
	printf("\t");
}

void doubleBackslash_handler()
{
	printf("\\");
}

void backslashQuote_handler()
{
	printf("\"");
}

void AsciiEscape_handler(string num)
{
	string hex = num;
	int ascii = strtol(hex.c_str(), NULL, 16);
	if (ascii == 0 && hex != "00")
	{
		printf("Error undefined escape sequence %s\n", hex.c_str());
		exit(0);
	}
	string max_ascii = "0x7F";
	if (ascii > strtol(max_ascii.c_str(), NULL, 16))
	{
		printf("Error undefined escape sequence %s\n", hex.c_str());
		exit(0);
	}
	printf("%c", ascii);
}
void backslashZero_handler()
{
	string str="\0";
	printf("%s",str.c_str());
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
				string_handler(str_token);
				}
				break;
			case COMMENT:
				printf("%d COMMENT //\n", yylineno);
				break;
			//Dealing with illegal chars
			case UNKNOWN:
				printf("Error %c\n",*yytext);
				exit(0);
				break;
			default:
				// Handle other cases or skip
				break;
		}
	}
	return 0;
}

void string_handler(string str)
{
	printf("%d STRING ", yylineno);
	str = trimFirst_N_Last(str);
	int index = 0;
	while (index < str.length())
	{
		if (str[index] == '\\')
		{
			if (index + 1 < str.length())
			{
				switch (str[index + 1])
				{
				case 'n':
					backslashN_handler();
					index += 2;
					break;
				case 'r':
					backslashR_handler();
					index += 2;
					break;
				case 't':
					backslashT_handler();
					index += 2;
					break;
				case '\\':
					doubleBackslash_handler();
					index += 2;
					break;
				case '"':
					backslashQuote_handler();
					index += 2;
					break;
				case 'x':
					if (index + 3 < str.length())
					{
						AsciiEscape_handler(str.substr(index + 2,2));
						index += 4;
					}
					else
					{
						printf("Error undefined escape sequence %c", str[index + 1]);
						if(index+2 < str.length())
							printf("%c", str[index + 2]);
						printf("\n");
						exit(0);
					}
					break;
				case '0':
					backslashZero_handler();
					index += 2;
					break;
				default:

					printf("Error undefined escape sequence %c\n", str[index + 1]);
					exit(0);
				}
			}
			else if (str[index] == '\n')
			{
				printf("Error unclosed string\\n\n");
				exit(0);
			}
			else
			{
				// If '\' is the last character,it's an error, exit the program
				printf("Error unclosed string\n");
				exit(0);
			}
		}
		else
		{
			// Print characters other than backslash as they are
			printf("%c", str[index]);
			index++;
		}
	}
	printf("\n");
}
