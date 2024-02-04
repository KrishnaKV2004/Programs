//  Structure For Round Robin --> Queue

typedef struct Node
{
    int Process_ID;
    int Burst_Time;
    struct Node *next;
} nd;

# define DASH 45

//  Function Declaration ---->

void menu();
void dash(int);
void new_line(int);
void ver_line(int);
void time_menu(int);

int process_counter(nd *);
nd * enqueue(nd *, int, int);
void view_processes(nd *, int);

//  Function Definition ---->

void dash(int dashes)
{
    int iteration;

    for (iteration = 1; iteration <= dashes; iteration ++)
    {
        printf("-");
    }
}

void new_line(int lines)
{
    int iteration;

    for (iteration = 1; iteration <= lines; iteration ++)
    {
        printf("\n");
    }
}

void ver_line(int ver_lines)
{
    int iteration;

    for (iteration = 1; iteration <= ver_lines; iteration ++)
    {
        printf("|\n");
    }
}

void menu()
{
    system("cls");

    printf("\n           ROUND ROBIN SCHEDULING           \n");
    dash(DASH);
    printf("\n KEY               OPERATIONS            \n");
    dash(DASH);
    printf("\n  T  |    Set Time Quantum For Processor              ");
    printf("\n  R  |    Register Processes In Processor             ");
    printf("\n  D  |    Delete A Process In Processor               ")
    printf("\n  V  |    View Processes In Processor                 ");
    printf("\n  S  |    Start Execution Of Processes                ");
    printf("\n  B  |    See Burst Time Of Processes                 ");
    printf("\n  K  |    Sort Processes Respect To Time              ");
    printf("\n  X  |    Delete All Processes In Queue               ");
    printf("\n  E  |    Exit Round Robin Scheduling                 ");
    new_line(1);
    dash(DASH);
    new_line(1);
}

void time_menu(int time_quantum)
{
    system("cls");
    printf("\n             ROUND ROBIN SCHEDULING         \n");
    new_line(1);
    dash(DASH);
    printf("\n                 OPERATIONS              \n");
    dash(DASH);
    new_line(1);
    printf("\n            Time Quantum --> %d      \n", time_quantum);
    printf("           Setting Time Quantum !       \n");
    sleep(1);
    new_line(1);
    printf("\n       Time Quantum Set Successfully !   \n");
    dash(DASH);
    new_line(2);
    sleep(3);
}

nd * enqueue(nd *head, int process_id, int burst_time)
{
    nd *temp = head;
    nd *newnode = (nd *)malloc(sizeof(nd));

    newnode->Process_ID = process_id;
    newnode->Burst_Time = burst_time;

    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;

        return head;
    }

    while (temp->next!=head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;

    return head;
}

nd * dequeue(nd *head, int process_id)
{
    nd *temp = head;

    while(temp->next!=NULL)
    {
        if (temp->Process_ID==process_id)
        {
            if (head->next == NULL)
            {
                
            }
        }
    }
}

void view_processes(nd *head, int process_count)
{
    int iterate;
    nd *temp = head;

    if (head == NULL)
    {
        printf("\nERROR --> Queue Is Empty !");
        return;
    }

    system("cls");
    printf("\n            ROUND ROBIN SCHEDULING          \n");
    dash(DASH);
    printf("\n                  PROCESSES              \n");
    dash(DASH);
    printf("\n         ID               BURST TIME        \n");
    dash(DASH);
    new_line(1);

    for (iterate = 1; iterate <= process_count; iterate ++)
    {
        printf("         %d                   %d", temp->Process_ID, temp->Burst_Time);
        new_line(1);
        temp = temp->next;
    }

    dash(DASH);
}

int process_counter(nd *head)
{
    int count = 1;
    nd *temp = head;

    while(temp->next!=head)
    {
        temp = temp->next;
        count ++;
    }

    return count;
}