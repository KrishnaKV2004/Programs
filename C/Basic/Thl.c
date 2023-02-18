//  To find the third largest element in an array -->

#include <stdio.h>

void main()
{
    //  Input Size -->
    int n, i, j, temp=0;
    printf("\nNumber Of Elements ? : ");
    scanf("%d",&n);

    //  Declaring Array -->
    int a[n];

    //  Input Elements -->
    printf("\nEnter Elements\n");

    for (i=0; i<n; i++)
    {
        printf("-->\t");
        scanf("%d",&a[i]);
    }

    //  Sorting Using Bubble Sort -->
    for (j=0; j<n; j++)
    {
        for (i=0; i<n-1; i++)
        {
            if (a[i]<a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }

    //  Printing The Third Largest -->
    printf("\nThird Largest --> %d",a[2]);
}