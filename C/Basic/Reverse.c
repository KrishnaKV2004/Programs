/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Write a C program to input n integer numbers from user
    and print reverse of each number.
*/

#include<stdio.h>

void main()
{
    int n,c,num,rev,rem;
    rev=0;

    printf("\t\t\t***** INPUT *****\n\n");
    printf("Number Of Elements : ");
    scanf("%d",&n);
    printf("\t\t\t***** OUTPUT *****\n\n");

    for (c=1; c<=n; c++)
    {
        printf("Enter Element %d : ",c);
        scanf("%d",&num);
        rev=0;
        while(num!=0)
        {
          rem=num%10;
          rev=rev*10+rem;
          num=num/10;
        }
       printf("Reverse Number --> %d\n\n",rev);
    }
}
