#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    printf("Program to Count Characters, Words, and Lines in a Text File\n");

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;
        if (ch == '\n')
        {
            lines++;
        }
        if (isspace(ch))
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            inWord = 1;
            words++;
        }
    }
    fclose(fp);
    if (characters > 0)
    {
        lines++;
    }
    printf("\nNumber of Characters = %d", characters);
    printf("\nNumber of Words      = %d", words);
    printf("\nNumber of Lines      = %d\n", lines);

    return 0;
}