#include <stdio.h>
#include <string.h>

char s[50], st[50];
int top = -1, i = 0;

char* rule(char X, char a) {
    if (X=='E' && (a=='i'||a=='(')) return "TQ";
    if (X=='Q' && a=='+') return "+TQ";
    if (X=='Q' && (a==')'||a=='$')) return "e";
    if (X=='T' && (a=='i'||a=='(')) return "FR";
    if (X=='R' && a=='*') return "*FR";
    if (X=='R' && (a=='+'||a==')'||a=='$')) return "e";
    if (X=='F' && a=='i') return "i";
    if (X=='F' && a=='(') return "(E)";
    return "ERR";
}

int main() {
    scanf("%49s", s);
    strcat(s, "$");

    st[++top]='$';
    st[++top]='E';

    while (top >= 0) {
        char X = st[top], a = s[i];

        if (X=='$' && a=='$') {
            printf("Accepted");
            return 0;
        }
        if (X==a && strchr("i()+*$", a)) {
            top--;
            i++;
        }
        else if (strchr("EQTRF", X)) {
            char *r = rule(X, a);
            if (!strcmp(r, "ERR")) break;

            top--;
            if (strcmp(r, "e"))
                for (int k=strlen(r)-1; k>=0; k--)
                    st[++top]=r[k];
        }
        else break;
    }

    printf("Rejected");
    return 0;
}