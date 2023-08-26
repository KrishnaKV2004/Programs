#include <stdio.h>

void main()
{
    float c,f;

    printf("Enter Temp In Fahrenheit : ");
    scanf("%f",&f);
    
    c = ((f-32)*5)/9;
    printf("Temp In Celsius : %f",c);
}