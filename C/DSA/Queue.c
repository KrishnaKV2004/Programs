#include <stdio.h>

# define MAX 10

int Enq(int [], int, int);
int Deq(int [], int, int);
void Disp(int [], int, int);
void Peek(int [], int, int);

int main()
{
    int ch, con;
    int Front = -1, Rear = -1;
    int Queue[MAX];

    menu:
    
        printf("\nEnter [1] To Enqueue");
        printf("\nEnter [2] To Dequeue");
        printf("\nEnter [3] To Display");
        printf("\nEnter [4] To Peek");
        printf("\n\nEnter Choice : ");
        scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        Rear = Enq(Queue, Front, Rear);

        if (Front==-1)
        {
            Front++;
        }

        break;

    case 2:
        Front = Deq(Queue, Front, Rear);
        break;
    
    case 3:
        Disp(Queue, Front, Rear);
        break;

    case 4:
        Peek(Queue, Front, Rear);
        break;

    default:
        printf("\nInvalid Input !");
        break;
    }

    printf("Do You Want To Continue ? [Y/N] : ");
    scanf(" %c",&con);

    if (con=='Y' || con=='y')
    {
        goto menu;
    }
}

int Enq(int Queue[], int Front, int Rear)
{
    int ins;

    if ((Rear+1)%MAX==Front)
    {
        printf("\nQueue Is Full");
    }
    else
    {
        printf("\nInput Element : ");
        scanf("%d",&ins);

        Rear = (Rear+1)%MAX;

        Queue[Rear] = ins;
    }
}

int Deq(int Queue[], int Front, int Rear)
{
    if (Front==-1)
    {
        printf("\nQueue Is Empty\n");
    }
    else
    {
        printf("%d",Queue[Front]);
        Front = (Front+1)%MAX;
    }
}

void Disp(int Queue[], int Front, int Rear)
{
    int tmp;

    if (Front==-1)
    {
        printf("\nQueue Is Empty\n");
    }
    else
    {
        tmp = Front;

        while (tmp!=Rear)
        {
            printf("%d ",Queue[tmp]);
            tmp = (temp+1)%MAX;
            printf("%d",Queue[tmp]);
        }
    }
}

void Peek(int Queue[], int Front, int Rear)
{
    if (Front==-1)
    {
        printf("\nQueue Is Empty\n");
    }
    else
    {
        printf("%d",Queue[Front]);
    }
}