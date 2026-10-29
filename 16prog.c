
%{
#include <stdio.h>
#include <stdlib.h>

char *one[] = {"Zero","One","Two","Three","Four","Five",
"Six","Seven","Eight","Nine","Ten","Eleven","Twelve",
"Thirteen","Fourteen","Fifteen","Sixteen","Seventeen",
"Eighteen","Nineteen"};

char *ten[] = {"","","Twenty","Thirty","Forty","Fifty",
"Sixty","Seventy","Eighty","Ninety"};

void words(int n) {
    if (n < 20)
        printf("%s", one[n]);
    else if (n < 100) {
        printf("%s", ten[n/10]);
        if (n%10) { printf(" "); words(n%10); }
    }
    else if (n < 1000) {
        printf("%s Hundred", one[n/100]);
        if (n%100) { printf(" "); words(n%100); }
    }
    else if (n == 1000)
        printf("One Thousand");
}
%}

%%
[0-9]+ {
    int n = atoi(yytext);
    if (n <= 1000) {
        words(n);
        printf("\n");
    } else printf("Out of range\n");
}
[ \t\n]+ ;
. { printf("Invalid input\n"); }
%%

int yywrap() { return 1; }

int main() {
    printf("Enter number (0-1000): ");
    yylex();
    return 0;
}
