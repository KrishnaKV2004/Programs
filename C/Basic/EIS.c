#include <stdio.h>

void main()
{
    int s1,s2,s3;

    printf("Enter First side : ");
    scanf("%d",&s1);
    printf("Enter Second side : ");
    scanf("%d",&s2);
    printf("Enter Third side : ");
    scanf("%d",&s3);
    
    if ((s1+s2)>s3 && ((s2+s3)>s1) && ((s1+s3)>s2))
    {
        printf("Valid Triangle\n");
        if(s1==s2 && s2 == s3)
        {
            printf("Equilateral Triangle");
        } else if (s1==s2 || s2==s3 || s1==s3)
        {
            printf("Isoceles Triangle");
        } else
        {
            printf("Scalar Triangle");
        }
    } else
    {
        printf("Invalid Triangle");
    }
}