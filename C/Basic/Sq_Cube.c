// To Give Square Or Cube Of A Number By Giving A Choice

#include <stdio.h>
#include <math.h>

void main()
{
    int n,c,s;
    char ch;

    printf("Enter a Number : ");
    scanf("%d",&n);
    printf("Enter A For Square or B For Cube : ");
    scanf("%c",&ch);

    s = pow(n,2);
    c = pow(n,3);

    switch (ch)
    {
    case 'A':
    case 'a':
        printf("%d",s);
        break;

    case 'B':
    case 'b':
        printf("%d",c);
        break;

    default:
        printf("Invalid Input");
        break;
    }
}