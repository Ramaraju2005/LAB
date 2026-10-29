
#include <stdio.h>
#include <stdlib.h>

int main() {
    void *p[10] = {NULL};
    int ch, n, id, i;

    do {
        printf("\n1.Allocate 2.Free 3.Display 4.Exit: ");
        scanf("%d", &ch);

        if (ch == 1) {
            for (i = 0; i < 10 && p[i]; i++);
            if (i == 10) continue;

            printf("Enter size: ");
            scanf("%d", &n);

            if (n <= 0) continue;

            p[i] = malloc(n);
            printf("Address = %p\n", p[i]);
        }
        else if (ch == 2) {
            printf("Enter block ID: ");
            scanf("%d", &id);

            if (id >= 1 && id <= 10 && p[id-1]) {
                free(p[id-1]);
                p[id-1] = NULL;
            }
        }
        else if (ch == 3) {
            for (i = 0; i < 10; i++)
                if (p[i])
                    printf("%d: %p\n", i+1, p[i]);
        }
    } while (ch != 4);

    for (i = 0; i < 10; i++)
        free(p[i]);

    return 0;
}
