// #include<stdio.h>

// int main()
// {

//     char str[]="Hello World";
//     int i;

//     for(i=0;str[i]!='\0';i++)
//     {
//         printf("%c",str[i]&127);
//     }
//     printf("\n");
//     for(i=0;str[i]!='\0';i++)
//     {
//         printf("%c",str[i]^127);
//     }
// return 0;
// }


#include <stdio.h>

int main() {
    char *str = "Hello world";
    int i;

    printf("Original String: %s\n", str);

    printf("After AND with 127: ");
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i] & 127);
    }

    printf("\n");

    printf("After XOR with 127: ");
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i] ^ 127);
    }

    printf("\n");

    return 0;
}
