/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Write a program to input n elements in an array and 
    organize them in descending order.
*/

#include <stdio.h>

void main()
{
    int n,i,j,m,t;
    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Enter Number Of Elements To Be Entered  : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter Elements : \n");

    for (int i=0; i<n; i++)
    {
        scanf("%d",&m);
        a[i]=m;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("\t\t\t ***** OUTPUT *****\n");
    printf("\nSorted Array -->\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
}