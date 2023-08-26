/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section J [G1]

    Write a program to find roots of a quadratic equation.
    Equation is of type (ax^2 + bx + c = 0)
*/

#include <stdio.h>
#include <math.h>

void main()
{
    int a,b,c;
    float r1,r2,check;
    
    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Enter a : ");
    scanf("%d",&a);
    printf("Enter b : ");
    scanf("%d",&b);
    printf("Enter c : ");
    scanf("%d",&c);

    check = (pow(b,2)) - (4*a*c);
    r1 = ((-b) + sqrt(check))/(2*a);
    r2 = ((-b) - sqrt(check))/(2*a);

    if (check>0)
    {
        printf("\t\t\t ***** OUTPUT *****\n\n");
        printf("Real Roots Exists !\n");
        printf("Root 1 = %f\n",r1);
        printf("Root 2 = %f\n",r2);
    } else if (check==0)
    {
        printf("\t\t\t ***** OUTPUT *****\n\n");
        printf("Unique Root Exists !\n");
        printf("Root = %f",r1);
    } else
    {
        printf("\t\t\t ***** OUTPUT *****\n\n");
        printf("Real Roots Doesn't Exist !\n");
    }
}