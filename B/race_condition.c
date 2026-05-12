#include <stdio.h>
#include <pthread.h>

int counter = 0;

pthread_mutex_t lock;

void* increment_without_mutex(void* arg) {

    for(int i=0;i<5000;i++) {
        counter++;
    }

    return NULL;
}

void* increment_with_mutex(void* arg) {

    for(int i=0;i<5000;i++) {

        pthread_mutex_lock(&lock);

        counter++;

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {

    pthread_t t1, t2;

    printf("WITHOUT MUTEX\n");

    counter = 0;

    pthread_create(&t1, NULL, increment_without_mutex, NULL);
    pthread_create(&t2, NULL, increment_without_mutex, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter = %d\n\n", counter);

    printf("WITH MUTEX\n");

    counter = 0;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment_with_mutex, NULL);
    pthread_create(&t2, NULL, increment_with_mutex, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter = %d\n", counter);

    pthread_mutex_destroy(&lock);

    return 0;
}
