// To print the sum between the numbers entered by the user including them -->

#include <stdio.h>

int main()
{
    int s;
    int e;
    printf("Enter Starting Number : ");
    scanf("%d", &s);
    printf("Enter Ending Number : ");
    scanf("%d", &e);

    int sum=0;
    for (int i=s; i<=e; i++) {
        sum += i;
    } printf("Sum is : %d", sum);

    return 0;
}