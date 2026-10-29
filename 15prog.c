
%{
#include <stdio.h>
%}

%%
"if"|"else"|"for"|"while"|"do"|"switch"|"case"|"break"|"continue"|"return"
    { printf("%s : Keyword\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*
    { printf("%s : Identifier\n", yytext); }
[ \t\n]+ ;
.       { printf("%s : Symbol\n", yytext); }
%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}
