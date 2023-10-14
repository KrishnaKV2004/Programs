//  To Implement Stack Using Linked List ---->

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

//  Structure Of Node -->

typedef struct Node
{
    int data;
    struct Node *next;
} stack;

//  Function Declaration -->

void peek(stack *);         //  To Display Top Element Of Stack
void disp(stack *);         //  To Display Elements Of Stack
stack* pop(stack *);       //  To Pop Element From Stack
stack* push(stack *);      //  To Push Element In Stack

//  Main Function -->

int main()
{
    int node_count;
    char con, choice;
    stack *top = NULL;

    menu :
        system("cls");
        printf("\n# ------ STACK ------ #\n");
        printf("\nOperations ---->\n");
        printf("\n[I] To Push");
        printf("\n[D] To Pop");
        printf("\n[P] To Peek");
        printf("\n[V] To Display");
        printf("\n[N] To Count Nodes");
        printf("\n\nChoose Operation ----> ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'I' :
        case 'i' :
            top = push(top);
            break;
        
        case 'D' :
        case 'd' :
            top = pop(top);
            break;

        case 'P' :
        case 'p' :
            peek(top);
            break;

        case 'V' :
        case 'v' :
            disp(top);
            break;

        default:
            printf("\nInvalid Operation !\n");
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

stack* push(stack *top)
{
    int val;
    stack *new_node = (stack *)malloc(sizeof(stack));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated\n");
        return top;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    new_node->data = val;
    new_node->next = top;
    top = new_node;

    return top;
}

stack* pop(stack *top)
{

}

void disp(stack *top)
{
    if (top == NULL)
    {
        printf("\nStack Is Empty !\n");
        return;
    }

    while (top!=NULL)
    {
        printf("\nData --> %d", top->data);
        top = top->next;
    }

    printf("\n");
}

void peek(stack *top)
{

}