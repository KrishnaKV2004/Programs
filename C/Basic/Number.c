#include <stdio.h>

int main()
{
    int age;

    printf("Enter Age : ");
    scanf("%d", &age);
    
    age >=18 ? printf("Adult"): printf("Child");
    return 0;
}