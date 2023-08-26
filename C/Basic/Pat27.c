/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Write a program to print following pattern :

    *                 *
    * *             * *
    * * *         * * *
    * * * *     * * * *
    * * * * * * * * * *
*/

#include <stdio.h>

void main()
{
    int n;
    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Enter Limit : ");
    scanf("%d",&n);
    printf("\n\t\t\t ***** OUTPUT *****\n\n");

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            printf("* ");
        }
        for (int k=1; k<=n-i; k++)
        {
            printf("  ");
        }
        for (int k=1; k<=n-i; k++)
        {
            printf("  ");
        }
        for (int s=1; s<=i; s++)
        {
            printf("* ");
        }
        printf("\n");
    }
}