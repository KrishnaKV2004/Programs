// To Print The Sum Of Series --> 1 + 2^2 + 3^3 + ......... + n^n

#include <stdio.h>
#include <math.h>

void main()
{
    int n;
    int sum=0;

    printf("Enter n : ");
    scanf("%d",&n);

    for (int i=1; i<=n; i++)
    {
        sum = sum+(pow(i,i));
    }
    printf("Sum = %d",sum);
}