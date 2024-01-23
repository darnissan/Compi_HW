# Makefile

# Target executable name
TARGET = hw1.out

# Source files
LEX_FILE = scanner.lex
CPP_FILE = hw1.cpp

# Generated file from Flex
LEX_C_FILE = lex.yy.c

# Command to compile the C++ code
CXX = g++

# C++ standard
CXXFLAGS = -std=c++17

# Rule to build the final executable
$(TARGET): $(LEX_C_FILE) $(CPP_FILE)
	$(CXX) $(CXXFLAGS) $(LEX_C_FILE) $(CPP_FILE) -o $(TARGET)

# Rule to run Flex
$(LEX_C_FILE): $(LEX_FILE)
	flex $(LEX_FILE)

# Rule to execute the program with input and output redirection
# Rule to execute the program with input and output redirection
run: $(TARGET)
	./$(TARGET) < my_t3.in > my_t3.out 


# Phony targets
.PHONY: clean run

# Rule to clean the generated files
clean:
	rm -f $(LEX_C_FILE) $(TARGET) my_t3.out
