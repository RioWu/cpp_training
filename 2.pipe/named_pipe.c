#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char* fifoPath = "../myfifo";
    char buffer[256];

    //mkfifo(fifoPath, 0666);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {  // 子进程
        int fd = open(fifoPath, O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        printf("子进程收到消息：%s\n", buffer);
        close(fd);
    } else {  // 父进程
        int fd = open(fifoPath, O_WRONLY);
        const char* message = "Hello from parent process!";
        write(fd, message, strlen(message));
        close(fd);
    }

    return 0;
}