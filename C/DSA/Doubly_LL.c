#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} nd;

// Function prototypes
nd* f_ins(nd **head, nd **tail);
nd* l_ins(nd **head, nd **tail);
nd* c_ins(nd **head, nd **tail, int *node_count);
nd* f_del(nd **head, nd **tail);
nd* l_del(nd **head, nd **tail);
nd* c_del(nd **head, nd **tail, int *node_count);
nd *rev(nd *head);

void f_view(nd *head);
void c_view(nd *head, int node_count);
int nd_cn(nd *head);

int main() {
    nd *head = NULL;
    nd *tail = NULL; // Add a tail pointer
    int node_count = 0;
    char con, pos, choice;

        menu :

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

                switch (pos) {
                    case 'F':
                    case 'f':
                        f_ins(&head, &tail);
                        node_count++;
                        break;

                    case 'L':
                    case 'l':
                        l_ins(&head, &tail);
                        node_count++;
                        break;

                    case 'C':
                    case 'c':
                        c_ins(&head, &tail, &node_count);
                        break;

                    default:
                        printf("\nInvalid Operation !");
                        sleep(2);
                        goto menu;
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

                switch (pos) {
                    case 'F':
                    case 'f':
                        f_del(&head, &tail);
                        node_count--;
                        break;

                    case 'L':
                    case 'l':
                        l_del(&head, &tail);
                        node_count--;
                        break;

                    case 'C':
                    case 'c':
                        c_del(&head, &tail, &node_count);
                        break;

                    default:
                        printf("\nInvalid Operation !");
                        sleep(2);
                        goto menu;
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

                switch (pos) {
                    case 'A':
                    case 'a':
                        f_view(head);
                        break;

                    case 'S':
                    case 's':
                        c_view(head, node_count);
                        break;

                    default:
                        printf("\nInvalid Operation !");
                        sleep(2);
                        goto menu;
                }
                break;

            case 'N':
            case 'n':
                nd_cn(head);
                break;

            case 'R':
            case 'r':
                head = rev(head);
                break;

            default:
                printf("\nInvalid Operation !");
                sleep(2);
                goto menu;
        }

        printf("\nContinue Operation ? [Y/N] --> ");
        scanf(" %c", &con);

        if (con == 'N' || con == 'n') {
            break;
        }
    }

    return 0;
}

nd* f_ins(nd **head, nd **tail)
{
    int val;
    nd *new_node = (nd *)malloc(sizeof(nd));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated\n");
        return NULL;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head == NULL)
    {
        *tail = new_node;
    }
    else
    {
        (*head)->prev = new_node;
    }

    *head = new_node;

    return new_node;
}

nd* l_ins(nd **head, nd **tail)
{
    int val;
    nd *new_node = (nd *)malloc(sizeof(nd));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated\n");
        return NULL;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    new_node->data = val;
    new_node->prev = *tail;
    new_node->next = NULL;

    if (*tail == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*tail)->next = new_node;
    }

    *tail = new_node;


    return new_node;
}

nd* c_ins(nd **head, nd **tail, int *node_count)
{
    int i, val, indx;
    nd *temp = *head;
    nd *new_node = (nd *)malloc(sizeof(nd));

    printf("\nEnter Place To Insert Node --> ");
    scanf("%d", &indx);

    if (indx <= 0 || indx > *node_count + 1)
    {
        printf("\nInvalid Index! [Out Of Bound]\n");
        return NULL;
    }

    if (indx == 1)
    {
        return f_ins(head, tail, node_count);
    }

    if (indx == *node_count + 1)
    {
        return l_ins(head, tail, node_count);
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    for (i = 1; i < indx - 1; i++)
    {
        temp = temp->next;
    }

    new_node->data = val;
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    (*node_count)++;

    return new_node;
}

nd* f_del(nd **head, nd **tail)
{
    if (*head == NULL)
    {
        printf("\nLinked List Is Empty !\n");
        return NULL;
    }

    nd *temp = *head;

    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }

    free(temp);

    return *head;
}

nd* l_del(nd **head, nd **tail)
{
    if (*head == NULL)
    {
        printf("\nLinked List Is Empty !\n");
        return NULL;
    }

    nd *temp = *tail;

    if ((*head)->next == NULL) {
        *head = NULL;
        *tail = NULL;
    } else {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }

    free(temp); 

    return *head;
}

nd* c_del(nd **head, nd **tail, int *node_count)
{
    int i, indx;
    nd *temp = *head;

    printf("\nEnter Node To Delete ? --> ");
    scanf("%d", &indx);

    if (indx <= 0 || indx > *node_count)
    {
        printf("\nInvalid Index ! [No Such Node]\n");
        return NULL;
    }

    if (indx == 1)
    {
        return f_del(head, tail, node_count);
    }

    if (indx == *node_count)
    {
        return l_del(head, tail, node_count);
    }

    for (i = 1; i < indx; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    (*node_count)--;

    return *head;
}

nd* rev(nd *head)
{
    if (head == NULL)
    {
        printf("\nNo Nodes To Reverse !\n");
        return NULL;
    }

    nd *temp = NULL;
    nd *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        head = temp->prev;
    }

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

int nd_cn(nd *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    printf("\nNodes --> %d\n", count);
    return count;
}