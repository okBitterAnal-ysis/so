#include <stdio.h>
#include <pthread.h>

int arr[100];
int partial[4];

typedef struct {
    int start;
    int end;
    int thread_no;
} Data;

void* calculate(void* arg) {
    Data* d = (Data*)arg;
    int sum = 0;

    for (int i = d->start; i < d->end; i++) {
        sum += arr[i];
    }

    partial[d->thread_no] = sum;

    pthread_exit(0);
}

int main() {
    pthread_t threads[4];
    Data data[4];

    for (int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 4; i++) {
        data[i].start = i * 25;
        data[i].end = (i + 1) * 25;
        data[i].thread_no = i;

        pthread_create(&threads[i], NULL, calculate, &data[i]);
    }

    int total = 0;

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
        total += partial[i];
    }

    printf("Total Sum = %d\n", total);

    return 0;
}
