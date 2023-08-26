#include <stdio.h>

int main()
{
    char ch;
    printf("Enter Character : ");
    scanf("%c", &ch);
    
    if (ch >='A' && ch <='Z'){
        printf("Upper Case\n");
    } else if (ch >='a' && ch <='z') {
        printf("Lower Case\n");
    } else {
        printf("Not An English Letter");
    }
    return 0;
}