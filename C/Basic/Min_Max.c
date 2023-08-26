/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section J [G1]

    Write a program to find minimum and maximum number among n integers.
*/

#include <stdio.h>

void main()
{
    int n,m;
    int min,max;

    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Enter Number Of Integers : ");
    scanf("%d",&n);
    printf("Enter Integers : \n");
    scanf("%d",&m);
    max = m;
    
    for (int i=1; i<=n-1; i++)
    {
        scanf("%d",&m);
        
        if (m>max)
        {
            max = m;
        } else if (m<max)
        {
            min = m;
        }
    }
    printf("\t\t\t ***** OUTPUT *****\n\n");
    printf("Minimum = %d\nMaximum = %d",min,max);
}