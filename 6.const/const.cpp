#include <stdio.h>
int main(int argc, char const* argv[]) {
    const int const_int = 4;
    // 这条语句会报错，因为不能用const int *类型来初始化int *，只能用const int *p来承载const_int的地址，但这样也不能修改const_int的值
    const int* p = &const_int;
    //*p = 5;
    //printf("%d\n", *p);
    return 0;
}