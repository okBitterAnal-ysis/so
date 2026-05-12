/*
Commands:
gcc shared_memory_counter.c -o shmcounter
./shmcounter
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <semaphore.h>

typedef struct {
    int counter;
    sem_t mutex;
} SharedData;

int main() {
    int shmid = shmget(IPC_PRIVATE, sizeof(SharedData), IPC_CREAT | 0666);

    SharedData *data = (SharedData*)shmat(shmid, NULL, 0);

    data->counter = 0;

    sem_init(&data->mutex, 1, 1);

    pid_t pid = fork();

    if (pid == 0) {
        for (int i = 0; i < 10; i++) {
            sem_wait(&data->mutex);
            printf("Reader: Counter = %d\n", data->counter);
            sem_post(&data->mutex);

            sleep(1);
        }
    } else {
        for (int i = 0; i < 10; i++) {
            sem_wait(&data->mutex);
            data->counter++;
            printf("Writer incremented counter to %d\n", data->counter);
            sem_post(&data->mutex);

            sleep(1);
        }

        wait(NULL);

        sem_destroy(&data->mutex);
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
