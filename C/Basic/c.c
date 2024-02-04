# include<stdio.h>
# include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insrt_beg(struct node* head)
{
    struct node* nwnode;

    if (nwnode == NULL)
    {
        printf("\nMemory Not Allocated !");
    }
    int da;
    printf("ENTER AN ELEMENT: ");
    scanf("%d", &da);

    nwnode-> data = da;

    nwnode->next = head;
    head = nwnode;

    return head;
}

struct node* create(struct node* h, struct node* p)
{   
    int element;
    printf("\n*ENTER (-1) TO STOP THE CREATION OF LINKED LIST*\n\n");
    printf("ENTER THE ELEMENT:");
    scanf("%d", &element);
    while(element != -1)
    {
        struct node* nwnode;
        nwnode = (struct node*)malloc(sizeof(struct node));

        nwnode->data = element;
        nwnode->next = NULL;

        if(h == NULL)
        {
            h = nwnode;
            p = nwnode;
        }

        else
        {
            p->next = nwnode;
            p = p->next;
        }

        printf("ENTER THE ELEMENTS:\n");
        scanf("%d", &element);
    }

    return h;
}

void traverse(struct node* z)
{
    while(z != NULL)
    {
        printf("ELEMENT: %d\n", z->data);
        z = z->next;
    }
}

void main()
{
    struct node* head, *ptr;

    head = (struct node*)malloc(sizeof(struct node));
    ptr = (struct node*)malloc(sizeof(struct node));

    head = NULL;
    ptr = NULL;

    head = create(head, ptr);
    
    printf("LINKED LIST: \n");
    traverse(head);

    int I;
    printf("\nENTER (1) TO INSERT AN ELEMENT AT BEGINING OF THE LINKED LIST\nENTER (0) TO NOT INSERT AN ELEMENT AT BEGINING OF THE LINKED LIST\n");
    printf("I: ");
    scanf("%d", &I);

    if(I == 1)
    {
        head = insrt_beg(head);
        printf("NOW YOUR LINKED LIST IS: \n");
        traverse(head);
    }
    else if(I == 0)
    {
        printf("\nINSERTION AT BEGINING IS NOT PERFORMED.\n");
        printf("\nYOUR LINKED LIST IS: \n");

        traverse(head);
    }
}