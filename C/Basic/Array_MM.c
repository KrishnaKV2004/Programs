/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Write a user defined code to input 10 elements in an array
    (all distinct). Pass this array to the function and print the
    sum of first three smallest and first three largest elements
    present in the array.
*/

#include <stdio.h>

void sum(int[]);

int i,j,t,add=0;

void main()
{
    int a[10];
    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Enter 10 Elements : ");

    for (int i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\t\t\t ***** OUTPUT *****\n\n");
    sum(a);
}

void sum(int b[])
{
    for(i=0; i<10; i++)
    {
        for(j=0; j<10-i-1; j++)
        {
            if(b[j] < b[j+1])
            {
                t = b[j];
                b[j] = b[j+1];
                b[j+1] = t;
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        add = add + b[i];
    }
    printf("Sum Of Three Largest = %d\n",add);

    add = 0;

    for(int i=9; i>6; i--)
    {
        add = add + b[i];
    }
    printf("Sum Of Three Smallest = %d\n",add);
}