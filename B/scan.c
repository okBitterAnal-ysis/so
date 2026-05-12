#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {

    for(int i=0;i<n;i++) {

        for(int j=i+1;j<n;j++) {

            if(arr[i] > arr[j]) {

                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int main() {

    int req[] = {176,79,34,60,92,11,41,114};

    int n = 8;

    int head = 50;

    int total = 0;

    sort(req, n);

    printf("SCAN Order: %d ", head);

    for(int i=0;i<n;i++) {

        if(req[i] >= head) {

            total += abs(head - req[i]);

            head = req[i];

            printf("-> %d ", head);
        }
    }

    total += abs(head - 199);

    head = 199;

    for(int i=n-1;i>=0;i--) {

        if(req[i] < 50) {

            total += abs(head - req[i]);

            head = req[i];

            printf("-> %d ", head);
        }
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
