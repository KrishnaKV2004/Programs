//  Header Files ---->

#include "Function.h"

#ifndef SINGLY_MAIN_H
#define SINGLY_MAIN_H

//  Function ---->

void singly_ll()
{
    //  Variables ---->

    nd *head = NULL;            //  To Store Address Of First Node
    int nodes;                  //  To Insert Multiple Nodes
    int iteration = 0;          //  To Track The Iteration
    int node_count = 0;         //  To Count The Nodes In The Linked List
    char pos, choice;           //  To Input Choice, Continue And Position To Operate
    extern void main_menu;

    //  Menu For Operations -->

    singly_menu :

        system("cls");
        printf("\n# -------- SINGLY LINKED LIST -------- #\n");
        printf("\nOperations ---->\n");
        printf("\n[I] To Insert Node");
        printf("\n[D] To Delete Node");
        printf("\n[V] To View Data");
        printf("\n[N] To View Nodes");
        printf("\n[M] To View Middle Node");
        printf("\n[S] To Sort The List");
        printf("\n[R] To Reverse The List");
        printf("\n[K] To Rotate The Linked List");
        printf("\n[X] To Go To Main Menu");
        printf("\n\nChoose Operation ----> ");
        scanf(" %c", &choice);
        
        switch (choice)
        {
            case 'I' :
            case 'i' :

                insert_menu :

                    system("cls");
                    printf("\nChoose Place To Insert ---->\n");
                    printf("\n[F] To Insert At First Position");
                    printf("\n[L] To Insert At Last Position");
                    printf("\n[C] To Insert At Custom Position");
                    printf("\n[S] To Sort While Inserting");
                    printf("\n[X] To Go To Previous Menu");
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

                        goto insert_menu;

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
                        
                        goto insert_menu;

                    case 'C' :
                    case 'c' :

                        //  Function To Insert Node At Specific Position
                        head = c_ins(head, node_count);
                        node_count ++;
                        goto insert_menu;

                    case 'S' :
                    case 's' :

                        //  Function To Sort While Insertion
                        head = s_ins(head);
                        node_count ++;
                        goto insert_menu;

                    case 'X' :
                    case 'x' :

                        goto singly_menu;

                    default :

                        //  Message For Invalid Input Choice
                        printf("\nInvalid Operation !");
                        sleep(2);
                        goto insert_menu;
                }
                
            case 'D' :
            case 'd' :

                delete_menu :

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
                            goto delete_menu;

                        case 'L' :
                        case 'l' :

                            //  Function To Delete Last Node
                            head = l_del(head);
                            node_count --;
                            goto delete_menu;

                        case 'C' :
                        case 'c' :

                            //  Function To Delete Custom Node
                            head = c_del(head, node_count);
                            node_count --;
                            goto delete_menu;

                        case 'A' :
                        case 'a' :

                            //  Function To Delete Alternate Nodes
                            head = a_del(head, &node_count);
                            goto delete_menu;

                        default:

                            //  Message For Invalid Input Choice
                            printf("\nInvalid Operation !");
                            sleep(2);
                            goto delete_menu;
                            break;
                    }

            case 'V' :
            case 'v' :

                view_menu :

                    system("cls");
                    printf("\nChoose Operation To View ---->\n");
                    printf("\n[A] To View All Data In Linked List");
                    printf("\n[S] To View Data Of Specific Node");
                    printf("\n[X] To Go To Previous Menu");
                    printf("\n\nChoose Operation ----> ");
                    scanf(" %c", &pos);

                    switch (pos)
                    {
                        case 'A' :
                        case 'a' :

                            //  Function To view Entire Linked List
                            f_view(head);
                            goto view_menu;

                        case 'S' :
                        case 's' :

                            //  Function To View Data At Specific Node
                            c_view(head, node_count);
                            goto view_menu;

                        case 'X' :
                        case 'x' :

                            goto singly_menu;

                        default :

                            //  Message For Invalid Input Choice
                            printf("\nInvalid Operation !");
                            sleep(2);
                            goto view_menu;
                            break;
                    }

            case 'N' :
            case 'n' :

                //  Function To Display Number Of Nodes
                nd_cn(node_count);
                goto singly_menu;

            case 'M' :
            case 'm' :

                //  Function To View Middle Node
                middle(head, node_count);
                goto singly_menu;

            case 'S' :
            case 's' :

                //  Function To Sort The list
                sort(head);
                goto singly_menu;

            case 'R' :
            case 'r' :

                //  Function To Reverse The Linked List
                head = rev(head);
                goto singly_menu;

            case 'K' :
            case 'k' :

                //  Function To Rotate Linked List
                head = rotate(head, node_count);
                goto singly_menu;

            case 'X' :
            case 'x' :

                goto main_menu;
        
            default :

                printf("\nInvalid Input !");
                sleep(2);
                goto singly_menu;
        }
}

#endif