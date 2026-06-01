// write a program to count the number of lines, comments in a given a program

#include <stdio.h>

int main() {
    FILE *fp;
    char ch, prev;
    int lines = 0, comments = 0;
    int inSingleLineComment = 0;
    int inMultiLineComment = 0;

    printf("Program to count lines and comments in a file\n");

    fp = fopen("input.c", "r");

    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    prev = fgetc(fp);

    while ((ch = fgetc(fp)) != EOF) {

        if (ch == '\n') {
            lines++;
        }

        if (!inMultiLineComment && prev == '/' && ch == '/') {
            inSingleLineComment = 1;
            comments++;
        }

        if (!inSingleLineComment && prev == '/' && ch == '*') {
            inMultiLineComment = 1;
            comments++;
        }

        if (inMultiLineComment && prev == '*' && ch == '/') {
            inMultiLineComment = 0;
        }

        if (inSingleLineComment && ch == '\n') {
            inSingleLineComment = 0;
        }

        prev = ch;
    }

    fclose(fp);

    if (lines > 0) {
        lines++;
    }

    printf("\nNumber of Lines    = %d", lines);
    printf("\nNumber of Comments = %d\n", comments);

    return 0;
}