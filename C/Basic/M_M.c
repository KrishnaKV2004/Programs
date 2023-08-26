#include <stdio.h>

void min_max(int *, int);

void main()
{
    int n;
    printf("\nEnter Number Of Elements : ");
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter Elements -->\n");

    for (int i=0; i<n; i++)
    {
        printf("Enter : ");
        scanf("%d",&arr[i]);
    }

    min_max(arr,n);

    printf("\nMin --> %d & Max --> %d", arr[0], arr[n-1]);
}

void min_max(int *p, int n)
{
    int temp;

    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (*(p+i)> *(p+j))
            {
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
}