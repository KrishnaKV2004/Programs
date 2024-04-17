//  Header Files ---->

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include "Round Robin.h"

//  Main Function ---->

int main()
{
    //  Variables ---->

    int iteration;
    int init_proccesses;
    int process_id;
    int burst_time;
    int time_quantum;
    int process_count;
    char operation_choice;

    nd * head = NULL;

    main_menu:

        system("cls");

        menu();

        printf("\nOperation To Perform --> ");
        scanf(" %c", &operation_choice);

        switch (operation_choice)
        {
            case 'T':
            case 't':
            
                time_menu:

                    system("cls");
                    printf("\n            ROUND ROBIN SCHEDULING          \n");
                    new_line(1);
                    dash(DASH);
                    printf("\n                 OPERATIONS              \n");
                    dash(DASH);
                    new_line(1);
                    printf("\n      Enter Time Quantum [1-20] --> ");
                    scanf("%d", &time_quantum);

                    if (time_quantum > 0 && time_quantum <= 20)
                    {
                        time_menu(time_quantum);
                        goto main_menu;
                    }

                    printf("\n        Time Quantum Out Of Range !");
                    sleep(2);
                    goto time_menu;

            case 'R':
            case 'r':

                register_menu:

                    system("cls");
                    printf("\n            ROUND ROBIN SCHEDULING          \n");
                    new_line(1);
                    dash(DASH);
                    printf("\n                 OPERATIONS              \n");
                    dash(DASH);
                    new_line(1);
                    printf("\n         Number Of Processes --> ");
                    
                    scanf("%d", &init_proccesses);

                    system("cls");
                    printf("\n            ROUND ROBIN SCHEDULING          \n");
                    new_line(1);
                    dash(DASH);
                    printf("\n                 OPERATIONS              \n");
                    dash(DASH);
                    new_line(2);
                    
                    for (iteration = 1; iteration <= init_proccesses; iteration ++)
                    {
                        printf("           Enter Process ID --> ");
                        scanf("%d", &process_id);
                        printf("           Enter Burst Time --> ");
                        scanf("%d", &burst_time);

                        head = enqueue(head, process_id, burst_time);
                        
                        new_line(1);
                    }

                    printf("\n           Processes Registered !\n");
                    new_line(1);
                    dash(DASH);

                    sleep(3);
                    goto main_menu;

            case 'V':
            case 'v':

                process_count = process_counter(head);
                view_processes(head, process_count);
                new_line(2);
                printf("\nPress Any Key To Continue --> ");
                getch();
                goto main_menu;

            case 'E':
            case 'e':

                printf("\nTERMINATING ROUND ROBIN !");
                sleep(2);
                exit(0);

            default:

                printf("\nINVALID OPEARTION !");
                sleep(2);
                goto main_menu;
        }

    return 0;
}