/*
Commands:
gcc race_condition_mutex.c -o race -lpthread
./race
*/

#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment_without_mutex(void* arg) {
    for (int i = 0; i < 5000; i++) {
        counter++;
    }
    pthread_exit(NULL);
}

void* increment_with_mutex(void* arg) {
    for (int i = 0; i < 5000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    printf("Without Mutex:\n");

    counter = 0;

    pthread_create(&t1, NULL, increment_without_mutex, NULL);
    pthread_create(&t2, NULL, increment_without_mutex, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Counter = %d\n", counter);

    printf("\nWith Mutex:\n");

    counter = 0;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment_with_mutex, NULL);
    pthread_create(&t2, NULL, increment_with_mutex, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Counter = %d\n", counter);

    pthread_mutex_destroy(&lock);

    return 0;
}
