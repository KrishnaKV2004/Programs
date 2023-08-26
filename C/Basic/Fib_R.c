#include <stdio.h>

int fib(int);

void main()
{
    int n;
    printf("Enter Number Of Terms : ");
    scanf("%d",&n);

    printf("Fibonacci Series -->\n");   
    printf("%d",fib(n));
}

int fib(int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }

    int fib_nm1 = fib(n-1);
    int fib_nm2 = fib(n-2);
    int fibo = fib_nm1 + fib_nm2;
    return fibo;
}