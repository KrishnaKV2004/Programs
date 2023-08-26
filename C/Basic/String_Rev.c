#include <stdio.h>
#include <string.h>

void main()
{
    char s[10];
    int i,n;
    int temp=0;

    printf("Enter String : ");
    gets(s);

    n = strlen(s);

    for (i=0; i<n/2; i++)
    {
        temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }

    puts(s);
}