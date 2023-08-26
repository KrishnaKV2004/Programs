/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Input n characters in an array and replace the characters
    as per the given instructions :
    
    1. Replace all capital vowels with symbol $.
    2. Replace all the capital consonant with symbol #.
    3. Replace all small letter vowels with symbol *.
    4. Replace all the small letter consonant with symbol +.
    5. Replace all special symbols with spaces.
    6. Replace all spaces with digit 5.
    7. Replace all digits with @
*/

#include <stdio.h>

void main()
{
    int n,i;
    printf("\t\t\t***** INPUT *****\n\n");
    printf("Enter Number Of Elements To Be Entered : ");
    scanf("%d",&n);
    char a[n];
    printf("Enter ELements : \n");
    getchar();

    for (i=0; i<n; i++)
    {
        scanf("%c",&a[i]);
        getchar();
    }
    for (i=0; i<n; i++)
    {
        if (a[i]>='a' && a[i]<='z')
        {
            if (a[i]=='a' || a[i]=='e' || a[i]=='i' ||
                a[i]=='o' ||a[i]=='u')
              {
                a[i]='*';
              }
            else
              {
                a[i]='+';
              }
        }
        if (a[i]>='A' && a[i]<='Z')
        {
            if(a[i]=='A' || a[i]=='E' || a[i]=='I' ||
               a[i]=='O' || a[i]=='U')
              {
                  a[i]='$';
              }
            else
              {
                  a[i]='#';
              }
        }
        if (a[i]==' ')
        {
            a[i]='5';
        }
        if (a[i]>='0' && a[i]<='9')
        {
            a[i]='@';
        }
        else
        {
            a[i]=32;
        }
    }
    for (int i=1; i<n; i++)
    {
        printf("%c ",a[i]);
    }
}