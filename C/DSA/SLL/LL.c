#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} nd;

nd * insert(nd *);
nd * split(nd *, nd *);
void display(nd *);

int main()
{
    int choice;
    nd *head = NULL;
    nd *spl = NULL;

    while(1)
    {
        printf("\n1 To Insert Elements");
        printf("\n2 To Split Linked List");
        printf("\n3 To Display Linked List");
        printf("\n4 To Exit The Program");
        printf("\n\nEnter Choice --> ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            head = insert(head);
        }

        if (choice == 2)
        {
            spl = split(head, spl);
        }

        if (choice == 3)
        {
            printf("\nLinked List 1\n\n");
            display(head);
            printf("\nLinked List 2\n\n");
            display(spl);
        }

        if (choice == 4)
        {
            exit(0);
        }
    }

    return 0;
}

nd * insert(nd *head)
{
    int value;

    printf("\nEnter Data --> ");
    scanf("%d", &value);

    nd *newnode = (nd *)malloc(sizeof(nd));

    if (head == NULL)
    {
        newnode->data = value;
        newnode->next = NULL;
        head = newnode;
        return head;
    }

    newnode->data = value;
    newnode->next = head;
    head = newnode;

    return head;
}

nd * split(nd *head, nd *spl)
{
    int iterate;
    int splitValue;

    nd *temp = head;
    nd *splitted = head;

    printf("\nEnter Split value --> ");
    scanf("%d", &splitValue);

    for(iterate=1;iterate<splitValue;iterate++)
    {
        temp = temp->next;
    }

    splitted = temp->next;
    temp->next = NULL;

    return splitted;
}

void display(nd *head)
{
    nd *temp = head;

    while(temp!=NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}