//  To Encode A String -->

//  Header Files
#include<stdio.h>
#include<string.h>

//  Main Function
void main()
{
    //  Declaring Variables and Array
    int i;
    char str[100];

    //  Input String
    printf("\nEnter String To Encode : ");
    fgets(str,20,stdin);

    //  Encoding
    for (i=0; str[i]!='\0'; i++)
    {
        if (str[i]>'a' && str[i]<='z')
        {
            str[i] = str[i] - 1;
        }
        if (str[i]=='a')
        {
            str[i] = 'z';
        }
        if (str[i]>'A' && str[i]<='Z')
        {
            str[i] = str[i] - 1;
        }
        if (str[i]=='A')
        {
            str[i] = 'Z';
        }
    }

    //  Printing the Encoded String
    printf("\nEncoded String : ");
    puts(str);
}