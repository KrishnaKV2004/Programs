#include <stdio.h>
#include <string.h>

void main()
{
    int i;
    char name[20];

    printf("\nEnter Full Name : ");
    fgets(name,20,stdin);

    printf("\nName --> %c.",name[0]);

    for (i=0; name[i]!='\0'; i++)
    {
        if (name[i]==' ')
        {
            if (name[i+1]!=' ')
            {
                printf("%c.",name[i+1]-32);
            }
        }
    }
}