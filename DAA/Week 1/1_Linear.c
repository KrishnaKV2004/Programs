#include<stdio.h>

int search(int [], int, int);

int main()
{
    int a[20];
    int i,n,x,res;

    printf("Number Of Elements In Array ? --> ");
    scanf("%d",&n);
    printf("Enter Elements In Array -->\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter Element To Search --> ");
    scanf("%d",&x);

    res=search(a,n,x);

    printf("%d",res);
}

int search(int a[], int n, int x)
{
    int i,res,y;

    for (i=0; i<n; i++)
    {
	    if (a[i]==x)
	    {
		    y=i;
	    }
    }

    res=y;
    return res;
}