#include<stdio.h>

int main()
{
     char st[]="hello world";
     char *ptr=st;

     while(*ptr !='\0')
     {
        char  ch=*ptr ^ 0;
        printf("%c",ch);
        ptr++;
     }

     return 0;
}

// #include <stdio.h>

// int main() {
//     char str[] = "Hello world";
//     char *ptr = str;

//     printf("Original String: %s\n", ptr);
//     printf("Result after XOR with 0: ");

//     while (*ptr != '\0') {
//         char ch = *ptr ^ 0;
//         printf("%c", ch);
//         ptr++;
//     }
//     printf("\n");

//     return 0;
// }