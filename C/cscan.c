#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
}

int main() {
    int req[] = {55,58,39,18,90,160,150,38,184};
    int n = 9;
    int head = 100;
    int total = 0;

    sort(req, n);

    printf("C-SCAN Order: %d ", head);

    for(int i=n-1;i>=0;i--) {
        if(req[i] <= head) {
            total += abs(head - req[i]);
            head = req[i];
            printf("-> %d ", head);
        }
    }

    total += head;
    printf("-> 0 ");
    head = 199;
    total += 199;
    printf("-> 199 ");

    for(int i=n-1;i>=0;i--) {
        if(req[i] > 100) {
            total += abs(head - req[i]);
            head = req[i];
            printf("-> %d ", head);
        }
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
