#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
    const char *name = "score_memory";

    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(int));

    int *score = mmap(0, sizeof(int),
                     PROT_READ | PROT_WRITE,
                     MAP_SHARED,
                     shm_fd,
                     0);

    pid_t pid = fork();

    if(pid == 0) {
        for(int i=0;i<3;i++) {
            printf("Reader reads score = %d\n", *score);
            sleep(1);
        }
    } else {
        *score = 100;
        sleep(1);
        *score = 200;
        sleep(1);
        *score = 300;
        sleep(1);

        wait(NULL);
        munmap(score, sizeof(int));
        shm_unlink(name);
    }

    return 0;
}
