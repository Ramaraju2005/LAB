#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[30];
    char *kw[] = {"if", "else", "while", "for",
                  "do", "switch", "case", "break",
                  "continue", "return"};
    int i, found = 0;

    printf("Enter a word: ");
    scanf("%29s", s);

    for (i = 0; i < 10; i++)
        if (strcmp(s, kw[i]) == 0)
            found = 1;

    if (found)
        printf("Keyword");
    else if (isalpha(s[0]) || s[0] == '_')
        printf("Identifier");
    else
        printf("Invalid");

    return 0;
}