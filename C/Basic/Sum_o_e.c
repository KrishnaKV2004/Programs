#include <stdio.h>

void main()
{
    int s_o = 0;
    int s_e = 0;
    char ch;

    printf("Enter (O) For Sum Of Odd Numbers\n");
    printf("Enter (E) For Sum Of Even Numbers\n");
    scanf("%c",&ch);

    switch (ch)
    {
    case 'O':
    case 'o':
        for (int i=1; i<=100; i+=2)
        {
            s_o = s_o + i;
        }
        printf("Sum Of Odd Numbers = %d",s_o);
        break;
    
    case 'E':
    case 'e':
        for (int i=2; i<=100; i+=2)
        {
            s_e = s_e + i;
        }
        printf("Sum Of Even Numbers = %d",s_e);
        break;

    default:
        break;
    }
}