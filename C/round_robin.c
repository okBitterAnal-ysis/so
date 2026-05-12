/*
Commands:
gcc round_robin.c -o rr
./rr
*/

#include <stdio.h>

int main() {
    int bt[] = {10, 4, 6, 3};
    int rt[] = {10, 4, 6, 3};
    int ct[4];
    int tq = 3;
    int time = 0;
    int done;

    do {
        done = 1;

        for (int i = 0; i < 4; i++) {
            if (rt[i] > 0) {
                done = 0;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                }
            }
        }

    } while (!done);

    float avg = 0;

    for (int i = 0; i < 4; i++) {
        printf("J%d Completion Time = %d\n", i + 1, ct[i]);
        avg += ct[i];
    }

    printf("\nAverage Turnaround Time = %.2f\n", avg / 4);

    return 0;
}
