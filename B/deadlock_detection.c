/*
Commands:
gcc deadlock_detection.c -o deadlock
./deadlock
*/

#include <stdio.h>

int main() {
    int allocation[3][2] = {
        {1, 0},
        {0, 1},
        {1, 1}
    };

    int request[3][2] = {
        {0, 1},
        {1, 0},
        {1, 1}
    };

    int available[2] = {0, 0};

    int finish[3] = {0};

    int changed;

    do {
        changed = 0;

        for (int i = 0; i < 3; i++) {
            if (!finish[i]) {
                int canFinish = 1;

                for (int j = 0; j < 2; j++) {
                    if (request[i][j] > available[j]) {
                        canFinish = 0;
                        break;
                    }
                }

                if (canFinish) {
                    for (int j = 0; j < 2; j++) {
                        available[j] += allocation[i][j];
                    }

                    finish[i] = 1;
                    changed = 1;
                }
            }
        }

    } while (changed);

    int deadlock = 0;

    for (int i = 0; i < 3; i++) {
        if (!finish[i]) {
            deadlock = 1;
        }
    }

    if (deadlock) {
        printf("Processes involved in deadlock: ");
        for (int i = 0; i < 3; i++) {
            if (!finish[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("No deadlock detected\n");
    }

    return 0;
}
