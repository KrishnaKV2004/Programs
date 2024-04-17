#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int *, int);

int * matrixInput(int *, int, int);
int * spiralPrint(int *, int, int);

int main()
{
    int row_size;
    int col_size;
    
    printf("\nEnter The Size Of Row --> ");
    scanf("%d",&row_size);
    printf("Enter The Size Of Column --> ");
    scanf("%d",&col_size);

    int matrix[row_size][col_size];

    int *matrixPtr = matrixInput(&matrix[0][0], row_size, col_size);

    int *spiral = spiralPrint(matrixPtr, row_size, col_size);

    displayMatrix(spiral, row_size*col_size);

    free(spiral);
    return 0;
}

int * matrixInput(int *matrix, int row_size, int col_size)
{
    printf("\nEnter Elements In Matrix -->\n\n");

    for (int i=0; i<row_size; i++)
    {
        for (int j=0; j<col_size; j++)
        {
            printf("Value [%d][%d] --> ",i,j);
            scanf("%d", matrix + i * col_size + j);
        }
    }

    return matrix;
}

void displayMatrix(int *matrix, int matrix_size)
{
    printf("\nSpiral Matrix -->\n\n");

    for (int i=0; i<matrix_size; i++)
    {
            printf("%d  ", matrix[i]);
    }
    printf("\n");
}

int * spiralPrint(int *matrix, int row_size, int col_size)
{
    int * spiral = (int *)malloc((row_size*col_size)*sizeof(int));

    int top_row = 0;
    int bottom_row = row_size - 1;
    int left_col = 0;
    int right_col = col_size - 1;
    int direction = 0;

    int index = 0;

    while (top_row <= bottom_row && left_col <= right_col)
    {
        if (direction == 0)
        {
            for (int i = left_col; i <= right_col; i++)
                spiral[index++] = *((matrix + top_row * col_size) + i);
            top_row++;
        }
        else if (direction == 1)
        {
            for (int i = top_row; i <= bottom_row; i++)
                spiral[index++] = *((matrix + i * col_size) + right_col);
            right_col--;
        }
        else if (direction == 2)
        {
            for (int i = right_col; i >= left_col; i--)
                spiral[index++] = *((matrix + bottom_row * col_size) + i);
            bottom_row--;
        }
        else if (direction == 3)
        {
            for (int i = bottom_row; i >= top_row; i--)
                spiral[index++] = *((matrix + i * col_size) + left_col);
            left_col++;
        }

        direction = (direction + 1) % 4;
    }

    return spiral;
}