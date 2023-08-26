#include <stdio.h>
#include <string.h>

void main()
{
    int i,j,l,flag=0;
    char str[20];

    printf("\nEnter String : ");
    fgets(str,20,stdin);

    l = strlen(str);

    for (i=0; str[i]!=0; i++)
    {
        flag++;
    }
    printf("\nLength --> %d",flag-1);
}