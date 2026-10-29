#include <stdio.h>

int main() {
    int n, i, size[10], addr = 1000;
    char name[10][20];

    printf("Enter number of variables: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter name and size: ");
        scanf("%19s%d", name[i], &size[i]);
    }

    printf("\nName\tSize\tAddress\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\n", name[i], size[i], addr);
        addr += size[i];
    }

    return 0;
}
