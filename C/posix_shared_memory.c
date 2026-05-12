/*
Commands:
gcc posix_shared_memory.c -o posixshm -lrt
./posixshm
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main() {
    const char *name = "/score_shm";

    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    ftruncate(shm_fd, sizeof(int));

    int *score = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    pid_t pid = fork();

    if (pid == 0) {
        for (int i = 0; i < 3; i++) {
            sleep(1);
            printf("Reader sees score: %d\n", *score);
        }
    } else {
        int values[] = {100, 200, 300};

        for (int i = 0; i < 3; i++) {
            *score = values[i];
            printf("Writer updated score to %d\n", *score);
            sleep(1);
        }

        wait(NULL);

        munmap(score, sizeof(int));
        shm_unlink(name);
    }

    return 0;
}
