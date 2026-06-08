// write a c program to implement DFAs that recognizes identifier ,constant and operators.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Rule to design the DFA for identifiers, constants, and operators
// Identifiers: Start with a letter or underscore, followed by letters, digits, or underscores
// Constants: A sequence of digits (integer constants) or a sequence of digits followed by a dot and more digits (floating-point constants)
// Operators: +, -, *, /, =, etc.

int isIdentifier(const char *str){
    if (strlen(str) == 0) return 0; 

    if (!isalpha(str[0]) && str[0] != '_') return 0;

    // Check the rest of the characters also called as transition states
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') return 0;
    }
    return 1;
}

int isConstant(const char *str) {
    int hasDecimalPoint = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (hasDecimalPoint) return 0; // More than one decimal point
            hasDecimalPoint = 1;
        } else if (!isdigit(str[i])) {
            return 0; // Not a digit
        }
    }
    return strlen(str) > 0; // Ensure it's not an empty string
}
bool isOperator(char *str) {
    const char *operators[] = {"+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||"};
    int numOps = sizeof(operators) / sizeof(operators[0]);

    for (int i = 0; i < numOps; i++) {
        if (strcmp(str, operators[i]) == 0) 
            return true;
    }
    return false;
}

int main() {
    char input[100];

    printf("Enter a string to check if it's an identifier, constant, or operator.\n");

    while (true) {
        printf("Enter input (type 'exit' to quit): ");
        scanf("%99s", input);

        if (strcmp(input, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        }

        if (isIdentifier(input)) {
            printf("'%s' is an Identifier.\n", input);
        }
        else if (isConstant(input)) {
            printf("'%s' is a Constant.\n", input);
        }
        else if (isOperator(input)) {
            printf("'%s' is an Operator.\n", input);
        }
        else {
            printf("'%s' is not recognized as an Identifier, Constant, or Operator.\n", input);
        }
    }

    return 0;
}