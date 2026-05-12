#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty, full, mutex;

void* producer(void* arg) {
    for(int i=1;i<=10;i++) {

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = i;
        printf("Produced %d\n", i);

        in = (in + 1) % SIZE;

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    }
}

void* consumer(void* arg) {
    int id = *(int*)arg;

    for(int i=0;i<3;i++) {

        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        printf("Consumer %d consumed %d\n", id, item);

        out = (out + 1) % SIZE;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(1);
    }
}

int main() {
    pthread_t p, c[3];
    int id[3] = {1,2,3};

    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);

    for(int i=0;i<3;i++)
        pthread_create(&c[i], NULL, consumer, &id[i]);

    pthread_join(p, NULL);

    for(int i=0;i<3;i++)
        pthread_join(c[i], NULL);

    return 0;
}
