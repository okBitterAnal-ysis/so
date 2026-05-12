/*
Commands:
gcc sstf_disk_scheduling.c -o sstf
./sstf
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int visited[8] = {0};
    int head = 53;
    int total = 0;

    printf("Order of servicing:\n");

    for (int i = 0; i < 8; i++) {
        int min = 10000;
        int index = -1;

        for (int j = 0; j < 8; j++) {
            if (!visited[j]) {
                int distance = abs(head - requests[j]);

                if (distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total += abs(head - requests[index]);
        head = requests[index];

        printf("%d ", head);
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
