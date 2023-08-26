/* 
    *
    * *
    * * *
    * * * *
    * * * * *
*/

#include <stdio.h>

void main()
{
    int n,i,k;
    printf("Enter Limit : ");
    scanf("%d",&n);

    for (i=1; i<=n; i++)
    {
        for (k=1; k<=i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}