
#include <stdio.h>

char s[50];
int i = 0;

int E();
int T();
int F();

int F() {
    if (s[i] == 'i') i++;
    else if (s[i] == '(') {
        i++;
        if (!E() || s[i++] != ')') return 0;
    }
    else return 0;
    return 1;
}

int T() {
    if (!F()) return 0;
    while (s[i] == '*') {
        i++;
        if (!F()) return 0;
    }
    return 1;
}

int E() {
    if (!T()) return 0;
    while (s[i] == '+') {
        i++;
        if (!T()) return 0;
    }
    return 1;
}

int main() {
    printf("Enter expression ending with $: ");
    scanf("%49s", s);

    if (E() && s[i] == '$')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
