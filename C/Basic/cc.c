#include<stdio.h>

int fun(int x)

{

    if(x<=5)

    return x;

    return fun(--x);

}

int main()

{

    printf("%d",fun(10));

    return 0;

}