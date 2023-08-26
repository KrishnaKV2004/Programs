#include <stdio.h>

int main()
{
    int age = 18;
    int *ptr = &age;

    printf("%d\n", age);
    printf("%d\n", *ptr);
    printf("%d\n", *(&age));
    printf("%d\n", ptr);

    return 0;
}