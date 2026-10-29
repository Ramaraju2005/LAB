#include <stdio.h>
#include <string.h>

int A[12][6]={
{5,0,0,4,0,0},{0,6,0,0,0,999},
{0,-2,7,0,-2,-2},{0,-4,-4,0,-4,-4},
{5,0,0,4,0,0},{0,-6,-6,0,-6,-6},
{5,0,0,4,0,0},{5,0,0,4,0,0},
{0,6,0,0,11,0},{0,-1,7,0,-1,-1},
{0,-3,-3,0,-3,-3},{0,-5,-5,0,-5,-5}};

int G[12][3]={
{1,2,3},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},
{8,2,3},{-1,-1,-1},{-1,9,3},{-1,-1,10},
{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};

int len[]={3,1,3,1,3,1};
int lhs[]={0,0,1,1,2,2};
char *tok[]={"id","+","*","(",")","$"};

int main(){
    char s[100],t[20];
    int st[100],top=0,p=0,n,a,v,r;
    st[0]=0;

    printf("Enter tokens: ");
    fgets(s,100,stdin);

    while(sscanf(s+p,"%19s%n",t,&n)==1){
        p+=n;
        for(a=0;a<6 && strcmp(t,tok[a]);a++);
        if(a==6){puts("Rejected");return 0;}

        while(1){
            v=A[st[top]][a];

            if(v==999){puts("Accepted");return 0;}
            if(v>0){st[++top]=v;break;}
            if(v==0){puts("Rejected");return 0;}

            r=-v-1;
            top-=len[r];
            st[++top]=G[st[top-1]][lhs[r]];

            if(st[top]<0){puts("Rejected");return 0;}
        }
    }
    puts("Rejected");
    return 0;
}