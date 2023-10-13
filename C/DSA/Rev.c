//  Implementation Of Singly Linked List

//  Header Files -->

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//  Node Structure To Store Data + Address-->

typedef struct Node
{
    int data;               //  Integer Variable To Store Data
    struct Node * next;     //  Self Referencing Pointer To Store Address Of Next Node
} nd;

//  Function Declaration-->

nd* f_ins(nd*);             //  To Insert Node At First Position
nd* l_ins(nd*);             //  To Insert Node At Last Position
nd* c_ins(nd*, int);        //  To Insert Node At Custom Position

nd* f_del(nd*);             //  To Delete First Node Of Linked List
nd* l_del(nd*);             //  To Delete Last Node Of Linked List
nd* c_del(nd*, int);        //  To Delete Node From Custom Position

nd * rev(nd *);             //  To Reverse The Linked List

void f_view(nd*);           //  To View Full Data In Linked List
void c_view(nd*, int);      //  To View Specific Node Data In Linked List

void nd_cn(int);            //  To Display Number Of Nodes In Linked List

//  Main Function -->

int main()
{
    nd *head = NULL;         //  To Store Address Of First Node
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
        printf("\n[R] To Reverse The List");
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
                printf("\n\nChoose Operation ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'F' :
                    case 'f' :

                        //  Function To Insert Node At First Position
                        head = f_ins(head);
                        node_count ++;
                        break;

                    case 'L' :
                    case 'l' :

                        //  Function To Insert Node At Last Position
                        head = l_ins(head);
                        node_count ++;
                        break;

                    case 'C' :
                    case 'c' :

                        //  Function To Insert Node At Specific Position
                        head = c_ins(head, node_count);
                        node_count ++;
                        break;

                    default:

                        //  Message For Invalid Input Choice
                        printf("\nInvalid Operation !\n");
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

                    default:

                        //  Message For Invalid Input Choice
                        printf("\nInvalid Operation !\n");
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
                        printf("\nInvalid Operation !\n");
                        break;
                }
                break;

            case 'N' :
            case 'n' :

                //  Function To Display Number Of Nodes
                nd_cn(node_count);
                break;

            case 'R' :
            case 'r' :

                //  Function To Reverse The Linked List
                head = rev(head);
                break;

            default :

                //  Message For Invalid Input Choice
                printf("\nInvalid Operation !\n");
                break;
        }

        //  To Continue Operations -->

        printf("\nContinue Operation ? [Y/N] --> ");
        scanf(" %c", &con);

        if (con=='Y' || con=='y')
        {
            goto menu;  //  If True Goto Menu
        }
        else
        {
            exit(0);    //  Else Exit
        }

    return 0;
}

//  Function Definition -->

nd* f_ins(nd *head)
{
    int val;                                    //  To Store Data Value
    nd *new_node = (nd *)malloc(sizeof(nd));    //  New Node Allocation

    //  Checking If Memory Is Allocated
    if (new_node == NULL)
    {
        //  If Memory Not Allocated
        printf("\nSorry ! Memory Not Allocated\n");
        return head;
    }

    //  Input Value To Store
    printf("\nEnter Data --> ");
    scanf("%d", &val);

    //  Joining New Node And Updating Head
    new_node->data = val;
    new_node->next = head;
    head = new_node;

    return head;
}

