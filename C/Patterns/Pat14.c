/*
     * * * * *
      * * * *
       * * *
        * *
         *
         *
        * *
       * * *
      * * * *
     * * * * *
*/

#include <stdio.h>

void main()
{
    int n;
    int i1,i2,j1,j2,k1,k2;
    printf("Enter Limit [Even] : ");
    scanf("%d",&n);
    printf("\n");

    if (n%2==0)
    {
            // For Upper Pattern -->

    for (i1=1; i1<=n/2; i1++)
    {
      for (j1=1; j1<=i1-1; j1++)
      {
        printf("  ");
      }
      for (k1=1; k1<=(2*n/2)-(2*i1-1); k1++)
      {
        printf("* ");
      }
      printf("\n");
    }

            // For Lower Pattern -->

    for (i2=1; i2<=n/2; i2++)
    {
        for (j2=1; j2<=n/2-i2; j2++)
        {
            printf("  ");
        }
        for (k2=1; k2<=(2*i2-1); k2++)
        {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
    }
    else
    {
        printf("Invalid Input : Limit Should Be Even !");
    }
}