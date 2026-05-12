#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 1234;

    int shmid = shmget(key, sizeof(int)*5, 0666);

    int *data = (int*) shmat(shmid, NULL, 0);

    for(int i=0;i<5;i++) {
        printf("Read: %d\n", data[i]);
    }

    shmdt(data);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
