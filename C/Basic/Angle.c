#include <stdio.h>

void main()
{
    int a1, a2, a3;

    printf("Enter Angle 1 : ");
    scanf("%d",&a1);
    
    printf("Enter Angle 2 : ");
    scanf("%d",&a2);

    a3 = 180-(a1+a2);
    printf("Angle 3 : %d",a3);
}
