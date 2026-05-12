/*
Commands:
gcc bankers_algorithm.c -o banker
./banker
*/

#include <stdio.h>

int main() {
    int allocation[4][2] = {
        {1, 0},
        {2, 1},
        {1, 1},
        {0, 2}
    };

    int max[4][2] = {
        {3, 2},
        {2, 2},
        {1, 3},
        {1, 2}
    };

    int available[2] = {1, 1};

    int need[4][2];
    int finish[4] = {0};
    int safeSeq[4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int count = 0;

    while (count < 4) {
        int found = 0;

        for (int i = 0; i < 4; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < 2; j++) {
                    if (need[i][j] > available[j])
                        break;
                }

                if (j == 2) {
                    for (int k = 0; k < 2; k++) {
                        available[k] += allocation[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("System is in deadlock\n");
            return 0;
        }
    }

    printf("Safe sequence: ");
    for (int i = 0; i < 4; i++) {
        printf("P%d ", safeSeq[i]);
    }

    printf("\n");

    return 0;
}
