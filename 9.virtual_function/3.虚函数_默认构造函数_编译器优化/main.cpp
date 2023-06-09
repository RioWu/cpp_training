#include <iostream>
using namespace std;
class B {
   public:
     virtual void f() {
        // if (this == nullptr) {
        //     cout << "this is nullptr" << endl;
        // }
        cout << "hello world" << endl;
        cout << b << endl;
    }

   private:
    int b;
};
class A {
   public:
    // 默认构造函数和编译器都会把m_b置为nullptr,把a置0
    // A() {
    // }
    void f() {
        m_b->f();
        // m_b->f(m_b)
        //_ZN1B1fEv()
    }
    B* m_b;

    int a;
};
//-g是附带调试信息，只会增加大小
//-O决定了优化等级
int main(int argc, char const* argv[]) {
    cout << sizeof(B) << endl;
    A* p = new A();
    // p->m_b = new B();
    p->f();
    //_ZN1A1fEv()
    return 0;
}

/*
    这个程序会报错，因为通过指针的方式调用虚函数时会走虚表，虚表是属于对象实例的内容，而m_b并没有初始化，所以它会是一个nullptr，或者一个随机值（这取决于编译优化以及默认构造函数）
    1.为p->m_b赋予一个真正对象的地址
    2.将virtual方法改为普通方法
        1）将virtual方法改为普通方法之后，如果f()中存在对B内成员的访问，仍然是不行的，因为m_b并没有真正指向一个对象，所以传进f()里的this指针是一个空指针，所以仍然会报错
    3.使用对象实例而非指针的方式调用方法

*/