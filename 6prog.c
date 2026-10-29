#include <stdio.h>
#include <stdlib.h>

char s[50];
int i = 0;

void S(); void L(); void Ld();

void err() {
    printf("Rejected\n");
    exit(0);
}

void S() {
    if (s[i] == 'a') {
        i++;
    } else if (s[i] == '(') {
        i++;
        L();
        if (s[i] == ')') i++;
        else err();
    } else err();
}

void L() {
    S();
    Ld();
}

void Ld() {
    if (s[i] == ',') {
        i++;
        S();
        Ld();
    }
}

int main() {
    printf("Enter string (e.g., (a,a)$ or a$): ");
    scanf("%s", s);
    S();
    if (s[i] == '$')
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;
}