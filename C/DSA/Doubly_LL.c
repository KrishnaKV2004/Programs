//  Implementation Of Doubly Linked List ---->

//  Header Files -->
#include <stdio.h>
#include <stdlib.h>

//  Structure Of Node -->

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} nd;

//  Function Declaration -->

void f_ins(nd **head, nd **tail);            //  To Insert Node At First Position
void l_ins(nd **head, nd **tail);            //  To Insert Node At Last Position
void c_ins(nd **head, nd **tail);            //  To Insert Node At Custom Position

void f_del(nd **head, nd **tail);            //  To Delete First Node
void l_del(nd **head, nd **tail);            //  To Delete Last Node
void c_del(nd **head, nd **tail);            //  To Delete Custom Node

nd *rev(nd *head);                          //  To Reverse The Linked List

void f_view(nd *head);                      //  To View Data In Linked List
void c_view(nd *head, int node_count);      //  To View Data At Custom Nodes

void nd_cn(int node_count);                 //  To Count Nodes In Linked List

//  Main Function -->

int main()
{
    nd *head = NULL;        //  To Point At First Node
    nd *tail = NULL;        //  To Point At Last Node
    int node_count = 0;
    char con, pos, choice;

    //  Menu To Give Choice Of Operations -->

    menu:
        system("cls");
        printf("\n# -------- Doubly Linked List -------- #\n");
        printf("\nOperations ---->\n");
        printf("\n[I] To Insert Node");
        printf("\n[D] To Delete Node");
        printf("\n[V] To View Data");
        printf("\n[N] To View Nodes");
        printf("\n[R] To Reverse The List");
        printf("\n\nChoose Operation ----> ");
        scanf(" %c", &choice);

        //  Function Calls Based On Desired Operation -->

        switch (choice)
        {
            case 'I':
            case 'i':
                system("cls");
                printf("\nChoose Place To Insert ---->\n");
                printf("\n[F] To Insert At First Position");
                printf("\n[L] To Insert At Last Position");
                printf("\n[C] To Insert At Custom Position");
                printf("\n\nChoose Operation ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'F':
                    case 'f':
                        f_ins(&head, &tail);
                        break;

                    case 'L':
                    case 'l':
                        l_ins(&head, &tail);
                        break;

                    case 'C':
                    case 'c':
                        c_ins(&head, &tail);
                        break;

                    default:
                        printf("\nInvalid Operation !\n");
                        break;
                }
                break;

            case 'D':
            case 'd':
                system("cls");
                printf("\nChoose Place To Delete ---->\n");
                printf("\n[F] To Delete First Node");
                printf("\n[L] To Delete Last Node");
                printf("\n[C] To Delete Custom Node");
                printf("\n\nChoose Operation ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'F':
                    case 'f':
                        f_del(&head, &tail);
                        break;

                    case 'L':
                    case 'l':
                        l_del(&head, &tail);
                        break;

                    case 'C':
                    case 'c':
                        c_del(&head, &tail);
                        break;

                    default:
                        printf("\nInvalid Operation !\n");
                        break;
                }
                break;

            case 'V':
            case 'v':
                system("cls");
                printf("\nChoose Operation To View ---->\n");
                printf("\n[A] To View All Data In Linked List");
                printf("\n[S] To View Data Of Specific Node");
                printf("\n\nChoose Operation ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'A':
                    case 'a':
                        f_view(head);
                        break;

                    case 'S':
                    case 's':
                        c_view(head, node_count);
                        break;

                    default:
                        printf("\nInvalid Operation !\n");
                        break;
                }
                break;

            case 'N':
            case 'n':
                nd_cn(node_count);
                break;

            case 'R':
            case 'r':
                head = rev(head);
                break;

            default:
                printf("\nInvalid Operation !\n");
                break;
        }

        //  To Ask User If He Wish To Continue -->
        
        printf("\nContinue Operation ? [Y/N] --> ");
        scanf(" %c", &con);

        if (con == 'Y' || con == 'y')
        {
            goto menu;
        }
        else
        {
            exit(0);
        }

    return 0;
}

