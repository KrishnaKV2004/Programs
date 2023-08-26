/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Write a program to find sum of following series :
    1 + 1/3! + 1/5! + 1/7! . . . . . 1/n!
*/

#include <stdio.h>

float fact(int);

void main()
{
    int n;
    float sum = 0;

    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Enter Limit : ");
    scanf("%d",&n);
    printf("\n\t\t\t ***** OUTPUT *****\n\n");

    for (int i=1; i<=2*n-1; i=i+2)
    {
        sum = sum + (1/fact(i));
    }
    printf("Sum = %f",sum);
    
}

float fact(int n)
{
    float fact=1;

    for (int i=1; i<=n; i++)
    {
        fact = fact * i;
    }
    return fact;
}