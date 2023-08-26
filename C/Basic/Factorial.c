#include <stdio.h>

int fact(int);

void main()
{
    int n;
    printf("Enter A Number : ");
    scanf("%d",&n);
    int fac = fact(n);
    printf("%d",fac);
}

int fact(int n)
{
    if (n==0)
    {
        return 1;
    }
    int fac_nm1 = fact(n-1);
    int fac = fac_nm1 * n;
    return fac;
}
