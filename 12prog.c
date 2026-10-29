%{
#include <stdio.h>
#include <stdlib.h>

void days(int m) {
    if (m == 2)
        printf("28 or 29 days\n");
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        printf("30 days\n");
    else if (m >= 1 && m <= 12)
        printf("31 days\n");
    else
        printf("Invalid month\n");
}
%}

%%
[0-9]+    { days(atoi(yytext)); }
\n        ;
.         { printf("Invalid input\n"); }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}