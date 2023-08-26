#include <stdio.h>
#include <string.h>

void con(char *, char *);

int main()
{
    char str1[10], str2[10];

    printf("Enter String 1 -->\t");
    fgets(str1, 10, stdin);
    printf("Enter String 2 -->\t");
    fgets(str2, 10, stdin);

    con(str1, str2);

    return 0;
}

void con(char *p, char *r)
{
    int i, j;
    char new_str[20];

    int len1 = strlen(p);
    int len2 = strlen(r);

    for (i = 0; i < len1 - 1; i++)
    {
        new_str[i] = p[i];
    }

    for (j = 0; j < len2; j++, i++)
    {
        new_str[i] = r[j];
    }

    new_str[i] = '\0'; // Add null terminator at the end of the concatenated string

    printf("\nConcatenated String -->\n\n");
    puts(new_str);
}