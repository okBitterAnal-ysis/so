#include <stdio.h>

int main() {
    int allocation[4][3] = {
        {1,1,0},
        {1,0,1},
        {1,3,5},
        {0,2,1}
    };

    int max[4][3] = {
        {3,2,2},
        {2,1,3},
        {1,4,6},
        {1,3,2}
    };

    int available[3] = {2,1,1};
    int request[3] = {1,0,2};
    int need[4][3];

    for(int i=0;i<4;i++)
        for(int j=0;j<3;j++)
            need[i][j] = max[i][j] - allocation[i][j];

    int valid = 1;

    for(int j=0;j<3;j++)
        if(request[j] > need[1][j] || request[j] > available[j])
            valid = 0;

    if(!valid) {
        printf("Request denied\n");
        return 0;
    }

    for(int j=0;j<3;j++) {
        available[j] -= request[j];
        allocation[1][j] += request[j];
        need[1][j] -= request[j];
    }

    int finish[4] = {0};
    int safe[4];
    int count = 0;

    while(count < 4) {
        int found = 0;
        for(int i=0;i<4;i++) {
            if(!finish[i]) {
                int possible = 1;
                for(int j=0;j<3;j++) {
                    if(need[i][j] > available[j]) {
                        possible = 0;
                        break;
                    }
                }
                if(possible) {
                    for(int j=0;j<3;j++)
                        available[j] += allocation[i][j];

                    finish[i] = 1;
                    safe[count++] = i;
                    found = 1;
                }
            }
        }
        if(!found) break;
    }

    if(count == 4) {
        printf("Request granted\nSafe Sequence: ");
        for(int i=0;i<4;i++)
            printf("P%d ", safe[i]);
    } else {
        printf("Request denied");
    }

    return 0;
}
