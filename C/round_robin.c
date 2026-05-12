#include <stdio.h>

int main() {
    int bt[] = {10,4,6,3};
    int rem[] = {10,4,6,3};
    int n = 4;
    int quantum = 3;
    int time = 0;
    int complete = 0;
    int ct[4];

    while(complete < n) {
        for(int i=0;i<n;i++) {
            if(rem[i] > 0) {
                if(rem[i] > quantum) {
                    time += quantum;
                    rem[i] -= quantum;
                } else {
                    time += rem[i];
                    ct[i] = time;
                    rem[i] = 0;
                    complete++;
                }
            }
        }
    }

    float avg = 0;

    printf("Job\tCompletion Time\tTurnaround Time\n");

    for(int i=0;i<n;i++) {
        avg += ct[i];
        printf("J%d\t%d\t\t%d\n", i+1, ct[i], ct[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", avg/n);

    return 0;
}
