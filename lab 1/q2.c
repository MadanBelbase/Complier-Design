#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int len;

    printf("Enter a string: ");
    scanf("%99[^\n]", input);

    len = strlen(input);

    if (input[0] == '/' && input[1] == '/') {
        printf("Single-line comment\n");
    }

    else if (input[0] == '/' && input[1] == '*' &&
             input[len - 2] == '*' && input[len - 1] == '/') {
        printf("Multi-line comment\n");
    }

    else {
        printf("Not a comment\n");
    }

    return 0;
}