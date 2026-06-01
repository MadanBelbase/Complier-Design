// # 1 write a program to find the whether given input is  const or not. i e enclosed within ""

#include <stdio.h>
#include <string.h>

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    if (input[0] == '"' && input[strlen(input) - 1] == '"') {
        printf("The input is a constant string.\n");
    } else {
        printf("The input is not a constant string.\n");
    }

    return 0;
}


