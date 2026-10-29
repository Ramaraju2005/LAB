
#include <stdio.h>

int top = -1, sp = 5000, addr[10], size[10];
char name[10][20];

int main() {
    int ch, n;

    do {
        printf("\n1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &ch);

        if (ch == 1 && top < 9) {
            printf("Enter name and size: ");
            scanf("%19s%d", name[top + 1], &n);

            if (n <= 0) continue;

            top++;
            addr[top] = sp;
            size[top] = n;
            sp += n;
        }
        else if (ch == 2 && top >= 0) {
            sp = addr[top];
            top--;
        }
        else if (ch == 3) {
            for (int i = top; i >= 0; i--)
                printf("%s %d %d\n",
                       name[i], size[i], addr[i]);
            printf("SP = %d\n", sp);
        }
    } while (ch != 4);

    return 0;
}
