#include <iostream>
using namespace std;
class A {
   public:
// 不能用这种方式初始化
//    A(){
//     const_member = 10; 
//    }
    const int const_member = 5;
};
int main(int argc, char const* argv[]) {
    // 用字面量初始化的const常量会被加入符号表
    const int const_int = 4;
    // 这条语句会报错，因为不能用const int *类型来初始化int *，只能用const int *p来承载const_int的地址，但这样也不能修改const_int的值
    // 常量指针，就是指针指向的地址里面的内容是不可以变的，指向常量的指针
    // int* p = &const_int;
    // *p = 5;
    int* p = (int*)&const_int;
    cout << "*p的值为" << *p << endl;
    *p = 5;
    cout << "*p的值为" << *p << endl;
    // const_int的值输出还是4,这是因为const_int的值在编译期就被确定了
    cout << "const_int的值为" << const_int << endl;


    // 只有用字面量初始化的const常量会被加入符号表，而变量初始化的const常量依然只是只读变量。
    int j = 5;
    const int i = j;
    p = (int*)&i;
    *p = 6;
    cout << i << endl;
    cout << *p << endl;

    cout << endl
         << endl;
    // const成员变量为只读变量，可以通过指针修改const成员的值，另外const成员变量只能在初始化列表中进行初始化。
    // 分析： a 是一个对象实例，在运行时才能被创建，所以编译的时候确定不了a里面的成员变量的值
    A a;
    p = (int*)&a.const_member;
    *p = 10;
    cout << a.const_member << endl;
    return 0;
}
