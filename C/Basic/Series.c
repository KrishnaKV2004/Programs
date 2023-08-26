/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section J [G1]

    Write a program to print following series : 0 3 8 15 24 35 48 . . .
    upto n terms.
*/

#include <stdio.h>

void main()
{
    int n;
    int j=1,sum=0;

    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Number Of Terms : ");
    scanf("%d",&n);
    printf("\t\t\t ***** OUTPUT *****\n\n");

    for (int i=1; i<=n; i++)
    {
        printf("%d ",sum);
        j = j+2;
        sum = sum+j;
    }
}