#include <stdio.h>

void main()
{
    int n,l,f;
    printf("Enter Number : ");
    scanf("%d",&n);

    l = n%10;
    f = n;

    while (f>0)
    {
        f = f/10;
    }
    int sum = f+l;
    printf("Sum = %d",sum);
}