//  Header Files -->

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Headers\Prior_Header.h"

//  Main Function -->

int main()
{
    int nodes;              //  To Input Number Of Nodes To Be Inserted
    int iteration;          //  To Iterate To Insert Multiple Nodes
    int node_count = 0;     //  To Count Track Number Of Nodes In Queue
    char choice, con;       //  For Operation Choice And Continue Choice

    prior_queue *head = NULL;

    //  Menu For Operations -->

    menu :

        system("cls");
        printf("\n# -------- Priority Queue -------- #\n");
        printf("\nOperations ---->\n");
        printf("\n[E] To Enqueue Data");
        printf("\n[D] To Dequeue Data");
        printf("\n[V] To View Data");
        printf("\n[N] To View Nodes");
        printf("\n[X] To Exit Priority Queue");
        printf("\n\nChoose Operation ----> ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'E':
            case 'e':

                system("cls");
                printf("\n# -------- Priority Queue -------- #\n");
                printf("\nNumber Of Nodes To Insert --> ");
                scanf("%d", &nodes);

                iteration = 0;

                while (iteration<nodes)
                {
                    system("cls");
                    printf("\n# -------- Priority Queue -------- #\n");
                    head = enqueue(head);
                    node_count ++;
                    iteration ++;
                }

                system("cls");
                printf("\n# -------- Priority Queue -------- #\n");
                printf("\nData Enqueued Successfully !");
                sleep(2);
                goto menu;

            case 'D':
            case 'd':

                system("cls");
                printf("\n# -------- Priority Queue -------- #\n");
                head = dequeue(head);
                node_count--;
                goto menu;

            case 'V':
            case 'v':

                system("cls");
                printf("\n# -------- Priority Queue -------- #\n");
                printf("\nData In Priority Queue [ Data | Priority ] ---->\n\n");
                prior_queue_display(head);
                sleep(5);
                goto menu;

            case 'N':
            case 'n':

                printf("\nNumber Of Nodes In Queue --> %d", node_count);
                sleep(3);
                goto menu;

            case 'X':
            case 'x':

                printf("\nThank You !");
                sleep(2);
                exit(0);
        
            default:
                printf("\nInvalid Input !");
                sleep(2);
                goto menu;
        }

    return 0;
}