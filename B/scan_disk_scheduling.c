/*
Commands:
gcc scan_disk_scheduling.c -o scan
./scan
*/

#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = 8;
    int head = 50;

    sort(requests, n);

    int total = 0;
    int current = head;

    printf("SCAN Service Order:\n");

    for (int i = 0; i < n; i++) {
        if (requests[i] >= head) {
            total += abs(current - requests[i]);
            current = requests[i];
            printf("%d ", current);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (requests[i] < head) {
            total += abs(current - requests[i]);
            current = requests[i];
            printf("%d ", current);
        }
    }

    printf("\nTotal Head Movement (SCAN) = %d\n", total);

    int fcfs[] = {176, 79, 34, 60, 92, 11, 41, 114};
    current = head;
    int fcfsTotal = 0;

    for (int i = 0; i < n; i++) {
        fcfsTotal += abs(current - fcfs[i]);
        current = fcfs[i];
    }

    printf("Total Head Movement (FCFS) = %d\n", fcfsTotal);

    return 0;
}
