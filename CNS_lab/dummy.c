#include<stdio.h.

int main()
{
  char str[100];
  int key,i;

  printf("enetr text");
  scanf("%s",str);
  printf("enter key");

  
  scanf("%d",&key);
  for(i=0;s[i];i++)
  s[i]=(s[i]-'A'+key)%26+'A';

  printf("encrypted ; %s\n",s);

  for(i=0;s[i];i++)
  s[i]=(s[i]-'A'-key+26)%26 +'A';

  printf("decrypted :%s",s);
  return 0;
}