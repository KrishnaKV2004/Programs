#include<stdio.h>
void main()
{
    int a[20],i,c=0,d=0,n,num,sum,nl,j,ng;
    printf("enter the element the of array ");
    scanf("%d",&n);
    printf("enter the elements of array\n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element ");
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
    printf("no lesser element\n");
    if(d==0)
    printf("no greater element\n");
    if(d)
    printf("greater %d\n",ng);
    if(c)
    printf("lesser %d",nl);
}
