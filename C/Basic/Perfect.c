/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Write a program to print following pattern ;
*/

#include <stdio.h>

void main()
{
    int n;
    int sum=0;

    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Enter Number : ");
    scanf("%d",&n);
    printf("\t\t\t ***** OUTPUT *****\n\n");
    printf("Factors -->\n");

    for (int i=1; i<=n; i++)
    {
        if(n%i==0)
        {
            printf("%d ",i);
            sum = (sum + i);
        }
    }
    if ((sum-n)==n)
    {
        printf("\nPerfect Number\n");
    } else
    {
        printf("\nNot A Perfect Number\n");
    }
}