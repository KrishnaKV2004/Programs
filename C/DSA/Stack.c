#include <stdio.h>

# define MAX 10

void Push(int [], int *);
void Pop(int [], int *);
void Disp(int [], int);
void Peek(int [], int);

void main()
{
    int ch, con, Top = -1;
    int Stack[MAX];

    menu:

        printf("\nThis Is A Stack -->\n");
        printf("\nEnter [1] To Push");
        printf("\nEnter [2] To Pop");
        printf("\nEnter [3] To Display");
        printf("\nEnter [4] To Peek\n");
        printf("\nEnter Choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            Push(Stack, &Top);
            break;

        case 2:
            Pop(Stack, &Top);
            break;

        case 3:
            Disp(Stack, Top);
            break;

        case 4:
            Peek(Stack,Top);
            break;
        
        default:
            printf("\nInvalid Choice !");
            break;
        }

    printf("\nDo You Want To Continue ? [Y/N] : ");
    scanf(" %c",&con);

    if (con == 'Y' || con == 'y')
    {
        goto menu;
    }
}

void Push(int Stack[], int *Top)
{
    if (*Top == MAX-1)
    {
        printf("\nStack Overflow");
    }

    int num;

    printf("\nEnter Number To Push : ");
    scanf("%d",&num);

    (*Top)++;

    Stack[*Top] = num;
}

void Pop(int Stack[], int *Top)
{
    if (*Top == -1)
    {
        printf("\nStack Underflow");
    }

    printf("%d",Stack[*Top]);
    (*Top)--;
}

void Disp(int Stack[], int Top)
{
    int i;

    if (Top == -1)
    {
        printf("\nStack Underflow");
    }

    printf("\n");

    for (i=Top; i>-1; i--)
    {
        printf("%d ",Stack[i]);
    }

    printf("\n");
}

void Peek(int Stack[], int Top)
{
    if (Top == -1)
    {
        printf("\nStack Underflow");
    }

    printf("\n%d",Stack[Top]);
}