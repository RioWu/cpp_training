// #include "a.h"
static int a;
int b,c;
void func1() {
    a = 3;
}
// 如果是static，在编译当前编译单元时就会检查该变量是否被使用，因为static指定的对象只能在本编译单元使用

// header-only 库：模板库

// ttroy50-cmake-examples

// inline 和 模板库 都要放在.h文件里

// 模板库怎么用cmake生成