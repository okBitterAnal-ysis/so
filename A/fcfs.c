#include <stdio.h>

int main() {
    int arrival[] = {0,1,2,3,4};
    int burst[] = {6,4,2,3,1};

    int wt[5], tat[5];

    wt[0] = 0;

    for(int i=1;i<5;i++) {
        wt[i] = wt[i-1] + burst[i-1] - arrival[i] + arrival[i-1];

        if(wt[i] < 0)
            wt[i] = 0;
    }

    float avg = 0;

    printf("Process\tWT\tTAT\n");

    for(int i=0;i<5;i++) {
        tat[i] = wt[i] + burst[i];
        avg += wt[i];

        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);
    }

    printf("\nGantt Chart:\n|");

    for(int i=0;i<5;i++) {
        for(int j=0;j<burst[i];j++)
            printf("--");
        printf("P%d|", i+1);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg/5);

    return 0;
}
