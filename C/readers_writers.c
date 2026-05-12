/*
Commands:
gcc readers_writers.c -o rw -lpthread
./rw
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, write_lock;
int reader_count = 0;

void* reader(void* arg) {
    int id = *(int*)arg;

    for (int i = 0; i < 3; i++) {
        sem_wait(&mutex);

        reader_count++;

        if (reader_count == 1)
            sem_wait(&write_lock);

        sem_post(&mutex);

        printf("Reader %d is reading\n", id);

        sleep(1);

        sem_wait(&mutex);

        reader_count--;

        if (reader_count == 0)
            sem_post(&write_lock);

        sem_post(&mutex);

        sleep(1);
    }

    pthread_exit(NULL);
}

void* writer(void* arg) {
    for (int i = 0; i < 3; i++) {
        sem_wait(&write_lock);

        printf("Writer is writing\n");

        sleep(1);

        sem_post(&write_lock);

        sleep(1);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t r1, r2, w;
    int id1 = 1, id2 = 2;

    sem_init(&mutex, 0, 1);
    sem_init(&write_lock, 0, 1);

    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&r2, NULL, reader, &id2);
    pthread_create(&w, NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w, NULL);

    sem_destroy(&mutex);
    sem_destroy(&write_lock);

    return 0;
}
