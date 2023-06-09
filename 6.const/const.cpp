#include <iostream>
using namespace std;
int main(int argc, char const* argv[]) {
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
    return 0;
}