/*
Commands:
gcc producer_shared_memory.c -o producer
gcc consumer_shared_memory.c -o consumer
./producer
./consumer
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

int main() {
    key_t key = 1234;

    int shmid = shmget(key, sizeof(int) * 5, 0666);

    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    int *data = (int*)shmat(shmid, NULL, 0);

    printf("Reading temperatures:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
