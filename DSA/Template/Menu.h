//  Menu Template ---->

# define DASH 40

void menu();
void dash(int);
void new_line(int);

void dash(int dashes)
{
    int i;

    for (i=1; i<=dashes; i++)
    {
        printf("-");
    }
}

void new_line(int lines)
{
    int i;

    for (i=1; i<=lines; i++)
    {
        printf("\n");
    }
}

void menu()
{
    system("cls");

    printf("\n              LINKED LIST               \n");
    dash(DASH);
    printf("\n KEY              OPERATIONS            \n");
    dash(DASH);
    printf("\n  I  |              Insert              ");
    printf("\n  D  |              Delete              ");
    printf("\n  V  |            Print Data            ");
    printf("\n  N  |            View Nodes            ");
    printf("\n  M  |              Middle              ");
    printf("\n  S  |               Sort               ");
    printf("\n  R  |             Reversed             ");
    printf("\n  K  |              Rotate              ");
    printf("\n  E  |               Exit               ");
    new_line(1);
    dash(DASH);
}