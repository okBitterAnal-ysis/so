/*
Commands:
echo "Hello OS Lab" > source.txt
gcc file_copy_syscall.c -o filecopy
./filecopy
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    int src, dest;
    char buffer[1024];
    ssize_t bytesRead;

    src = open("source.txt", O_RDONLY);
    if (src < 0) {
        perror("Error opening source file");
        exit(1);
    }

    dest = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("Error opening destination file");
        close(src);
        exit(1);
    }

    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        if (write(dest, buffer, bytesRead) != bytesRead) {
            perror("Write error");
            close(src);
            close(dest);
            exit(1);
        }
    }

    if (bytesRead < 0) {
        perror("Read error");
    }

    close(src);
    close(dest);

    struct stat s1, s2;
    stat("source.txt", &s1);
    stat("destination.txt", &s2);

    if (s1.st_size == s2.st_size) {
        printf("File copied successfully.\n");
    } else {
        printf("File copy failed.\n");
    }

    return 0;
}
