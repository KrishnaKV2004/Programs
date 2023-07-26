//  Tic Tac Toe !

/*
        Assumptions -->

    ∙   Integer matrix Of Size 10
    ∙   Integer Variable place
    ∙   Integer Variable turn
    ∙   Character Array pname_1
    ∙   Character Array pname_2
    ∙   Goto Menu quit
    ∙   Goto Menu again_p1
    ∙   Goto Menu again_p2
    ∙   Void Function drawboard
    ∙   Integer Function win_check
    ∙   Integer Function draw_check
*/
/*  
        Flow Of Program -->

	∙	Start
	∙   Welcome Message
	∙   Ask For Player Names
	∙   Ask For Place To Mark
    ∙   Check For Invalid Mark Location
    ∙   If Invalid, Mark Again
    ∙   If Not, Continue
	∙   Quit If Win Or Draw
    ∙   If Not, Increment To Another Player
    ∙   If Win Or Draw, Quit
    ∙   Stop
*/

//  Importing Headers -->

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <stdlib.h>

//  Declaring Array With Matrix For Structure -->

int matrix[10] = {'0','1','2','3','4','5','6','7','8','9'};

void drawboard();   //  Function To Draw Structure

int win_check();    //  Function To Check For Win

int draw_check();   //  Function To Check For Draw

//  Main Function -->

int main()
{
    int place;      //  Variable To Store Marking Position
    int turn = 1;   //  Variable To Keep Record Of Turn

    char pname_1[20];   //  Array To Store Player 1's Name
    char pname_2[20];   //  Array To Store Player 2's Name

    system("cls");      //  Clearing The Screen
    printf("Jai Shree Ram !");
    printf("\n\nWelcome To Tic Tac Toe -->\n\n");

    printf("Player 1 Name [X] --> ");   //  Input Name Of Player 1
    scanf("%s",&pname_1);
    printf("\n");
    printf("Player 2 Name [O] --> ");   //  Input Name Of Player 2
    scanf("%s",&pname_2);

    
    //  While No One Has Won -->

    while (win_check()!=1)
    {
        drawboard();    //  Draw Structure

        printf("\n");

        //  For Player 1's Turn -->

        if (turn%2!=0)
        {
            again_p1 :      //  Menu For Invalid Mark

            drawboard();    // Draw Structure

            printf("\n");
            printf("%s's Turn -->\n", pname_1);
            printf("Enter Place To Mark : ");
            scanf("%d",&place);     //  Asking For Place To Mark

            if (0>place || place>9 || matrix[place]=='X' || matrix[place]=='O')
            {
                printf("\nInvalid Input ! Try Again -->");
                sleep(1);
                goto again_p1;         //  Goto Again Menu
            }

            matrix[place] = 'X';    //  Marking Desired Place With X
            turn ++;                //  Incrementing Turn

            if (win_check()==1)     //  Checking For Win
            {
                drawboard();        //  Draw Structure Again
                printf("\nCongrats ! %s Won", pname_1);     //  Player Won If True
                goto quit;          //  Goto Quit If Won
            }

            if (draw_check()==1)    //  Checking For Draw
            {
                drawboard();        //  Draw Structure Again
                printf("\nMatch Draw !\n");         //  Match Draw
                goto quit;          //  Goto Quit If Won
            }
        }

        //  For Player 2's Turn -->

        if (turn%2==0)
        {
            again_p2 :      //  Menu For Invalid Mark

            drawboard();    //  Draw Structure

            printf("\n");
            printf("%s's Turn -->\n", pname_2);
            printf("Enter Place To Mark : ");
            scanf("%d",&place);     //  Asking For Place To Mark

            if (0>place || place>9 || matrix[place]=='X' || matrix[place]=='O')
            {
                printf("\nInvalid Input ! Try Again -->");
                sleep(1);
                goto again_p2;         //  Goto Again Menu
            }

            matrix[place] = 'O';   //  Marking Desired Place With O
            turn ++;                //  Incrementing Turn

            if (win_check()==1)     //  Checking For Win
            {
                drawboard();                        //  Draw Structure Again
                printf("\nCongrats ! %s Won", pname_2);     //  Player Won If True
                goto quit;                          //  Goto Quit If Won
            }

            if (draw_check()==1)    //  Checking For Draw
            {
                drawboard();        //  Draw Structure Again
                printf("\nMatch Draw !\n");         //  Match Draw
                goto quit;          //  Goto Quit If Won
            }
        }
    }

    quit :      //  Menu To Quit
    return 0;
}

void drawboard()        //  Drawing Structure With Array matrix
{
    system("cls");      //  Clearing The Screen To Draw Again
    printf("\n Tic Tac Toe \n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", matrix[1], matrix[2], matrix[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", matrix[4], matrix[5], matrix[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", matrix[7], matrix[8], matrix[9]);
    printf("     |     |     \n");
}

int win_check()     //  Checking For Win With Respect To matrix
{
    if ((matrix[1] == matrix[2] && matrix[2] == matrix[3]) || (matrix[4] == matrix[5] && matrix[5] == matrix[6]) || (matrix[7] == matrix[8] && matrix[8] == matrix[9]) || (matrix[1] == matrix[4] && matrix[4] == matrix[7]) || (matrix[2] == matrix[5] && matrix[5] == matrix[8]) || (matrix[3] == matrix[6] && matrix[6] == matrix[9]) || (matrix[1] == matrix[5] && matrix[5] == matrix[9]) || (matrix[3] == matrix[5] && matrix[5] == matrix[7]))
    {
        return 1;   //  Return 1 If True
    }
}

int draw_check()    //  Checking For Draw With Respect To matrix
{
    if ((matrix[1]=='X' || matrix[1]=='O') && (matrix[2]=='X' || matrix[2]=='O') && (matrix[3]=='X' || matrix[3]=='O') && (matrix[4]=='X' || matrix[4]=='O') && (matrix[5]=='X' || matrix[5]=='O') && (matrix[6]=='X' || matrix[6]=='O') && (matrix[7]=='X' || matrix[7]=='O') && (matrix[8]=='X' || matrix[8]=='O') && (matrix[9]=='X' || matrix[9]=='O'))
    {
        return 1;
    }
}