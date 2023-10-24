//  Implementation Of Singly Linked List

//  Header Files -->

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//  Main Function -->

int main()
{
    nd *head = NULL;         //  To Store Address Of First Node
    int nodes;               //  To Insert Multiple Nodes
    int iteration = 0;       //  To Track The Iteration
    int node_count = 0;      //  To Count The Nodes In The Linked List
    char con, pos, choice;   //  To Input Choice, Continue And Position To Operate

    //  Menu For Operations -->

    menu :

        system("cls");
        printf("\n# -------- Linked List -------- #\n");
        printf("\nOperations ---->\n");
        printf("\n[I] To Insert Node");
        printf("\n[D] To Delete Node");
        printf("\n[V] To View Data");
        printf("\n[N] To View Nodes");
        printf("\n[M] To View Middle Node");
        printf("\n[S] To Sort The List");
        printf("\n[R] To Reverse The List");
        printf("\n[K] To Rotate The Linked List");
        printf("\n[E] To Exit Linked List");
        printf("\n\nChoose Operation ----> ");
        scanf(" %c", &choice);

        //  Checking For Operation Cases -->

        switch (choice)
        {
            //  To Insert -->

            case 'I' :
            case 'i' :

                //  Checking Further Possibilities -->
                system("cls");
                printf("\nChoose Place To Insert ---->\n");
                printf("\n[F] To Insert At First Position");
                printf("\n[L] To Insert At Last Position");
                printf("\n[C] To Insert At Custom Position");
                printf("\n[S] To Sort While Inserting");
                printf("\n\nChoose Operation ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'F' :
                    case 'f' :

                        //  Function To Insert Node At First Position
                        printf("\nNumber Of Nodes To Insert --> ");
                        scanf("%d", &nodes);
                        printf("\n");

                        iteration = 0;

                        while (iteration<nodes)
                        {
                            head = f_ins(head);
                            node_count ++;
                            iteration ++;
                        }

                        break;

                    case 'L' :
                    case 'l' :

                        //  Function To Insert Node At Last Position
                        printf("\nNumber Of Nodes To Insert --> ");
                        scanf("%d", &nodes);
                        printf("\n");

                        iteration = 0;

                        while (iteration<nodes)
                        {
                            head = l_ins(head);
                            node_count ++;
                            iteration ++;
                        }
                        
                        break;

                    case 'C' :
                    case 'c' :

                        //  Function To Insert Node At Specific Position
                        head = c_ins(head, node_count);
                        node_count ++;
                        break;

                    case 'S' :
                    case 's' :

                        //  Function To Sort While Insertion
                        head = s_ins(head);
                        node_count ++;
                        break;

                    default:

                        //  Message For Invalid Input Choice
                        printf("\nInvalid Operation !");
                        sleep(2);
                        goto menu;
                        break;
                }
                break;

            case 'D' :
            case 'd' :

                //  Checking Further Possibilities -->

                system("cls");
                printf("\nChoose Place To Delete ---->\n");
                printf("\n[F] To Delete First Node");
                printf("\n[L] To Delete Last Node");
                printf("\n[C] To Delete Custom Node");
                printf("\n[A] To Delete Alternate Nodes");
                printf("\n\nChoose Operation ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'F' :
                    case 'f' :

                        //  Function To Delete First Node
                        head = f_del(head);
                        node_count --;
                        break;

                    case 'L' :
                    case 'l' :

                        //  Function To Delete Last Node
                        head = l_del(head);
                        node_count --;
                        break;

                    case 'C' :
                    case 'c' :

                        //  Function To Delete Custom Node
                        head = c_del(head, node_count);
                        node_count --;
                        break;

                    case 'A' :
                    case 'a' :

                        //  Function To Delete Alternate Nodes
                        head = a_del(head, &node_count);
                        break;

                    default:

                        //  Message For Invalid Input Choice
                        printf("\nInvalid Operation !");
                        sleep(2);
                        goto menu;
                        break;
                }
                break;

            case 'V' :
            case 'v' :

                //  Checking For Further Viewing Possibilities -->

                system("cls");
                printf("\nChoose Operation To View ---->\n");
                printf("\n[A] To View All Data In Linked List");
                printf("\n[S] To View Data Of Specific Node");
                printf("\n\nChoose Operation ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'A' :
                    case 'a' :

                        //  Function To view Entire Linked List
                        f_view(head);
                        break;

                    case 'S' :
                    case 's' :

                        //  Function To View Data At Specific Node
                        c_view(head, node_count);
                        break;

                    default :

                        //  Message For Invalid Input Choice
                        printf("\nInvalid Operation !");
                        sleep(2);
                        goto menu;
                        break;
                }
                break;

            case 'N' :
            case 'n' :

                //  Function To Display Number Of Nodes
                nd_cn(node_count);
                break;

            case 'M' :
            case 'm' :

                //  Function To View Middle Node
                middle(head, node_count);
                break;

            case 'S' :
            case 's' :

                //  Function To Sort The list
                sort(head);
                break;

            case 'R' :
            case 'r' :

                //  Function To Reverse The Linked List
                head = rev(head);
                break;

            case 'K' :
            case 'k' :

                //  Function To Rotate Linked List
                head = rotate(head);
                break;

            case 'E' :
            case 'e' :
                printf("\nLinked List Terminated !");
                sleep(1);
                exit(0);

            default :

                //  Message For Invalid Input Choice
                printf("\nInvalid Operation !");
                sleep(2);
                goto menu;
                break;
        }

        //  To Continue Operations -->

        printf("\nContinue Operation ? [Y/N] --> ");
        scanf(" %c", &con);

        if (con=='Y' || con=='y')
        {
            goto menu;  //  If True Goto Menu
        }
        else if (con=='N' || con=='n')
        {
            printf("\nThank You !");
            sleep(3);
            exit(0);
        }
        else
        {
            printf("\nInvalid Choice !");
            sleep(2);
            goto menu;
        }

    return 0;
}