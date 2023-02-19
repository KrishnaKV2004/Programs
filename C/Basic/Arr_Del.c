//  To Delete An Element From Given Index

#include <stdio.h>

void main()
{
    //  Declaring Array By Asking Size
    int n,i,ind;
    printf("\nNumber Of Elements ? :\t");
    scanf("%d",&n);
    int a[n];

    //  Inputting Elements In Array
    printf("\nEnter Elements\n");

    for (i=0; i<n; i++)
    {
        printf("-->\t");
        scanf("%d",&a[i]);
    }

    //  Printing Array For Reference
    printf("\n");
    for (i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }

    //  Asking Index To Delete Element
    printf("\n\nEnter Index To Delete Element :\t");
    scanf("%d",&ind);

    //  Overlapping Values To Delete Element
    for (i=ind; i<n-1; i++)
    {
        a[i] = a[i+1];
    }

    //  Printing New Array
    printf("\nNew Array -->\n");
    for (i=0; i<n-1; i++)
    {
        printf("%d\t",a[i]);
    }
}