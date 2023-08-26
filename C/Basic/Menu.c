/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Write a menu driven program using functions that can
    perform following tasks on pressing given keys.
    1 --> Check whether number is odd or even
    3 --> Print reverse of a number
    4 --> Print sum of series 1 + 3 + 5 ... upto n
    5 --> Exit

*/

#include <stdio.h>

void oe(int);
void rev(int);
void sum(int);

void main()
{
    int n, ch ;
    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Enter N : ");
    scanf("%d",&n);
    printf("\n1 --> Check whether number is odd or even\n");
    printf("3 --> Print reverse of a number\n");
    printf("4 --> Print sum of series 1 + 3 + 5 ... upto n\n");
    printf("5 --> Exit\n");
    printf("\nEnter Choice : ");
    scanf("%d",&ch);
    printf("\t\t\t ***** OUTPUT *****\n\n");

    switch (ch)
    {
    case 1:
        oe(n);
        break;

    case 3:
        rev(n);
        break;

    case 4:
        sum(n);
        break;

    case 5:
        break;
    
    default:
        printf("Invalid Input !");
        break;
    }
}

void oe(int n)
{
    if (n%2==0)
    {
        printf("Even");
    } else
    {
        printf("Odd");
    }
}

void rev(int n)
{
    int a,b=0;
        while(n>0)
        {
            a=n%10;
            b=b*10+a;
            n=n/10;
        }
        printf("Reversed Number --> %d",b);
}

void sum(int n)
{
    int sum = 0;
        for (int i=1; i<=n; i=i+2)
        {
            sum = sum + i;
        }
        printf("Sum = %d",sum);
}