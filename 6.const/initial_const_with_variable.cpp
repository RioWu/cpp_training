#include <iostream>
using namespace std;
class A {
   public:
    const int const_member = 5;
};
int main(int argc, char const* argv[]) {
    // 只有用字面量初始化的const常量会被加入符号表，而变量初始化的const常量依然只是只读变量。
    int j = 5;
    const int i = j;
    int* p = (int*)&i;
    *p = 6;
    cout << i << endl;
    cout << *p << endl;

    cout << endl
         << endl;
    // const成员为只读变量，可以通过指针修改const成员的值，另外const成员变量只能在初始化列表中进行初始化。
    A a;
    p = (int*)&a.const_member;
    *p = 10;
    cout << a.const_member << endl;
    return 0;
}
