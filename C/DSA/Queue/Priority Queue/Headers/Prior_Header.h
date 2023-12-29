// Priority Queue Header Files -->

// Node Structure -->

typedef struct prior_queue
{
    int data;               //  To Store Value
    int priority;           //  To Store Priority
    struct prior_queue *next;      //  To Store Address Of Next Node
} prior_queue;

//  Function Declaration -->

prior_queue * enqueue(prior_queue *);       //  To Insert Data
prior_queue * dequeue(prior_queue *);       //  To Delete Data

void prior_queue_display(prior_queue *);    //  To Display Data In Queue

//  Function Definition -->

prior_queue * enqueue(prior_queue *head)
{
    int data_value;
    int prior_value;

    prior_queue *temp = head;
    prior_queue *newnode = (prior_queue *)malloc(sizeof(prior_queue));

    printf("\nEnter Data --> ");
    scanf("%d", &data_value);
    printf("\nEnter Priority Value --> ");
    scanf("%d", &prior_value);

    newnode->data = data_value;
    newnode->priority = prior_value;
    newnode->next = NULL;

    if (head == NULL || prior_value <= head->priority)
    {
        newnode->next = head;
        head = newnode;

        return head;
    }

    else
    {
        while (temp->next != NULL && temp->next->priority < prior_value)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;

        return head;
    }
}

prior_queue * dequeue(prior_queue *head)
{

}

void prior_queue_display(prior_queue *head)
{
    if (head == NULL)
    {
        printf("\nPriority Queue Is Empty !");
        return;
    }

    while (head != NULL)
    {
        printf("[%d | %d]  ",head->data, head->priority);
        head = head->next;
    }
}