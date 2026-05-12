/*
Commands:
gcc priority_scheduling.c -o priority
./priority
*/

#include <stdio.h>

typedef struct {
    int pid;
    int burst;
    int priority;
    int waiting;
    int turnaround;
} Process;

int main() {
    Process p[5] = {
        {1, 4, 2},
        {2, 3, 1},
        {3, 5, 3},
        {4, 1, 1},
        {5, 2, 4}
    };

    for (int i = 0; i < 5 - 1; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (p[i].priority > p[j].priority) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].waiting = 0;
    p[0].turnaround = p[0].burst;

    for (int i = 1; i < 5; i++) {
        p[i].waiting = p[i - 1].waiting + p[i - 1].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    float avgWT = 0, avgTAT = 0;

    printf("PID\tBurst\tPriority\tWaiting\tTurnaround\n");

    for (int i = 0; i < 5; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid, p[i].burst, p[i].priority,
               p[i].waiting, p[i].turnaround);

        avgWT += p[i].waiting;
        avgTAT += p[i].turnaround;
    }

    printf("\nAverage Waiting Time = %.2f\n", avgWT / 5);
    printf("Average Turnaround Time = %.2f\n", avgTAT / 5);

    return 0;
}
