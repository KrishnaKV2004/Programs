/*
    *
    * *
    * * *
    * * * *
    * * * * *
    * * * *
    * * *
    * *
    *
*/

#include <stdio.h>

void main()
{
    int n;
    printf("Enter Limit : ");
    scanf("%d",&n);

    if (n%2==0)
        {
            printf("Limit Should Be Odd !");
        } else
        {
            for (int i=1; i<=(n+1)/2; i++)
                {
                    for (int j=1; j<=i; j++)
                        {
                            printf("* ");
                        }
                        printf("\n");
                }
            for (int i=1; i<=(n-1)/2; i++)
                {
                    for (int j=1; j<=(n+1)/2-i ; j++)
                        {
                            printf("* ");
                        }
                        printf("\n");
                }
        }
}