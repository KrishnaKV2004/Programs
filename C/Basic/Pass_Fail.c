#include <stdio.h>

int main()
{
    int marks;
    printf("Enter Marks : ");
    scanf("%d", &marks);

    if (marks>=0 && marks<=33) {
        printf("Fail\n");
    } else if (marks>33 && marks<=100) {
        printf("Pass\n");
    } else {
        printf("Invalid Input\n");
    }
    return 0;
}