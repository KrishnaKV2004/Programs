//  To find two even nos and swap them

#include <stdio.h>

void main()
{
    //  Declaring The Array
    int n,i,j,k,z,flag=0;
    printf("Number Of Elements ? :\t");
    scanf("%d",&n);
    int a[n];

    //  Input Elements
    printf("\nEnter Elements\n");
    for (i=0; i<n; i++)
    {
        printf("-->\t");
        scanf("%d",a[i]);
    }

    //  Finding Index Of First Even Number
    for (i=0; i<n; i++)
    {
        if (a[i]%2==0)
        {
            j=i;
            break;
        }
    }

    //  Finding Index Of Second Even Number
    for (z=j+1; z<n; z++)
    {
        if (a[z]%2==0)
        {
            k=z;
            break;
        }
    }

    printf("\n%d %d\n",j,k);
}