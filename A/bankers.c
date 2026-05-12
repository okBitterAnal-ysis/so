#include <stdio.h>

int main() {
    int allocation[4][2] = {
        {1,0},
        {2,1},
        {1,1},
        {0,2}
    };

    int max[4][2] = {
        {3,2},
        {2,2},
        {1,3},
        {1,2}
    };

    int available[2] = {1,1};

    int need[4][2];
    int finish[4] = {0};
    int safe[4];
    int count = 0;

    for(int i=0;i<4;i++) {
        for(int j=0;j<2;j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    while(count < 4) {
        int found = 0;

        for(int i=0;i<4;i++) {
            if(!finish[i]) {
                int possible = 1;

                for(int j=0;j<2;j++) {
                    if(need[i][j] > available[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {
                    for(int j=0;j<2;j++)
                        available[j] += allocation[i][j];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found)
            break;
    }

    if(count == 4) {
        printf("Safe sequence: ");
        for(int i=0;i<4;i++)
            printf("P%d ", safe[i]);
    }
    else {
        printf("System is in deadlock");
    }

    return 0;
}
