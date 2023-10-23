//  Linked List ---->

#include <stdio.h>
#include <stdlib.h>

//  Node Structure ---->
typedef struct list
{
    int data;
    struct list *next;
} ls;

//  Function Declaration ---->

ls* insert(ls *head);
ls* delete(ls *head);
void view(ls *head);

//  Main Function ---->

int main()
{
    ls *head = NULL;
    char ch, con;

menu:

    printf("\nEnter [I] To Insert Element");
    printf("\nEnter [D] To Delete Element");
    printf("\nEnter [V] To View Elements");
    printf("\n\nEnter Choice : ");
    scanf(" %c", &ch);

    switch (ch) 
    {
        case 'I':
        case 'i':
            head = insert(head);
            break;

        case 'D':
        case 'd':
            head = delete(head);
            break;

        case 'V':
        case 'v':
            view(head);
            break;

        default:
            printf("\nInvalid Input !");
            break;
    }

    printf("\nDo You Want To Continue ? [Y/N] : ");
    scanf(" %c", &con);

    if (con == 'y' || con == 'Y')
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

ls* insert(ls *head)
{
    int val;
    printf("\nEnter Value : ");
    scanf("%d", &val);
 
    ls *newNode = (ls *)malloc(sizeof(ls));
    if (newNode == NULL)
    {
        printf("\nMemory Not Allocated !\n");
        return head;
    }

    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ls *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

ls* delete(ls *head)
{
    return head;
}

void view(ls *head)
{
    if (head == NULL)
    {
        printf("\nNo Data To Display !\n");
    }
    else
    {
        printf("\nElements in the list : ");
        ls *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}