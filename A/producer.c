#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    key_t key = 1234;

    int shmid = shmget(key, sizeof(int)*5, 0666 | IPC_CREAT);

    int *data = (int*) shmat(shmid, NULL, 0);

    for(int i=0;i<5;i++) {
        data[i] = 25 + i;
        printf("Written: %d\n", data[i]);
    }

    shmdt(data);

    return 0;
}
