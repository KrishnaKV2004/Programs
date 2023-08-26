// To Find The Sum Of A Digit

#include <stdio.h>

void main()
{
    int n,d,sum = 0;
    printf("Enter Number : ");
    scanf("%d",&n);

    while (n>0)
    {
        d = n % 10;
        sum = sum + d;
        n = n / 10;
    }
    printf("Sum = %d",sum);
}