#include <stdio.h>
#include <math.h>
#include <conio.h>

void main()
{
    int x, p2, p3;
    printf("Enter x : ");
    scanf("%d",&x);

    p2 = pow(x,2);
    p3 = pow(x,3);

    if (x>=0 && x<=10)
    {
        printf("F(x) = %d", p2+2);
    } else if (x>=11 && x<=20)
    {
        printf("F(x) = %d", p2+(2*x));
    } else if (x>=21 && x<=30)
    {
        printf("F(x) = %d", p3+4);
    } else
    {
        printf("F(x) = 0");
    }
    getch();
}