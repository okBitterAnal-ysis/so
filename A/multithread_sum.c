/*
Commands:
gcc multithread_sum.c -o multithread_sum -lpthread
./multithread_sum
*/

#include <stdio.h>
#include <pthread.h>

int arr[100];
int partial_sum[4];

typedef struct {
    int start;
    int end;
    int thread_no;
} ThreadData;

void* calculate_sum(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int sum = 0;

    for (int i = data->start; i < data->end; i++) {
        sum += arr[i];
    }

    partial_sum[data->thread_no] = sum;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    ThreadData data[4];

    for (int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 4; i++) {
        data[i].start = i * 25;
        data[i].end = (i + 1) * 25;
        data[i].thread_no = i;

        pthread_create(&threads[i], NULL, calculate_sum, &data[i]);
    }

    int total = 0;

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
        total += partial_sum[i];
    }

    printf("Total Sum = %d\n", total);

    return 0;
}
