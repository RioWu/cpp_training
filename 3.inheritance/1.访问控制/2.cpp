#include <iostream>
using namespace std;
class Base {
   public:
    void publicMethod() {
        cout << "This is a public method in the base class." << endl;
    }

   protected:
    void protectedMethod() {
        cout << "This is a protected method in the base class." << endl;
    }

   private:
    void privateMethod() {
        cout << "This is a private method in the base class." << endl;
    }
};

struct Derivedstruct : Base {
    // 默认为公有继承
    void accessBaseMembers() {
        publicMethod();     // 可以访问基类的公有成员
        protectedMethod();  // 可以访问基类的保护成员
        // privateMethod();  // 无法访问基类的私有成员
    }
};

class Derivedclass : Base {
    // 默认私有继承
   public:
    void accessBaseMembers() {
        publicMethod();     // 可以访问基类的公有成员
        protectedMethod();  // 可以访问基类的保护成员
        // privateMethod();  // 无法访问基类的私有成员
    }
};

int main() {
    Derivedstruct derivedstruct;
    Derivedclass derivedclass;

    derivedstruct.accessBaseMembers();
    // 可以调用派生类的公有成员函数

    derivedstruct.publicMethod();
    // 可以访问基类的公有成员

    // derivedstruct.protectedMethod();
    // 错误：无法访问基类的保护成员
    // derivedstruct.privateMethod();
    // 错误：无法访问基类的私有成员

    derivedclass.accessBaseMembers();
    // 可以调用派生类的公有成员函数

    // derivedclass.publicMethod();
    // 可以访问基类的公有成员
    // derivedclass.protectedMethod();
    // 错误：无法访问基类的保护成员
    // derivedclass.privateMethod();
    // 错误：无法访问基类的私有成员
    return 0;
}