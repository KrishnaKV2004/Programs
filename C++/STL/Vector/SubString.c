#include <stdio.h>
#include <string.h>

void add(char[], char[], int);

int main()
{
    int p;
    char str[20];
    char str1[20];

    printf("\nEnter String 1 --> ");
    gets(str);

    printf("Enter The Substring --> ");
    gets(str1);

    printf("\nEnter Position --> ");
    scanf("%d",&p);

    add(str, str1, p);

    return 0;
}

void add(char str[], char str1[], int p)
{
    int l, l1, i, j;

    l = strlen(str);
    l1 = strlen(str1);

    for (i = l; i >= p; i--)
    {
        str[i + l1] = str[i];
    }

    for (i = p, j = 0; j < l1; i++, j++)
    {
        str[i] = str1[j];
    }

    puts(str);
}