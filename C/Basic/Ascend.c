#include <stdio.h>

void main()
{
    int n1,n2,n3,small,mid,large;

    printf("Enter First Number : ");
    scanf("%d",&n1);

    printf("Enter Second Number : ");
    scanf("%d",&n2);

    printf("Enter Third Number : ");
    scanf("%d",&n3);

    large = n1;

    if (n2>n1)
    {
        large = n2;
    } else if (n3>n1)
    {
        large = n3;
    } else
    {
        large = n1;
    }
    if (large==n1)
    {
        if(n2>n3)
        {
            mid = n2;
            small = n3;
        } else
        {
            mid = n3;
            small = n2;
        }
    } else if (large==n2)
    {
        if (n1>n3)
        {
            mid = n1;
            small = n3;
        } else
        {
            mid = n3;
            small = n1;
        }
    } else if (large==n3)
    {
        if (n1>n2)
        {
            mid = n1;
            small = n2;
        } else
        {
            mid = n2;
            small = n1;
        }
    } else
    {
        printf("Invalid Input");
    }
    printf("Ascending Order : %d, %d, %d\n", small,mid,large);
}