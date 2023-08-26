//  To Swap Two Numbers -->

#include <stdio.h>

void main()
{
    int a,b;

    printf("Enter A : ");
    scanf("%d", &a);
    printf("Enter B : ");
    scanf("%d", &b);

    a = a+b;
    b = a-b;
    a = a-b;

    printf("Swapped -->\nA : %d\nB : %d", a,b);
}