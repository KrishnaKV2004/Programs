/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section J [G1]

    Write a program to print all the prime numbers
    between the range m and n. 
*/

#include <stdio.h>

void main()
{
    int m,n;
    int i,c,d=0;

    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Enter m : ");
    scanf("%d",&m);
    printf("Enter n : ");
    scanf("%d",&n);
    printf("\t\t\t ***** OUTPUT *****\n\n");

    for (i=m; i<=n; i++)
    {
        for (c=1; c<=i; c++)
        {
            if (i%c==0)
            {
                d=d+1;
            }
        }
        if (d==2)
        {
            printf("%d\n",i);
        }
        d=0;
    }
}