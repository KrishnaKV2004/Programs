/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Write a program to calculate the sum of numbers
    from 1 to n using recursion.
*/

#include <stdio.h>

int sum(int);

int main()
{
    int n;
    printf("\t\t\t***** INPUT *****\n\n");
    printf("Enter A Number : ");
    scanf("%d", &n);

    printf("\t\t\t***** OUTPUT *****\n\n");
    printf("Sum Of Numbers From 1 To %d Is --> %d\n", n, sum(n));
    return 0;
}

int sum(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return n + sum(n-1);
    }
}