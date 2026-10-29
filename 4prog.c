
#include <stdio.h>
#include <string.h>

char input[20];
int pos = 0;

int S();
int A();
int B();

int A() {
    if (input[pos] == 'a') {
        pos++;
        return 1;
    }
    return 1;  // A -> epsilon
}

int B() {
    if (input[pos] == 'b') {
        pos++;
        return 1;
    }
    return 1;  // B -> epsilon
}

int S() {
    return A() && B();
}

int main() {
    printf("Enter string: ");
    scanf("%19s", input);

    if (S() && input[pos] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
