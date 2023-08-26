//  To Swap The First And The Last Row In An Matrix

#include <stdio.h>

void main()
{
    //  Asking Number Of Rows And Columns
    int i,j,r,c,temp=0;
    printf("Number Of Rows ? :\t");
    scanf("%d",&r);
    printf("Number Of Columns ? :\t");
    scanf("%d",&c);
    
    //  Declaring 2D Array According To The Size
    int a[r][c];

    //  Inputting Elements
    printf("\nEnter Elements\n");
    for (i=0; i<c; i++)
    {
        for (j=0; j<c; j++)
        {
            printf("-->\t");
            scanf("%d",&a[r][c]);
        }
    }

    //  Swapping The Elements
    for (i=0; i<r; i++)
    {
        if (i==1)
        {
            break;
        }
        for (j=0; j<c; j++)
        {
            temp = a[i][j];
            a[i][j] = a[r-1][j];
            a[r-1][j] = temp;            
        }
    }

    //  Printing The Matrix
    printf("\nNew Matrix -->\n");
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            printf("%d\n",a[i][j]);
        }
    }
}