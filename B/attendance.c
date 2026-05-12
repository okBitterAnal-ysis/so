#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main() {

    pid_t pid = fork();

    if(pid == 0) {

        int fd = open("attendance.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

        char msg[] = "Child attended\n";

        write(fd, msg, strlen(msg));

        printf("Child PID = %d Parent PID = %d\n", getpid(), getppid());

        close(fd);
    }

    else {

        wait(NULL);

        int fd = open("attendance.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

        char msg[] = "Parent attended\n";

        write(fd, msg, strlen(msg));

        printf("Parent PID = %d\n", getpid());

        close(fd);
    }

    return 0;
}
