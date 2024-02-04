#include <iostream>
#include "output.hpp"
extern int yyparse();

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (!yyin)
        {
            std::cerr << "Failed to open " << argv[1] << std::endl;
            return 1;
        }
    }
    yyparse();
    fclose(yyin);
    return 0;
}
