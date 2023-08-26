#include <stdio.h>

int main()
{
    int year;
    printf("Enter Year : ");
    scanf("%d", &year);

    if (year%4 >0)
    {
        printf("Not A Leap Year !");
    } else {
        printf("Leap Year");
    }
    return 0;
}