/*
Commands:
gcc fcfs_scheduling.c -o fcfs
./fcfs
*/

#include <stdio.h>

int main() {
    int n = 5;
    int arrival[] = {0, 1, 2, 3, 4};
    int burst[] = {6, 4, 2, 3, 1};
    int waiting[5], turnaround[5], completion[5];

    completion[0] = arrival[0] + burst[0];
    turnaround[0] = completion[0] - arrival[0];
    waiting[0] = turnaround[0] - burst[0];

    for (int i = 1; i < n; i++) {
        if (completion[i - 1] < arrival[i])
            completion[i] = arrival[i] + burst[i];
        else
            completion[i] = completion[i - 1] + burst[i];

        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    float avg_wait = 0;

    printf("Process\tArrival\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], waiting[i], turnaround[i]);
        avg_wait += waiting[i];
    }

    avg_wait /= n;

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        printf("--P%d--|", i + 1);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wait);

    return 0;
}
