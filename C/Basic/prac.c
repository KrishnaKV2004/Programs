/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Write a recursive code to print GCD of 2 numbers.
*/

#include <stdio.h>

int gcd(int a, int b);

void main()
{
    int num1, num2, hcf;
    printf("\t\t\t***** INPUT *****\n\n");
    printf("Enter Two Numbers : \n");
    scanf("%d%d", &num1, &num2);

    hcf = gcd(num1, num2);

    printf("\t\t\t***** OUTPUT *****\n\n");
    printf("GCD = %d", num1, num2, hcf);
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b); 
}