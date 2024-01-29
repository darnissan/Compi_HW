#include "tokens.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#define UNCLOSED 29
#define BAD_ESCAPE 30
#define INVALID_HEX 31
#define UNKNOWN 32
using namespace std;

string trimFirst_N_Last(const string &str);
void handleAsciiEscape(const string &num, string &result);

string trimFirst_N_Last(const string &str)
{
	if (str.length() > 2)
	{
		return str.substr(1, str.length() - 2);
	}
	return "";
}

void handleAsciiEscape(const string &num, string &result)
{
	/*
	long ascii = strtol(num.c_str(), nullptr, 16);
	long min_range_print=strtol("20", nullptr, 16);
	long max_range_print=strtol("7E", nullptr, 16);
	long special_print1=strtol("09", nullptr, 16);
	long special_print2=strtol("0A", nullptr, 16);
	long special_print3=strtol("0D", nullptr, 16);
	if (!((ascii >=  min_range_print && ascii <= max_range_print) || ascii == special_print1 || ascii == special_print2 ||  ascii == special_print3))
	{
		cout << "Error undefined escape sequence x" << num << endl;
		exit(0);
	}
	result += static_cast<char>(ascii);*/
	long ascii = strtol(num.c_str(), nullptr, 16);
	if ((ascii == 0 && num != "00") || ascii >= 0x7F || (ascii < 0x20 && ascii != 0x09 && ascii != 0x0A && ascii != 0x0D))
	{
		cout << "Error undefined escape sequence x" << num << endl;
		exit(0);
	}
	result += static_cast<char>(ascii);
}

void string_handler(const string &str)
{
	string to_print = to_string(yylineno) + " STRING ";
	string trimmed = trimFirst_N_Last(str);
	size_t index = 0;
	size_t length = trimmed.length();
	while (index < length)
	{
		if (trimmed[index] == '\\')
		{
			if (index + 1 < length)
			{
				switch (trimmed[index + 1])
				{
				case 'n':
					to_print += "\n";
					break;
				case 'r':
					to_print += "\r";
					break;
				case 't':
					to_print += "\t";
					break;
				case '\\':
					to_print += "\\";
					break;
				case '"':
					to_print += "\"";
					break;
				case 'x':
					if (index + 3 < length)
					{
						handleAsciiEscape(trimmed.substr(index + 2, 2), to_print);
						index += 2; // Skip the x and two hex digits
					}
					else
					{
						cout << "Error undefined escape sequence " << trimmed[index + 1];
						if (index + 2 < length)
							cout << trimmed[index + 2];
						cout << endl;
						exit(0);
					}
					break;
				case '0':
					// finish the string reading
					index = length;
					break;
				default:
					cout << "Error undefined escape sequence " << trimmed[index + 1] << endl;
					exit(0);
				}
				index += 2;
			}
			else
			{
				cout << "Error unclosed string" << endl;
				exit(0);
			}
		}
		else if (trimmed[index] == '\n')
		{

			cout << "Error unclosed string" << endl;
			exit(0);
		}
		else if (trimmed[index] == '\r')
		{

			cout << "Error unclosed string" << endl;
			exit(0);
		}
		else
		{
			to_print += trimmed[index++];
		}
	}
	cout << to_print << endl;
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
			break;
		}
		case COMMENT:
			cout << yylineno << " COMMENT //" << endl;
			break;
		case BAD_ESCAPE:
			cout << "Error undefined escape sequence " << yytext[yyleng - 1] << endl;
			break;
		case UNCLOSED:
			cout << "Error unclosed string" << endl;
			exit(0);
			break;
		case INVALID_HEX:
			if (yytext[yyleng - 3] == 'x')
				cout << "Error undefined escape sequence x" << yytext[yyleng - 2] << yytext[yyleng - 1] << endl;
			else
				cout << "Error undefined escape sequence x" << yytext[yyleng - 1] << endl;
			exit(0);
			break;
		case UNKNOWN:
			// Handle error
			cout << "Error " << *yytext << endl;
			exit(0);
			break;

		default:
			// Do nothing
			break;
		}
	}
	return 0;
}
