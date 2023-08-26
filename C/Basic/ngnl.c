/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Input n numbers in an array and find the nearest lesser and
    nearest greater element than a given element.
*/

#include<stdio.h>
void main()
{
    int a[20],i,c=0,d=0,n,num,sum,nl,j,ng;
    printf("Number of Elements in Array : ");
    scanf("%d",&n);
    printf("Enter The Elements of Array -->\n ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter The Element : ");
    scanf("%d",&num);
    sum=num;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]==num-1)
            {
                nl=a[j];
                c++;
            }
            if(c)
            break;
        }
        num--;
        if(c)
        break;
    }
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]==sum+1)
            {
                ng=a[j];
                d++;
            }
            if(d)
            break;
        }
        sum++;
        if(d)
        break;
    }
    if(c==0)
    printf("No Lesser Element\n");
    if(d==0)
    printf("No Greater Element\n");
    if(d)
    printf("Greater --> %d\n",ng);
    if(c)
    printf("Lesser --> %d",nl);
}