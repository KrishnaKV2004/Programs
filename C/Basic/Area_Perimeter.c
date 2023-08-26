#include <stdio.h>

int main()
{
    float l, b;

    printf("Enter Length : ");
    scanf("%f", &l);
    
    printf("Enter Breadth : ");
    scanf("%f", &b);

    printf("Perimeter Is : %f Unit\n", 2 * (l + b));
    printf("Area Is : %f Unit sq\n", l * b);
    
    return 0;
}