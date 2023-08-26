#include <stdio.h>

int main()
{
    float rad;
    float pi = 3.14;

    printf("Enter Radius : ");
    scanf("%f", &rad);

    printf("Area Is : %f", pi * rad * rad);

    return 0;
}