# 指定编译器和编译选项
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra 


# 指定链接选项
LDFLAGS =

# 源文件列表
SRC = 1.c 2.c 3.c main.c

# 目标文件列表
OBJ = 1.o 2.o 3.o main.o

# 可执行文件
EXE = myprogram

all: $(EXE)

myprogram: 1.o 2.o 3.o main.o
	$(CC) $(LDFLAGS) 1.o 2.o 3.o main.o -o myprogram

1.o: 1.c 
	$(CC) $(CFLAGS) -c 1.c -o 1.o

2.o: 2.c 
	$(CC) $(CFLAGS) -c 2.c -o 2.o

3.o: 3.c 
	$(CC) $(CFLAGS) -c 3.c -o 3.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f myprogram 1.o 2.o 3.o main.o

# 如果不使用Makefile，那么就用手动输入下面的gcc 命令来执行编译和链接操作
# -c 选项指的是不链接只编译
# gcc -Wall -Wextra -Werror -c 1.c -o 1.o
# gcc -Wall -Wextra -Werror -c 2.c -o 2.o
# gcc -Wall -Wextra -Werror -c 3.c -o 3.o
# gcc -Wall -Wextra -Werror -c main.c -o main.o
# gcc 1.o 2.o 3.o main.o -o myprogram