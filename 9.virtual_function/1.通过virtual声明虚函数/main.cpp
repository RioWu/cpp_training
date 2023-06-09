#include <iostream>
using namespace std;
class A {
   public:
    virtual void func1() {
        cout << "func1 in A" << endl;
    };
    void func2() {
        cout << "func2 in A" << endl;
    };
    void func3() {
        cout << "func3 in A" << endl;
    }
};
// 测试发现，即使B里面没有定义任何虚函数，并且B没有重写A的虚函数，B的对象也会有虚表指针
// 这应该是一种从保守角度设计的编译器行为，A中有虚函数，那么A的子类就有可能重写A的方法，那就需要有虚表和虚表指针
// 说他保守的原因是，这种情况下，B没有虚表和虚表指针也完全ok
// 又做了一些测试，得到的结论如下：
//    如果一个类有虚函数f1，那么自它开始继承链中的后面所有类:
//                                      1.都会有虚表和虚表指针
//                                      2.都支持对f1的重写（但不支持对其他未被声明为virtual的函数的重写，如f2)
class B : public A {
   public:
    void func1() {
        cout << "func1 in B" << endl;
    }
    virtual void func2() {
        cout << "func2 in B" << endl;
    }
    virtual void func3() {
        cout << "func3 in B" << endl;
    }
};
class C : public B {
   public:
    void func1() {
        cout << "func1 in C" << endl;
    }
    void func3() {
        cout << "func3 in C" << endl;
    }
};
class D {
   public:
    void func1() {
        cout << "func1 in D" << endl;
    }
};
class E : public D {
   public:
    void func1() {
        cout << "func1 in E" << endl;
    }
};
int main(int argc, char const* argv[]) {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    // B继承A，由于A中的func1()声明为一个虚函数，B中的func1()也自动成为虚函数，可以实现多态
    B* n = new C();
    n->func1();
    // func3()没有被声明成虚函数
    n->func3();
    // 由于C中没有声明func3()为虚函数，所以不能实现多态
    D* m = new E();
    m->func1();

    cout << endl
         << endl;
    // 普通成员函数和虚函数的调用流程是不同的：
    //   1.普通成员函数的地址在编译期就已经确定，直接调用即可
    //   2.虚函数的地址是在运行时通过虚表动态绑定的
    //      a.通过实例的虚表找到要绑定的函数
    //      b.执行对应函数
    // 只有加了"virtual"关键字才表示这个函数是虚函数，通过指针调用时才会走虚表的流程
    A* p = new B();
    // 多态（A中定义了虚函数func1，B继承了A并重载了函数func1，那么当一个A类型的指针承载的是B类型的对象时，它访问func1函数理应访问到B的func1函数而不是A的，这就是多态）
    p->func1();
    p->func2();
    p->func3();
    cout << endl
         << endl;

    // 通过实例无法实现多态
    A a = B();
    a.func1();
    a.func2();
    a.func3();

    cout << endl
         << endl;
    B* q = new B();
    q->func1();
    q->func2();
    q->func3();
    return 0;
}