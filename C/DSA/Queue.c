//  Queue ---->

//  Header Files ---->

#include <stdio.h>

#define MAX 10      //  Macro

//  Function Declaration ---->

int Enq(int [], int, int);
int Deq(int [], int, int);
void Disp(int [], int, int);
void Peek(int [], int);

//  Main Function ---->

int main()
{
    int ch;
    char con;
    int Front = -1, Rear = -1;
    int Queue[MAX];

    do
    {
        printf("\nEnter [1] To Enqueue");
        printf("\nEnter [2] To Dequeue");
        printf("\nEnter [3] To Display");
        printf("\nEnter [4] To Peek");
        printf("\n\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                Rear = Enq(Queue, Front, Rear);
                if (Front == -1)
                {
                    Front = 0;
                }
                break;

            case 2:
                Front = Deq(Queue, Front, Rear);
                break;

            case 3:
                Disp(Queue, Front, Rear);
                break;

            case 4:
                Peek(Queue, Front);
                break;

            default:
                printf("\nInvalid Input !");
                break;
        }

        printf("\nDo You Want To Continue? [Y/N]: ");
        scanf(" %c", &con);

    } while (con == 'Y' || con == 'y');
}

//  Function Definition ---->

int Enq(int Queue[], int Front, int Rear)
{
    int ins;

    if ((Rear + 1) % MAX == Front)
    {
        printf("\nQueue Is Full\n");
    }
    else
    {
        printf("\nInput Element: ");
        scanf("%d", &ins);

        Rear = (Rear + 1) % MAX;

        Queue[Rear] = ins;
    }

    return Rear;
}

int Deq(int Queue[], int Front, int Rear)
{
    if (Front == -1)
    {
        printf("\nQueue Is Empty\n");
    }
    else
    {
        printf("%d\n", Queue[Front]);
        if (Front == Rear)
        {
            Front = -1;
        }
        else
        {
            Front = (Front + 1) % MAX;
        }
    }

    return Front;
}

void Disp(int Queue[], int Front, int Rear)
{
    int tmp;

    if (Front == -1)
    {
        printf("\nQueue Is Empty\n");
    }
    else
    {
        tmp = Front;

        while (tmp != Rear)
        {
            printf("%d ", Queue[tmp]);
            tmp = (tmp + 1) % MAX;
        }
        printf("%d\n", Queue[tmp]);  // Print the last element
    }
}

void Peek(int Queue[], int Front)
{
    if (Front == -1)
    {
        printf("\nQueue Is Empty\n");
    }
    else
    {
        printf("%d", Queue[Front]);
    }
}