nd* l_ins(nd *head)
{
    int val;                                    //  To Store Data Value
    nd *temp = head;                            //  Temp Pointer To Traverse To The Last Node
    nd *new_node = (nd *)malloc(sizeof(nd));    //  New Node Allocation

    //  Checking If Memory Is Allocated
    if (new_node == NULL)
    {
        //  If Memory Not Allocated
        printf("\nSorry ! Memory Not Allocated\n");
        return head;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    //  Checking If There Is No Node
    if (head == NULL)
    {
        //  Updating New Node With Head Info
        new_node->data = val;
        new_node->next = head;
        head = new_node;

        return head;
    }
    //  If Nodes Exists Already
    else
    {
        //  Traversing To The Last Node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        //  Updating New Node With Help Of Temp Info
        new_node->data = val;
        temp->next = new_node;
        new_node->next = NULL;
    }

    return head;
}

nd* c_ins(nd *head, int node_count)
{
    int i,val,indx;                             //  To Iterate, Store Value And Index
    nd *exc = head;                             //  To Exchange Address With Temp Node
    nd *temp = head->next;                      //  To Traverse To Specific Node
    nd *new_node = (nd *)malloc(sizeof(nd));    //  New node To Insert

    //  Input Index To Insert Node
    printf("\nEnter Place To Insert Node --> ");
    scanf("%d", &indx);

    //  Checking -ve Index Condition
    if (indx<=0)
    {
        printf("\nInvalid Index ! [ Out Of Bound ]\n");
        return head;
    }

    //  Checking First Node Condition
    if (indx == 1)
    {
            //  Function To Insert Node At Index 1 
            head = f_ins(head);
    }

    //  Checking If Index Is Last Node
    if (indx == (node_count+1))
    {
        head = l_ins(head);
        return head;
    }

    //  Checking If Index Exceeds Node
    if (indx > node_count)
    {
        printf("\nInvalid Index [ Out Of Bound ]\n");
        return head;
    }

    //  Inserting Nodes in Between
    else
    {
        printf("\nEnter Data --> ");
        scanf("%d", &val);

        for (i=1; i<indx-1; i++)
        {
            //  Traversing To Specified Node
            temp = temp->next;
            exc = exc->next;
        }

        //  Updating Address Of Node
        new_node->data = val;
        new_node->next = exc->next;
        exc->next = new_node;
    }

    return head;
}

nd* f_del(nd *head)
{
    //  Checking If List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return head;
    }

    nd *temp = head;        //  Temp Pointer To Traverse

    //  Updating Head With Next Node And Deleting Temp
    head = head->next;
    free(temp);

    return head;
}

nd* l_del(nd *head)
{
    //  Checking If Linked List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return head;
    }

    nd *temp = head;         //  Temp Pointer To Traverse
    nd *exc = head->next;    //  Fr Pointer Pointing Next Node Of Temp

    //  Traversing Fr To Last Node
    while (exc->next != NULL)
    {
        //  Updating Temp And Fr To Last Node
        temp = temp->next;
        exc = exc->next;
    }

    //  Assigning NULL To Second Last Node And Deleting Last Node
    temp->next = NULL;
    free(exc);

    return head;
}

nd* c_del(nd *head, int node_count)
{
    int i, indx;    //  To Iterate And Store Index

    //  Checking If Linked List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return head;
    }

    nd *exc = head;
    nd *temp = head->next;

    printf("\nNode To Delete ? --> ");      //  Input Node To Delete
    scanf("%d", &indx);                     //  Store Input In Variable

    //  If Index Is Zero
    if (indx<=0)
    {
        printf("\nInvalid Index ! [ No Such Node ]\n");
        return head;
    }

    //  If Index Is 1
    else if (indx == 1)
    {
        head = f_del(head);     //  Function To Delete First Node
    }

    //  If Index Exceeding Last Node 
    else if (indx > node_count)
    {
        printf("\nInvalid Index ! [ Node Doesn't Exist ]\n");
        return head;
    }

    //  If Index Is Out Of Bound
    else if (temp == NULL || temp->next == NULL)
    {
        printf("\nInvalid Index ! [ Out Of Bound ]\n");
        return head;
    }

    else
    {
        for (i=1; i<indx-1; i++)
        {
            //  Traversing To The Specific Index
            temp = temp->next;
            exc = exc->next;
        }

        //  Updating Node Address And Deleting Node
        exc->next = temp->next;
        free(temp);
    }

    return head;
}

nd* rev(nd *head)
{
    nd *prev = NULL;
    nd *current = head;
    nd *nxt = head->next;

    while (nxt->next != NULL)
    {
        current->next = prev;
        nxt->next = current;
        prev = current;
        nxt = nxt->next;
        current = current->next;
    }

    head = nxt;
    return head;
}

void f_view(nd *head)
{
    //  Checking If Linked List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty !\n");
        return;
    }

    while (head != NULL)
    {
        //  Traversing Linked List And Printing Data
        printf("\nData --> %d", head->data);
        head = head->next;  //  Moving To Next Node
    }

    printf("\n");
}

void c_view(nd *head, int node_count)
{
    int i, indx;        //  To Iterate And Store Index
    nd *temp = head;    //  To Traverse To Specific Node

    //  Checking If Linked List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty !\n");
        return;
    }

    printf("\nEnter Index To View Node Data --> ");
    scanf("%d", &indx);

    if (indx<=0 || indx>node_count)
    {
        printf("\nInvalid Node !\n");
        return;
    }

    for (i=1; i<indx; i++)
    {
        //  Traverse To Specified Node
        temp = temp->next;
    }

    //  Printing Data At Specified Node
    printf("\nData --> %d\n", temp->data);
}

void nd_cn(int node_count)
{
    //  Display Number Of Nodes
    printf("\nNodes --> %d\n", node_count);
}