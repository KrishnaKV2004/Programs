#include <stdio.h>
#include <string.h>

void main()
{
    int i, j, freq=0, max_freq=0, len=0;
    char max_char, str[20];

    printf("\nEnter String : ");
    fgets(str,20,stdin);

    len = strlen(str);

    for (i=0; i<len; i++)
    {
        for (j=0; j<len; j++)
        {
            if (str[i]==str[j])
            {
                freq++;
            }
        }
        if (freq>max_freq)
        {
            max_freq = freq;
            max_char = str[i];
        }
        freq = 0;
    }

    printf("\nMaximum Occurring Character --> %c",max_char);
    printf("\nFrequency --> %d\n",max_freq);
}