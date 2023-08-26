# include <stdio.h>

int main()
{
    int n;
    printf("Enter No (0-10) : ");
    scanf("%d", &n);

    if (n<=10) {
        int i=0;
        while (i<=n) {
            printf("%d\n", i);
            i++;
        }
    } else {
        printf("Invalid Input");
    }
    return 0;
}