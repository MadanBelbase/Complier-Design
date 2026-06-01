// write a c program to recognize strings under a^* ,a^*b+,abb

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, len;
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    if (strcmp(str, "abb") == 0)
    {
        printf("\nResult: The string \"%s\" belongs to the language abb.\n", str);
        return 0;
    }
    int onlyA = 1;
    for (i = 0; i < len; i++)
    {
        if (str[i] != 'a')
        {
            onlyA = 0;
            break;
        }
    }
    if (onlyA)
    {
        printf("\nResult: The string \"%s\" belongs to the language a*.\n", str);
        return 0;
    }
    i = 0;
    while (i < len && str[i] == 'a')
        i++;
    int bCount = 0;
    while (i < len && str[i] == 'b')
    {
        bCount++;
        i++;
    }
    if (bCount > 0 && i == len)
    {
        printf("\nResult: The string \"%s\" belongs to the language a*b+.\n", str);
    }
    else
    {
        printf("\nResult: The string \"%s\" does NOT belong to any of the given languages.\n", str);
    }

    return 0;
}
