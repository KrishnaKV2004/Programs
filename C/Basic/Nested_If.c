#include <stdio.h>

int main()
{
    int num;
    printf("Enter NO. : ");
    scanf("%d", &num);

    if (num>=0){
        printf("Positive\n");
        if (num%2==0){
            printf("Even\n");
        } else {
            printf("Odd\n");
        }

    } else {
        printf("Negative\n");
        if (num%2==0){
            printf("Even\n");
        } else {
            printf("Odd\n");
        }
    }
    return 0;
}