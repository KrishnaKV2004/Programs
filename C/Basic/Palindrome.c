// To Check Whether A Number Is Palindrome

#include <stdio.h>

void main()
{
    int n, z, sum=0;
    printf("Enter Number : ");
    scanf("%d",&n);
    z = n;

    while (n>0)
    {
        int a = n%10;
        sum = sum*10+a;
        n = n/10;
    }
    if (sum==z)
    {
        printf("Number Is Palindrome");
    } else
    {
        printf("Not A Palindrome Number");
    }
}