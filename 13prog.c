%{
#include <stdio.h>
%}

%%
0       { printf("Zero"); }
1       { printf("One"); }
2       { printf("Two"); }
3       { printf("Three"); }
4       { printf("Four"); }
5       { printf("Five"); }
10      { printf("Ten"); }
100     { printf("One Hundred"); }
[0-9]+  { printf("Number between 0 and 100"); }
\n      ;
.       { printf("Invalid"); }
%%

int yywrap() { return 1; }

int main() {
    printf("Enter number: ");
    yylex();
    return 0;
}