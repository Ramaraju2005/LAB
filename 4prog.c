
#include <stdio.h>

int A[6][3]={{103,-3,-3},{0,0,999},{0,105,-5},
             {0,-2,-2},{0,0,-1},{0,0,-4}};
int G[6][3]={{1,2,-1},{-1,-1,-1},{-1,-1,4},
             {-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
int L[]={0,2,1,0,1,0}, P[]={0,0,1,1,2,2};

int col(char c) {
    if(c=='a') return 0;
    if(c=='b') return 1;
    if(c=='$') return 2;
    return -1;
}

int main() {
    char s[50];
    int st[50], t=0, i=0;
    st[0]=0;
    printf("Enter string ending with $: ");
    scanf("%49s",s);

    while(1) {
        int c=col(s[i]);
        if(c<0) break;
        int x=A[st[t]][c];

        if(x>100 && x!=999) st[++t]=x-100, i++;
        else if(x<0) {
            int r=-x;
            t-=L[r];
            st[++t]=G[st[t-1]][P[r]];
        }
        else if(x==999) { printf("Accepted\n"); return 0; }
        else break;
    }
    printf("Rejected\n");
    return 0;
}
