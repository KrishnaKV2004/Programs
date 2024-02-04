//  Header Files ---->

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//  Headers In Sub Folders ---->

#include "Headers/Singly/Main.h"
#include "Headers/Doubly/Main.h"
#include "Headers/Circular/Main.h"

//  Main Function ---->

int main()
{   
    //  Variables ---->

    char con;
    char list_type;

    //  Main Menu ----> 

    main_menu :

        system("cls");
        printf("\n# ------ LINKED LIST ------ #\n\n");
        printf("• [S] Singly Linked List\n");
        printf("• [D] Doubly Linked List\n");
        printf("• [C] Circular Linked List\n");
        printf("• [X] To Exit Linked List");
        printf("\nChoose List ----> ");
        scanf(" %c", &list_type);

        switch (list_type)
        {
            case 'S':
            case 's':

                singly_ll();
                goto main_menu;
        
            case 'D':
            case 'd':

                doubly_ll();
                goto main_menu;

            case 'C':
            case 'c':

                circular_ll();
                goto main_menu;

            case 'X':
            case 'x':

                exit(0);

            default:
                
                printf("\nInvalid Input !");
                sleep(3);
                goto main_menu;
                break;
        }

    return 0;
}
