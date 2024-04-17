#include <stdio.h>
#include <string.h>

int main()
{
    char str[40];

    printf("Enter a string\n");
    gets(str);

    int i=0;
    
    while(str[i]!='\0')
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i]=str[i]-32;
            i++;
        }
    }

    printf("String in uppercase is: %s", str);

    return 0;
}