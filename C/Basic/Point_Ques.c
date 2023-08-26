#include <stdio.h>

int main()
{
    int *ptr;
    int x;

    ptr = &x;
    *ptr = 0;

    printf("X = %d\n", x);
    printf("*ptr = %d\n", *ptr);

    *ptr += 5;
    printf("X = %d\n", x);
    printf("*ptr = %d\n", *ptr);

    (*ptr) ++;
    printf("X = %d\n", x);
    printf("*ptr = %d\n", *ptr);

    return 0;
}