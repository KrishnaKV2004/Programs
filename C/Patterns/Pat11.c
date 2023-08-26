/*
    *********
     *********
      *********
       *********
        *********
*/

#include <stdio.h>

void main()
{
    int n,i,j,k;
    printf("Enter Limit : ");
    scanf("%d",&n);

    for (i=1; i<=n; i++)
    {
      for (j=1; j<=i-1; j++)
      {
        printf(" ");
      }
      for (k=1; k<=2*n-1; k++)
      {
        printf("*");
      }
      printf("\n");
    }
}