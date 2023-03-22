#include <stdio.h>
#include <string.h>

void main()
{
    int n, i, j, k, fq=0, len_1, len_2, frq=0;
    char ch='A', str_1[20], str_2[20], frq_1[100]={0}, frq_2[100]={0};

    printf("\nEnter String 1 : ");
    fgets(str_1,20,stdin);

    printf("\nEnter String 2 : ");
    fgets(str_2,20,stdin);

    len_1 = strlen(str_1);
    len_2 = strlen(str_2);

    if (len_1==len_2)

    {
        for (i=0; i<100; i++)
        {
            for (j=0; str_1[j]!='\0'; j++)
            {
                for (k=ch; k<='Z'; k++)
                {
                    if (str_1[j]==k)
                    {
                        frq_1[k]++;
                    }
                }
            }
        }
        for (i=0; i<100; i++)
        {
            for (j=0; str_2[j]!='\0'; j++)
            {
                for (k=ch; k<='Z'; k++)
                {
                    if (str_2[j]==k)
                    {
                        frq_2[k]++;
                    }
                }
            }
        }
        for (i=0; i<100; i++)
        {
            if (frq_1[i]==frq_2[i])
            {
                fq++;
            }
        }
        if (fq==100)
        {
            printf("\nStrings Are Anagram !");
        }
        else
        {
            printf("\nStrings Are Not Anagram !");
        }
    }
    else
    {
        printf("\nStrings Are Not Anagram !");
    }
}