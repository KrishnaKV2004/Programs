#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

/* Reverses alternate k nodes and
returns the pointer to the new head node */
struct Node* kAltReverse(struct Node* head, int k)
{
    struct Node* current = head;
    struct Node* next;
    struct Node* prev = NULL;
    int count = 0;

    /* 1) reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    /* 2) Now head points to the kth node.
    So change next of head to (k+1)th node*/
    if (head != NULL)
        head->next = current;

    /* 3) We do not want to reverse next k
    nodes. So move the current pointer to skip next k nodes */
    count = 0;
    while (count < k - 1 && current != NULL)
    {
        current = current->next;
        count++;
    }

    /* 4) Recursively call for the list
    starting from current->next. And make
    rest of the list as next of the first node */
    if (current != NULL)
        current->next = kAltReverse(current->next, k);

    /* 5) prev is the new head of the input list */
    return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list of the new node */
    new_node->next = (*head_ref);    

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node* node)
{
    int count = 0;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
        count++;
    }
}

/* Driver code */
int main(void)
{
    /* Start with the empty list */
    struct Node* head = NULL;
    int i;

    // create a list 1->2->3->4->5...... ->20
    for (i = 20; i > 0; i--)
        push(&head, i);

    printf("Given linked list:\n");
    printList(head);
    head = kAltReverse(head, 3);

    printf("\nModified Linked list:\n");
    printList(head);

    return 0;
}
