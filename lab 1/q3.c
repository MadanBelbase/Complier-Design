// 3 wap to split string
//  int main() { char a ; printf("good morning"); a = "A";
//  printf("%c", a); return 0 ; }  into a tokens 
// int , main, char ,print = keywor
// a  = identifer
// "goodemorning" = constant
// = - operator


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *word) {
    char keywords[][10] = {"int", "char", "return", "float", "void"};

    for (int i = 0; i < 5; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char str[200];
    char token[50];
    int j = 0;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {

        if (isalnum(str[i])) {
            token[j++] = str[i];
        }

        else {
            if (j != 0) {
                token[j] = '\0';

                if (isKeyword(token))
                    printf("%s = keyword\n", token);
                else
                    printf("%s = identifier\n", token);

                j = 0;
            }

            if (str[i] == '=' || str[i] == '+' || str[i] == '-' ||
                str[i] == '(' || str[i] == ')' || str[i] == '{' ||
                str[i] == '}' || str[i] == ';') {
                printf("%c = operator\n", str[i]);
            }

            if (str[i] == '"') {
                printf("\"string constant\"\n");
            }
        }
    }

    return 0;
}
