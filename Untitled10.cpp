#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burstTime;
    struct Process* next;
};

struct Process* createProcess(int id, int burstTime) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->id = id;
    newProcess->burstTime = burstTime;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(struct Process** head, int id, int burstTime) {
    struct Process* newProcess = createProcess(id, burstTime);
    if (*head == NULL) {
        *head = newProcess;
        newProcess->next = *head;
    } else {
        struct Process* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newProcess;
        newProcess->next = *head;
    }
} // Added missing closing brace

void timeSharing(struct Process* head, int timeSlice) {
    if (head == NULL) {
        printf("No processes to execute.\n");
        return;
    }
    struct Process* current = head;
    int remainingTime;
    do {
        printf("Executing process %d for %d ms.\n", current->id, timeSlice);
        remainingTime = current->burstTime - timeSlice;
        if (remainingTime <= 0) {
            printf("Process %d completed.\n", current->id);
            struct Process* temp = current->next;
            while (temp->next != current) {
                temp = temp->next;
            }
            temp->next = current->next;
            free(current);
            current = temp->next;
        } else {
            current->burstTime = remainingTime;
            current = current->next;
        }
    } while (current != head);
} 

int main() {
    struct Process* processes = NULL;
    int numProcesses, timeSlice;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("Enter the time slice for each process (in ms): ");
    scanf("%d", &timeSlice);
    for (int i = 1; i <= numProcesses; ++i) {
        int burstTime;
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &burstTime);
        addProcess(&processes, i, burstTime);
    }
    timeSharing(processes, timeSlice);
    return 0;
}

