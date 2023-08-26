/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section J [G1]

    Write a code to remove duplicate elements
    in an array using functions.
*/

#include <stdio.h>

void dup(int [],int);

void main()
{
    int i,k,n;
    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Number Of Elements : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter Elements -->\n");

    for (i=0; i<n; i++)
    {
        scanf ("%d",&k);
        a[i]=k;
    }
    printf("\t\t\t ***** OUTPUT *****\n\n");
    printf("New Array -->\n");
    dup(a,n);
}

void dup(int a[],int n)
{
    int i,j,t=1;

    for (i=0; i<n; i++)
    {
        t=1;
        for (j=i+1; j<n; j++)
        {
            if (a[i]==a[j])
            {
                t=0;
                break;
            }
        }
        if (t)
        {
            printf("%d ",a[i]);
        }
    }
}