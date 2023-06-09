#include "a.h"
// 全局空间内不能直接赋值
// b = 4; 
// 但是可以 int b = 4;
// 定义 + 赋值一起 = 初始化
int a;
void func2(){
    b = 4;
}