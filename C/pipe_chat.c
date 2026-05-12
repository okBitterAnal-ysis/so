/*
Commands:
gcc pipe_chat.c -o pipechat
./pipechat
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char buffer[100];

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));

        for (int i = 0; buffer[i] != '\0'; i++) {
            buffer[i] = toupper(buffer[i]);
        }

        printf("Child received: %s\n", buffer);

        close(fd[0]);
    } else {
        close(fd[0]);

        char msg[] = "Hello from parent";

        write(fd[1], msg, strlen(msg) + 1);

        close(fd[1]);

        wait(NULL);
    }

    return 0;
}
