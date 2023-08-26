#include <stdio.h>
#include <math.h>

void main()
{
    int p,r,t,n,e,ci;

    printf("Enter Principle Amount : ");
    scanf("%d",&p);

    printf("Enter Rate Of Interest : ");
    scanf("%d",&r);

    printf("Enter Time Period : ");
    scanf("%d",&t);
    
    printf("Enter No Of Times Interest Applied : ");
    scanf("%d",&n);

    ci = pow(e,n*t);
    printf("Compound Interest : %d",ci);
}