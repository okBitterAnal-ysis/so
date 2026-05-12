/*
Commands:
gcc bankers_request.c -o banker
./banker
*/

#include <stdio.h>

int main() {
    int allocation[4][3] = {
        {1, 1, 0},
        {1, 0, 2},
        {1, 3, 5},
        {0, 2, 1}
    };

    int max[4][3] = {
        {3, 2, 2},
        {2, 1, 3},
        {3, 3, 5},
        {1, 2, 2}
    };

    int available[3] = {2, 1, 2};

    int request[3] = {1, 0, 2};

    int need[4][3];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int vm = 1;

    for (int j = 0; j < 3; j++) {
        if (request[j] > need[vm][j] || request[j] > available[j]) {
            printf("Request denied\n");
            return 0;
        }
    }

    for (int j = 0; j < 3; j++) {
        available[j] -= request[j];
        allocation[vm][j] += request[j];
        need[vm][j] -= request[j];
    }

    int finish[4] = {0};
    int safe[4];
    int count = 0;

    while (count < 4) {
        int found = 0;

        for (int i = 0; i < 4; i++) {
            if (!finish[i]) {
                int j;

                for (j = 0; j < 3; j++) {
                    if (need[i][j] > available[j])
                        break;
                }

                if (j == 3) {
                    for (int k = 0; k < 3; k++) {
                        available[k] += allocation[i][k];
                    }

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("Request denied\n");
            return 0;
        }
    }

    printf("Request granted\nSafe sequence: ");

    for (int i = 0; i < 4; i++) {
        printf("VM%d ", safe[i]);
    }

    printf("\n");

    return 0;
}
