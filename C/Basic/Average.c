#include <stdio.h>

void main()
{
    float M1,M2,M3,M4,M5,total,percent;

    printf("Enter Marks In Maths : ");
    scanf("%f",&M1);

    printf("Enter Marks In Electrical : ");
    scanf("%f",&M2);

    printf("Enter Marks In Physics : ");
    scanf("%f",&M3);

    printf("Enter Marks In Programming : ");
    scanf("%f",&M4);
    
    printf("Enter Marks In Civil : ");
    scanf("%f",&M5);

    total = M1 + M2 + M3 + M4 + M5;
    percent = (total / 500) * 100;

    printf("Total Marks : %f", total);
    printf("Percentage : %f", percent);
}