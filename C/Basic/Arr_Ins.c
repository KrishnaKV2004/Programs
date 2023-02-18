//  To Insert An Element At A Particular Index

#include <stdio.h>

void main()
{
    //  Input No of Elements and Declare Array
    int n, i, el, ind;
    char ch;
    printf("\nNumber Of Elements ? : ");
    scanf("%d",&n);
    int a[20];

    //  Input Elements
    printf("\nEnter Elements\n");

    for (i=0; i<n; i++)
    {
        printf("-->\t");
        scanf("%d",&a[i]);
    }

    //  Checking If User Want To Insert Element
    printf("Do You Want To Insert Element [Y/N] ?\t");
    scanf(" %c",&ch);

    if ((ch=='Y') || (ch=='y'))
    {
        //  Asking Info
        printf("Enter Index :\t");
        scanf("%d",&ind);
        printf("Enter Element To Insert :\t");
        scanf("%d",&el);

        //  Shifting Elements Next To Insertion Index
        if (ind>0 && ind<n)
        {
            for (i=n-1; i>=ind; i--)
            {
                a[i+1]=a[i];
            }

            //  Inserting Element At Desired Index
            a[ind]=el;
        }
        else
        {
            printf("Invalid Index !");
        }
    }

        //  Printing New Array
        printf("\nArray -->\n");
        for (i=0; i<=n; i++)
        {
            printf("%d\t",a[i]);
        }
}