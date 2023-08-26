#include <stdio.h>
#include <string.h>

void rev(char *);

void main()
{
    int n;
    char str[10];

    printf("\nEnter String --> ");
    fgets(str,10,stdin);

    rev(str);
}

void rev(char *p)
{
    int i,j,len;
    char temp;

    len = strlen(p);

    for (i=0; i<len/2; i++)
    {
        temp = p[i];
        p[i] = p[len-i-1];
        p[len-i-1] = temp;
    }

    printf("Reverse String -->\n");
    puts(p);
}