//  To Implement Queue Using Linked List ---->

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//  Structure Of Node -->

typedef struct Node
{
    int data;
    struct Node *next;
} queue;

//  Function Declaration -->

void peek(queue *);                       //  To Display Top Element Of Queue
void disp(queue *);                       //  To Display Elements Of Queue
void node(queue *);                       //  To Count Number Of Nodes
void enqueue(queue **, queue **);         //  To Pop Element From Queue
void dequeue(queue **, queue **);         //  To Push Element In Queue

//  Main Function -->

int main()
{
    char con, choice;
    queue *front = NULL;
    queue *rear = NULL;

    menu :
        system("cls");
        printf("\n# ------ QUEUE ------ #\n");
        printf("\nOperations ---->\n");
        printf("\n[E] To Enqueue");
        printf("\n[D] To Dequeue");
        printf("\n[P] To Peek");
        printf("\n[V] To Display");
        printf("\n[N] To Count Nodes");
        printf("\n[X] To Exit Stack");
        printf("\n\nChoose Operation ----> ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'E' :
        case 'e' :
            enqueue(&front, &rear);
            break;
        
        case 'D' :
        case 'd' :
            dequeue(&front, &rear);
            break;

        case 'P' :
        case 'p' :
            peek(front);
            break;

        case 'V' :
        case 'v' :
            disp(front);
            break;

        case 'N' :
        case 'n' :
            node(front);
            break;

        case 'X' :
        case 'x' :
            printf("\nQueue Terminated !");
            sleep(1);
            exit(0);

        default:
            printf("\nInvalid Operation !");
            sleep(2);
            goto menu;
            break;
        }

        printf("\nDo You Want To Continue ? [Y/N] --> ");
        scanf(" %c", &con);

        if (con=='Y' || con=='y')
        {
            goto menu;
        }
        else
        {
            printf("\nThank You !");
            sleep(3);
            exit(0);
        }

    return 0;
}

//  Function Definition -->

void enqueue(queue **front, queue **rear)
{
    int val;
    queue *temp = *front;
    queue *new_node = (queue *)malloc(sizeof(queue));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated\n");
        return;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    if (*front == NULL)
    {
        new_node->data = val;
        new_node->next = *front;
        *front = new_node;
        *rear = new_node;
    }
    else
    {
        new_node->data = val;
        new_node->next = NULL;
        
        while ((temp)->next != NULL)
        {
            temp = (temp)->next;
        }

        (temp)->next = new_node;
        *rear = new_node;
    }
}

void dequeue(queue **front, queue **rear)
{
    queue *temp = *front;

    if (*front == NULL)
    {
        printf("\nQueue Is Empty !\n");
        return;
    }

    printf("\nDequeued Data --> %d\n", (*front)->data);

    *front = (*front)->next;
    free(temp);

    if (*front == NULL)
    {
        *rear = NULL;
    }
}

void disp(queue *front)
{
    if (front == NULL)
    {
        printf("\nQueue Is Empty !\n");
        return;
    }

    while (front != NULL)
    {
        printf("\nData --> %d", front->data);
        front = front->next;
    }

    printf("\n");
}

void peek(queue *front)
{
    if (front == NULL)
    {
        printf("\nQueue Is Empty !\n");
        return;
    }

    printf("\nData --> %d\n", front->data);
}

void node(queue *front)
{
    int node_count = 0;

    while (front != NULL)
    {
        front = front->next;
        node_count++;
    }

    printf("\nNodes In Queue --> %d\n", node_count);
}