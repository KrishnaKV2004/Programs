/*
    Write a user defined function to print
    Fibonacci series.
*/

#include <stdio.h>

void fib(int);

void main()
{
    int n;
    printf("Enter Number of Terms : ");
    scanf("%d",&n);

    fib(n);
}

void fib(int n)
{
    int a=0, b=1, c=0;
    printf("%d\n",a);
    printf("%d\n",b);
    for (int i=1; i<=n-2; i++)
    {
        c = a+b;
        printf("%d\n",c);
        a = b;
        b = c;
    }
}