#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
    // 获取信号量
    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");  // 打印错误信息
        exit(1);  // 退出程序
    }

    // 初始化信号量
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } arg;
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl");  // 打印错误信息
        exit(1);  // 退出程序
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");  // 打印错误信息
        exit(1);  // 退出程序
    }

    if (pid == 0) {
        // 子进程
        while (1) {
            // 获取信号量
            struct sembuf sb = {0, -1, SEM_UNDO};  // 定义信号量操作结构体
            if (semop(semid, &sb, 1) == -1) {  // 对信号量进行P操作
                perror("semop");  // 打印错误信息
                exit(1);  // 退出程序
            }
            // 访问共享资源（例如文件）
            printf("Child process is accessing the shared resource...\n");

            sleep(1);

            // 释放信号量
            sb.sem_op = 2;  // 设置信号量操作为V操作
            if (semop(semid, &sb, 1) == -1) {  // 对信号量进行V操作
                perror("semop");  // 打印错误信息
                exit(1);  // 退出程序
            }
        }
    } else {
        // 父进程
        while (1) {
            // 获取信号量
            struct sembuf sb = {0, -3, SEM_UNDO};  // 定义信号量操作结构体
            if (semop(semid, &sb, 1) == -1) {  // 对信号量进行P操作
                perror("semop");  // 打印错误信息
                exit(1);  // 退出程序
            }

            // 访问共享资源（例如文件）
            printf("Parent process is accessing the shared resource...\n");
            sleep(1);

            // 释放信号量
            sb.sem_op = 1;  // 设置信号量操作为V操作
            if (semop(semid, &sb, 1) == -1) {  // 对信号量进行V操作
                perror("semop");  // 打印错误信息
                exit(1);  // 退出程序
            }
        }
    }

    return 0;
}