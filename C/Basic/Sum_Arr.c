//  To Add Two Arrays

#include <stdio.h>

void main()
{
    int a[10] = {0};
    int b[10] = {0};
    int c[10];

    int e,d;
    printf("Number Of Elements In A ? :\t");
    scanf("%d",&e);
    printf("Number Of Elements In B ? :\t");
    scanf("%d",&d);

    printf("\nEnter Elements Of A\n");
    for (int i=0; i<e; i++)
    {
        printf("-->\t");
        scanf("%d",&a[i]);
    }

    printf("\nEnter Elements Of B\n");
    for (int i=0; i<d; i++)
    {
        printf("-->\t");
        scanf("%d",&b[i]);
    }

    for (int i=0; i<10; i++)
    {
        c[i] = a[i] + b[i];
    }

    printf("\nNew Array -->\n");

    for (int i=0; i<10; i++)
    {
        printf("%d\t",c[i]);
    }
}