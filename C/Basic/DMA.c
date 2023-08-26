#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,elm,*p;
    
    printf("\nEnter Number Of Elements : ");
    scanf("%d",&n);

    p = malloc(n*sizeof(int));

    printf("Enter Elements -->\n");
    
    for (int i=0; i<n; i++)
    {
        printf("Enter Element -->\t");
        scanf("%d",&p[i]);
    }

    printf("\nEnter Element To Search : ");
    scanf("%d",&elm);

    for (int i=0; i<n; i++)
    {
        if (*(p+i)==elm)
        {
            printf("%d\n",i);
            *(p+i) = *(p+i) * *(p+i) * *(p+i);
            printf("%d",*(p+i));
        }
    }
    
    free(p);
    return 0;
}