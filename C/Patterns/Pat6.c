/*
    A
    A B
    A B C
    A B C D
    A B C D E
*/

#include <stdio.h>

void main()
{
    int n,i,j;
    printf("Enter Limit : ");
    scanf("%d",&n);
    char ch = 'A';

    for ( i=1; i<=n; i++)
    {
        for (j=1; j<=i; j++)  
        {
            printf("%c ",ch);
            ch ++;
        }
        ch = 'A';
        printf("\n");
    }
}