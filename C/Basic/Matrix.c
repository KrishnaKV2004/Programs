/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Input a matrix of order m x n and print the square of the
    elements in the principal diagonal and cube of the elements
    in the secondary diagonal.
*/

#include <stdio.h>

void main()
{
    int mat[10][10];
    int m, n;
    int i, j;
    
    printf("\t\t\t ***** INPUT *****\n\n");
    printf("Number Of Rows In The Matrix : ");
    scanf("%d", &m);
    printf("Number Of Columns In The Matrix : ");
    scanf("%d", &n);

    printf("Enter The Elements Of The Matrix :\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\t\t\t ***** OUTPUT *****\n\n");
    printf("Square Of Elements In Principal Diagonal -->\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("%d ", mat[i][j] * mat[i][j]);
            }
        }
    }
    printf("\n");

    printf("Cube Of Elements In Secondary Diagonal -->\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i + j == m - 1)
            {
                printf("%d ", mat[i][j] * mat[i][j] * mat[i][j]);
            }
        }
    }
    printf("\n");
}