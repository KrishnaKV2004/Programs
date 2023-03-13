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
    printf("\nEnter String To Decode : ");
    fgets(str,20,stdin);

    //  Decoding
    for (i=0; str[i]!='\0'; i++)
    {
        if (str[i]=='z')
        {
            str[i] = 'a';
        }

        if (str[i]>'a' && str[i]<='z')
        {
            str[i] = str[i] + 1;
        }

        if (str[i]=='Z')
        {
            str[i] = 'A';
        }
        
        if (str[i]>'A' && str[i]<='Z')
        {
            str[i] = str[i] + 1;
        }
    }

    //  Printing the Decoded String
    printf("\nDecoded String : ");
    puts(str);
}