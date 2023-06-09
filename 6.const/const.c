#include <stdio.h>
int main(int argc, char const* argv[]) {
    const int const_int = 4;
    int* p = &const_int;
    *p = 5;
    printf("%d\n", *p);
    return 0;
}
/*
编译会报 warning：使用const int *类型来初始化int *类型会丢弃掉 "const"这个限定符
main.c:4:10: warning: initializing 'int *' with an expression of type 'const int *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
    int* p = &const_int;
         ^   ~~~~~~~~~~
*/