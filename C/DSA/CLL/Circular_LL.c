//  Circular Linked :List ---->

//  Header Files -->

#include <stdio.h>
#include <stdlib.h>

//  Node Structure -->
typedef struct Node {
    int data;
    struct Node* next;
} nd;

//  Function Declaration -->

nd* f_ins(nd*);             //  Function To Insert At Node First Place
nd* l_ins(nd*);             //  Function To Insert At Node Last Place
nd* c_ins(nd*, int);        //  Function To Insert Node At Custom Place

nd* f_del(nd*);             //  Function To Delete First Node
nd* l_del(nd*);             //  Function To Delete Last Node
nd* c_del(nd*, int);        //  Function To Delete Custom Node

void f_view(nd*);           //  Function To View Data In Linked List
void c_view(nd*, int);      //  Function To View Data In Specific Node

nd* rev(nd*);               //  Function To Reverse The Data In Linked List

void nd_cn(int);            //  Function To Count The Nodes In Linked List

//  Main Function -->

int main()
{
    nd* head = NULL;
    int node_count = 0;
    char con, pos, choice;

    menu:

    system("cls");
    printf("\n# -------- Circular Linked List -------- #\n");
    printf("\nOperations ---->\n");
    printf("\n[I] To Insert Node");
    printf("\n[D] To Delete Node");
    printf("\n[V] To View Data");
    printf("\n[N] To View Nodes");
    printf("\n[R] To Reverse The List");
    printf("\n\nChoose Operation ----> ");
    scanf(" %c", &choice);

    switch (choice) {
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
                    head = f_ins(head, &node_count);
                    break;

                case 'L':
                case 'l':
                    head = l_ins(head, &node_count);
                    break;

                case 'C':
                case 'c':
                    head = c_ins(head, &node_count);
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
                    head = f_del(head, &node_count);
                    break;

                case 'L':
                case 'l':
                    head = l_del(head, &node_count);
                    break;

                case 'C':
                case 'c':
                    head = c_del(head, &node_count);
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
                    c_view(head);
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

//  Function Definition ---->

nd* f_ins(nd* head, int* node_count)
{
    int val;
    nd* new_node = (nd*)malloc(sizeof(nd));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated\n");
        return head;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    new_node->data = val;

    if (head == NULL)
    {
        new_node->next = new_node; // Point to itself in a circular list
    }
    else
    {
        new_node->next = head->next;
        head->next = new_node;
    }

    *node_count += 1;
    return new_node;
}

nd* l_ins(nd* head, int* node_count)
{
    int val;
    nd* new_node = (nd*)malloc(sizeof(nd));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated\n");
        return head;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    new_node->data = val;

    if (head == NULL)
    {
        new_node->next = new_node;
        *node_count += 1;
        return new_node;
    }
    else
    {
        new_node->next = head->next;
        head->next = new_node;
        *node_count += 1;
        return head;
    }
}

nd* c_ins(nd* head, int* node_count)
{
    int i, val, indx;
    nd* temp = head;
    nd* new_node = (nd*)malloc(sizeof(nd));

    printf("\nEnter Place To Insert Node --> ");
    scanf("%d", &indx);

    if (indx <= 0 || indx > *node_count + 1)
    {
        printf("\nInvalid Index ! [ Out Of Bound ]\n");
        return head;
    }

    if (indx == 1)
    {
        return f_ins(head, node_count);
    }

    if (indx == *node_count + 1)
    {
        return l_ins(head, node_count);
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    for (i = 1; i < indx - 1; i++)
    {
        temp = temp->next;
    }

    new_node->data = val;
    new_node->next = temp->next;
    temp->next = new_node;
    *node_count += 1;

    return head;
}

nd* f_del(nd* head, int* node_count)
{
    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return head;
    }

    nd* temp = head->next;

    if (temp == head)
    {
        free(head);
        *node_count -= 1;
        return NULL;
    }

    head->next = temp->next;
    free(temp);
    *node_count -= 1;

    return head;
}

nd* l_del(nd* head, int* node_count)
{
    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return head;
    }

    nd* temp = head;
    nd* prev = NULL;

    // Traverse to the last node while keeping track of the previous node
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    // Now 'temp' points to the last node, and 'prev' points to the second last node

    if (prev == NULL)
    {
        // There is only one node in the list
        free(temp);
        *node_count -= 1;
        return NULL;
    }

    // Update the 'next' pointer of the second last node to point to the head
    prev->next = head;

    // Free the last node
    free(temp);

    *node_count -= 1;
    return head;
}

nd* c_del(nd* head, int* node_count)
{
    int i, indx;

    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return head;
    }

    nd* temp = head;
    nd* prev = NULL;

    printf("\nNode To Delete ? --> ");
    scanf("%d", &indx);

    if (indx <= 0 || indx > *node_count)
    {
        printf("\nInvalid Index ! [ Node Doesn't Exist ]\n");
        return head;
    }

    if (indx == 1)
    {
        return f_del(head, node_count);
    }

    for (i = 1; i < indx; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // 'temp' points to the node to be deleted, and 'prev' points to the previous node
    prev->next = temp->next;
    free(temp);

    *node_count -= 1;
    return head;
}

void nd_cn(int node_count)
{
    printf("\nNodes --> %d\n", node_count);
}

nd* rev(nd* head)
{
    if (head == NULL)
    {
        printf("\nNo Nodes To Reverse!\n");
        return head;
    }

    nd* current = head;
    nd* prev = NULL;
    nd* next_node = NULL;

    do
    {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    } while (current != head);

    // Adjust the head to point to the last node (previously the first node)
    head->next = prev;

    printf("\nLinked List Reversed Successfully!\n");
    return prev; // Return the new head (previously the last node)
}