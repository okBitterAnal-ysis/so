#include <stdio.h>

typedef struct {
    int pid;
    int bt;
    int pr;
    int wt;
    int tat;
} Process;

int main() {

    Process p[5] = {
        {1,4,2,0,0},
        {2,3,1,0,0},
        {3,5,3,0,0},
        {4,1,1,0,0},
        {5,2,4,0,0}
    };

    for(int i=0;i<5;i++) {

        for(int j=i+1;j<5;j++) {

            if(p[i].pr > p[j].pr) {

                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].wt = 0;

    for(int i=1;i<5;i++) {

        p[i].wt = p[i-1].wt + p[i-1].bt;
    }

    float avgwt = 0, avgtat = 0;

    printf("PID\tBT\tPR\tWT\tTAT\n");

    for(int i=0;i<5;i++) {

        p[i].tat = p[i].wt + p[i].bt;

        avgwt += p[i].wt;
        avgtat += p[i].tat;

        printf("P%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].bt,
            p[i].pr,
            p[i].wt,
            p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f\n", avgwt/5);
    printf("Average Turnaround Time = %.2f\n", avgtat/5);

    return 0;
}
