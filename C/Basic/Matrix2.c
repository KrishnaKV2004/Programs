/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Input a matrix of order m x n. Print the sum of odd elements
    in present each row and sum of odd elements present in each column.
*/

#include <stdio.h>

void main()
{
  int m, n;
  printf("\t\t\t***** INPUT *****\n\n");
  printf("Number Of Rows In The Matrix : ");
  scanf("%d", &m);
  printf("Number Of Columns In The Matrix : ");
  scanf("%d", &n);

  int matrix[m][n];
  printf("Enter The Elements Of The Matrix : \n");

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("\t\t\t***** OUTPUT *****\n\n");
  printf("Sum Of Odd Elements In Each Row:\n");

  for (int i = 0; i < m; i++)
  {
    int row_sum = 0;
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j] % 2 == 1)
      {
        row_sum += matrix[i][j];
      }
    }
    printf("Row %d: %d\n", i+1, row_sum);
  }
  printf("Sum Of Odd Elements In Each Column:\n");

  for (int j = 0; j < n; j++)
  {
    int column_sum = 0;
    for (int i = 0; i < m; i++)
    {
      if (matrix[i][j] % 2 == 1)
      {
        column_sum += matrix[i][j];
      }
    }
    printf("Column %d: %d\n", j+1, column_sum);
  }
}
