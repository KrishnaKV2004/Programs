#include <stdio.h>

void main()
{
    FILE *fe, *fo, *fd;
    int i,tmp;

    fd = fopen("Data.txt","r");
    fe = fopen("Even.txt","w");
    fo = fopen("Odd.txt","w");
    
    for (i=0; getc(fd)!=EOF; i++)
    {
        tmp = getc(fd);
        if (tmp%2==0)
        {
            putc(fe);
        }
        else
        {
            putc(fo);
        }
    }

    fclose(fd);
    fclose(fe);
    fclose(fo);
}