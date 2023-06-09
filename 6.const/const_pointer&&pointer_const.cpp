#include <stdio.h>
int main(int argc, char const* argv[]) {
    //对指针类型加const，有两种含义：
    // 1.对指针本身加const =》 指针对应的地址不能改变
    //   指针常量 int *const p; const加在*号的右边
    // 2.对指针指向的地址内容加const =》 指针指向的地址内容不能改变
    //   常量指针 int const*p; const int *p 指针指向的地址内容不能变
    int i = 3;  //地址1
    int j = 100;  //地址2
    // 常量指针-指针指向的内容是常量，不能被这个指针所改变
    const int* const_ptr = &i;
    printf("%d\n" ,*const_ptr);
    // 常量指针的含义不是指向的内容不能改变，而是不能被这个常量指针改变
    i = 5;
    printf("%d\n",*const_ptr);
    // 下面的语句会报错，因为const int*的值是不能被修改的
    //*const_ptr = 4;
    // 常量指针指向的地址可以改变
    const_ptr = &j;
    printf("%d\n",*const_ptr);




    // 指针常量-指针指向的地址不能被修改，指针常量声明的时候必须初始化
    int* const ptr_const = &i;
    *ptr_const = 521;
    printf("%d\n",*ptr_const);
    // 下面的语句会报错，因为指针常量指向的内容是不能被修改的
    // ptr_const = &j;

    return 0;
}
