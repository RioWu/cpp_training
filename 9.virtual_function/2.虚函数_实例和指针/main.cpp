#include <iostream>
#include <cstring>
using namespace std;
class A {
   public:
    void func1() {
        cout << "normal func" << endl;
        cout << a << endl;
    }
    virtual void func2() {
        cout << 2 << endl;
    }
    static void func3() {
        cout << 3 << endl;
    }
    int a = 1;
};
int main(int argc, char const* argv[]) {
    A::func3();
    A* p = new A();
    cout << p << endl;
    cout << &p->a << endl;
    cout << sizeof(A) << endl;
    // 指针p和整形i相加时，这里的i不是指的具体字节的个数，而是指的"单位"的个数，而一个"单位"的大小就是p类型的大小，也就是整形i会自动转换成i*(p所指类型的大小)
    // 所以p + 8实际上对应的地址是 p的地址 + 8 * 16(因为p是A类型的指针，而A类型的大小是16)
    // 将p强制转换为void*类型（或者char*类型也可以），再和整数相加时就能达到想要的效果
    // 因为sizeof(char) = 1,void*和整形运算的时候也是以一个字节大小为单位
    memset((void*)p + 8, 0, sizeof(A) - 8);
    p->func1();
    p->func2();
    p->func3();

    // 实例不会访问虚表,指针才会访问虚表
    // A p;
    // memset((void*)&p, 0, sizeof(A));
    // p.func1();
    // p.func2();
    // p.func3();
    return 0;
}
