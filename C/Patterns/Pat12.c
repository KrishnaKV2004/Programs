/*
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
*/

#include <stdio.h>
#include <conio.h>

void main()
{
    int n,i,j;
    int k=1;
    printf("Enter Limit : ");
    scanf("%d",&n);

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=i; j++)
        {
            printf("%d ",k);
            k ++;
        }
        k =1;
        printf("\n");
    }
}