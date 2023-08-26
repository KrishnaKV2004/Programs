// Take input from user until he enters multiple of 5 -->

#include <stdio.h>

int main()
{
    int n;
    
    do {
        printf("Enter Number : ");
        scanf("%d", &n);
        printf("%d\n", n);

        if (n%5==0) {
            break;
        }
    } while(1);
    printf("Thank You");

    return 0;
}