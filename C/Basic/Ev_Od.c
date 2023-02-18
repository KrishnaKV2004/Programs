//  To separate even and odd elements in different array -->

#include <stdio.h>

void main()
{
    int n, j=0, k=0;
    printf("\nNumber Of Elements ? : ");
    scanf("%d",&n);
    int a[n], e[n], o[n];

    for (int i=0; i<n; i++)
    {
        printf("-->\t");
        scanf("%d",&a[i]);
    }

    for (int i=0; i<n; i++)
    {
        if (a[i]%2==0)
        {
            e[j] = a[i];
            j++;
        }
        else
        {
            o[k] = a[i];
            k++;
        }
    }

    printf("\nOdd Elements -->\n");

    for (int i=0; i<j; i++)
    {
        printf("%d\t",e[i]);
    }
    
    printf("\nEven Elements -->\n");

    for (int i=0; i<k; i++)
    {
        printf("%d\t",o[i]);
    }
}