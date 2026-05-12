/*
Commands:
gcc cscan_disk.c -o cscan
./cscan
*/

#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int main() {
    int req[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};
    int n = 9;
    int head = 100;
    int total = 0;
    int current = head;

    sort(req, n);

    printf("C-SCAN Service Order:\n");

    for (int i = n - 1; i >= 0; i--) {
        if (req[i] <= head) {
            total += abs(current - req[i]);
            current = req[i];
            printf("%d ", current);
        }
    }

    total += abs(current - 0);
    current = 199;

    printf("-> Jump to 199 -> ");

    total += 199;

    for (int i = n - 1; i >= 0; i--) {
        if (req[i] > head) {
            total += abs(current - req[i]);
            current = req[i];
            printf("%d ", current);
        }
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
