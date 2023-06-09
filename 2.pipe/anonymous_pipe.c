#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main() {
    int pipefd[2];
    //pipefd[0] pipefd[1]
    //往pipefd[1]写
    //从pipefd[0]读
    char buffer[256];
/*
    int pipe(int *__pipedes)
    Create a one-way communication channel (pipe).
    If successful, two file descriptors are stored in PIPEDES;
    bytes written on PIPEDES[1] can be read from PIPEDES[0].
    Returns 0 if successful, -1 if not.
*/
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    __pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {  // 子进程
        close(pipefd[1]);  // 关闭写入端

        read(pipefd[0], buffer, sizeof(buffer));
        printf("子进程收到消息：%s\n", buffer);

        close(pipefd[0]);
    } else {  // 父进程
        close(pipefd[0]);  // 关闭读取端

        const char* message = "Hello from parent process!";
        write(pipefd[1], message, strlen(message));
        //write(pipefd[1], message,sizeof(message));
        //注：这里不能用sizeof，因为sizeof(message)返回的是这个char类型指针的大小，而不是字符串的长度
        // 64位：8个字节，一个字节8位
        // 32位：4个字节，一个字节8位
        close(pipefd[1]);
    }

    return 0;
}