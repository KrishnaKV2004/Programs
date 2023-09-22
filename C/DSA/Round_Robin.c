#include <stdio.h>
#include <stdlib.h>

struct Process {
    int process_id;
    int burst_time;
    struct Process* next;
};

typedef struct Process Process;

void enqueue(Process** rear, int process_id, int burst_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->burst_time = burst_time;
    new_process->next = NULL;

    if (*rear == NULL) {
        *rear = new_process;
        (*rear)->next = *rear;
    } else {
        new_process->next = (*rear)->next;
        (*rear)->next = new_process;
        *rear = new_process;
    }
}

Process* dequeue(Process** rear) {
    if (*rear == NULL) {
        return NULL;
    }

    Process* front = (*rear)->next;
    if (front->next == front) {
        *rear = NULL;
    } else {
        (*rear)->next = front->next;
    }
    
    return front;
}

void roundRobin(Process* rear, int time_quantum) {
    if (rear == NULL) {
        printf("No processes to schedule.\n");
        return;
    }

    Process* current = rear->next;
    while (1) {
        if (current->burst_time <= time_quantum) {
            printf("Process %d is executing for %d units.\n", current->process_id, current->burst_time);
            current->burst_time = 0;
        } else {
            printf("Process %d is executing for %d units.\n", current->process_id, time_quantum);
            current->burst_time -= time_quantum;
        }

        if (current->burst_time == 0) {
            Process* temp = current;
            current = current->next;
            if (temp == rear) {
                rear = NULL;
            }
            free(temp);
        } else {
            current = current->next;
        }

        if (rear == NULL) {
            break;
        }
    }
}

int main() {
    Process* rear = NULL;
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    for (int i = 1; i <= n; i++) {
        int burst_time;
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &burst_time);
        enqueue(&rear, i, burst_time);
    }

    roundRobin(rear, time_quantum);

    return 0;
}