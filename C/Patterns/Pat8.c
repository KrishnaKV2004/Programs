/*
            A
          B C D
        E F G H I 
      J K L M N O P
    Q R S T U V W X Y
*/

#include <stdio.h>

void main()
{
  int n,i,j,k;
  char ch ='A';
  printf("Enter Limit : ");
  scanf("%d",&n);

  for (i=1; i<=n; i++)
  {
    for (j=1; j<=n-i; j++)
    {
      printf("  ");
    }
    for (k=1; k<=2*i-1; k++)
    {
      printf("%c ",ch);
      ch ++;
    }
    printf("\n");
  }
}