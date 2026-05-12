/*
Commands:
gcc fork_attendance.c -o attendance
./attendance
cat attendance.txt
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());

        int fd = open("attendance.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

        write(fd, "Child attended\n", strlen("Child attended\n"));

        close(fd);
    } else {
        wait(NULL);

        printf("Parent PID: %d\n", getpid());

        int fd = open("attendance.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

        write(fd, "Parent attended\n", strlen("Parent attended\n"));

        close(fd);
    }

    return 0;
}