//  Function Definition -->

nd* f_ins(nd **head, nd **tail)
{
    int val;
    nd *new_node = (nd *)malloc(sizeof(nd));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated\n");
        return;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    if (*head == NULL && *tail == NULL)
    {
        new_node->data = val;
        new_node->prev = *head;
        new_node->next = *tail;
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        new_node->data = val;
        new_node->prev = NULL;
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

nd* l_ins(nd **head, nd **tail)
{
    int val;
    nd *new_node = (nd *)malloc(sizeof(nd));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated\n");
        return;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    if (*head == NULL && *tail == NULL)
    {
        new_node->data = val;
        new_node->prev = *head;
        new_node->next = *tail;
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        new_node->data = val;
        new_node->prev = *tail;
        new_node->next = NULL;
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

nd* c_ins(nd **head, nd **tail)
{
    int i, val, indx;
    nd *exc = *head;
    nd *temp = (*head)->next;
    nd *new_node = (nd *)malloc(sizeof(nd));

    printf("\nEnter Place To Insert Node --> ");
    scanf("%d", &indx);

    if (indx <= 0)
    {
        printf("\nInvalid Index ! [ Out Of Bound ]\n");
        return;
    }

    if (indx == 1)
    {
        f_ins(head, tail);
        return;
    }

    if (indx == 2)
    {
        l_ins(head, tail);
        return;
    }

    if (indx > (*tail)->data)
    {
        printf("\nInvalid Index [ Out Of Bound ]\n");
        return;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    for (i = 1; i < indx - 1; i++)
    {
        temp = temp->next;
        exc = exc->next;
    }

    new_node->data = val;
    new_node->prev = exc;
    new_node->next = temp;
    exc->next = new_node;
    temp->prev = new_node;
}

nd* f_del(nd **head, nd **tail)
{
    if (*head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return;
    }

    nd *temp = *head;

    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
        free(temp);
        return;
    }

    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

nd* l_del(nd **head, nd **tail)
{
    if (*head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return;
    }

    nd *temp = *tail;

    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
        free(temp);
        return;
    }

    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    free(temp);
}

nd* c_del(nd **head, nd **tail)
{
    int i, indx;
    nd *exc = *head;
    nd *temp = (*head)->next;

    printf("\nNode To Delete ? --> ");
    scanf("%d", &indx);

    if (indx <= 0)
    {
        printf("\nInvalid Index ! [ No Such Node ]\n");
        return;
    }

    if (indx == 1)
    {
        f_del(head, tail);
        return;
    }

    if (indx == 2)
    {
        l_del(head, tail);
        return;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("\nInvalid Index ! [ Out Of Bound ]\n");
        return;
    }

    for (i = 1; i < indx - 1; i++)
    {
        temp = temp->next;
        exc = exc->next;
    }

    exc->next = temp->next;
    temp->next->prev = exc;
    free(temp);
}

nd* rev(nd *head)
{
    if (head == NULL)
    {
        printf("\nNo Nodes To Reverse !\n");
        return head;
    }

    nd *prev, *curr, *nxt;
    prev = NULL;
    curr = nxt = head;

    while (nxt != NULL)
    {
        nxt = nxt->next;
        curr->next = prev;
        curr->prev = nxt;
        prev = curr;
        curr = nxt;
    }

    head = prev;
    printf("\nLinked List Reversed Successfully !\n");
    return head;
}

void f_view(nd *head)
{
    while (head != NULL)
    {
        printf("\nData --> %d", head->data);
        head = head->next;
    }

    printf("\n");
}

void c_view(nd *head, int node_count)
{
    int i, indx;
    nd *temp = head;

    printf("\nEnter Index To View Node Data --> ");
    scanf("%d", &indx);

    if (indx <= 0 || indx > node_count)
    {
        printf("\nInvalid Node !\n");
        return;
    }

    for (i = 1; i < indx; i++)
    {
        temp = temp->next;
    }

    printf("\nData --> %d\n", temp->data);
}

void nd_cn(int node_count)
{
    printf("\nNodes --> %d\n", node_count);
}