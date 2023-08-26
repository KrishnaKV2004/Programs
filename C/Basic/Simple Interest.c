#include <stdio.h>

void main()
{
    int si, p, r, t;

    printf("Enter Principle : ");
    scanf("%d",&p);
    printf("Enter Rate : ");
    scanf("%d",&r);
    printf("Enter Time : ");
    scanf("%d",&t);
    
    si = (p*r*t)/100;
    printf("Simple Interest : %d", si);
}