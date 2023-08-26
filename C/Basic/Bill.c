/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section : J
    
    Write a C program to input electricity unit and calculate 
    total electricity bill according to the given condition.
    For first 50 units Rs 0.50 per unit
    For next 100 units Rs 0.75 per unit
    For next 100 units Rs 1.20 per unit
    For unit above 250 Rs 1.50 per unit
    An additional surcharge of 20% of bill is added.
*/
#include <stdio.h>

void main()
{
    int units;
    float bill;
    printf("\t\t\t***** INPUT *****\n\n");
    printf("Enter No.Of Units Used:");
    scanf("%d",&units);

    if(units<=50)
    {
        bill=units*0.5;
    }
    else if(units<=150)
    {
        bill=25+(units-50)*0.75;
    }
    else if(units<=250)
    {
        bill=100+(units-150)*1.2;
    }
    else
    {
        bill=220+(units-250)*1.5;
    }
    bill=bill+0.2*bill;

    printf("\t\t\t***** OUTPUT *****\n");
    printf("The Final Bill Is %f",bill);
}