#include <stdio.h>

void main()
{
    char pname_1[20];
    char pname_2[20];

    printf("Jai Shree Ram !");
    printf("\n\nWelcome To Tic Tac Toe -->\n");

    printf("Player 1 Name [X] --> ");
    scanf("%s",&pname_1);

    printf("Player 2 Name [O] --> ");
    scanf("%s",&pname_2);

    printf("\n%s\n",pname_1);
    printf("%s\n",pname_2);
}