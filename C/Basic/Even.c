#include <stdio.h>

int main()
{
    printf("Even Numbers :\n");
    for (int i=1; i<=50; i++)
    {   if (i%2!=0) {
        continue;
    } printf("%d\n", i);
    }
    return 0;
}