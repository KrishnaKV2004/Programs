#include <stdio.h>

int main()
{
    int marks;
    printf("Enter Marks : ");
    scanf("%d", &marks);

    if (marks>=0 && marks<33){
        printf("Grade : C\n");
    } else if (marks>=33 && marks<=70){
        printf("Grade : B\n");
    } else if (marks>70 && marks<=80){
        printf("Grade : B+\n");
    } else if (marks>80 && marks<=90){
        printf("Grade : A\n");
    } else if (marks>90 && marks<=100){
        printf("Grade : A+");
    } else {
        printf("Invalid Input\n");
    }
    return 0;
}