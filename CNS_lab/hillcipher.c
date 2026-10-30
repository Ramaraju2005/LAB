
#include <stdio.h>
#include <string.h>

int mod(int x) {
    return (x % 26 + 26) % 26;
}

int main() {
    int k[2][2], det, d = -1;
    char s[100], c[100], p[100];
    int a, b, n;

    printf("Enter key matrix: ");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&k[i][j]);

    printf("Enter text: ");
    scanf("%s",s);

    n = strlen(s);

    if(n%2) {
        printf("Enter even length text");
        return 0;
    }

    det = mod(k[0][0]*k[1][1]-k[0][1]*k[1][0]);

    for(int i=1;i<26;i++)
        if(mod(det*i)==1) d=i;

    if(d==-1) {
        printf("Invalid key");
        return 0;
    }

    for(int i=0;i<n;i+=2) {
        a=s[i]-'A'; b=s[i+1]-'A';

        c[i]=mod(k[0][0]*a+k[0][1]*b)+'A';
        c[i+1]=mod(k[1][0]*a+k[1][1]*b)+'A';
    }
    c[n]='\0';

    for(int i=0;i<n;i+=2) {
        a=c[i]-'A'; b=c[i+1]-'A';

        p[i]=mod(d*(k[1][1]*a-k[0][1]*b))+'A';
        p[i+1]=mod(d*(-k[1][0]*a+k[0][0]*b))+'A';
    }
    p[n]='\0';

    printf("Encrypted: %s\n",c);
    printf("Decrypted: %s\n",p);

    return 0;
}


// sample output:
// Enter 2x2 key matrix:
// 3 3
// 2 5
// Enter plaintext (even number of letters): HELP

// Encrypted Text: HIAT
// Decrypted Text: HELP