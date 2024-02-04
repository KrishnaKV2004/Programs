#include<stdio.h>

int main()
{
    int a[100],i,n,x,res;

    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the elements of teh array");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("enter the element you want to search");
    scanf("%d",&x);
    res=search(a,n,x);
    printf("%d",res);
}

int search(int a[],int n,int x)
{
    int i,res,y;
    for(i=0;i<n;i++)
    {
	    if(a[i]==x)
	    {
		    y=i;
	    }
    }
    res=y;
    return res;
}