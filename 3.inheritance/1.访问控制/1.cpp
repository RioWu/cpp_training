class A {
   public:
    int public_int;

   protected:
    int protected_int;

   private:
    int private_int;
};

class B : public A {
   public:
    void func() {
        public_int++;
        protected_int++;
        // private_int++;
    }
};
class C : protected A {
   public:
    void func() {
        public_int++;
        protected_int++;
        // private_int++;
    }
};
class D : private A {
   public:
    void func() {
        public_int++;
        protected_int++;
        // private_int++;
    }
};
int main(int argc, char const* argv[]) {
    // 初始化对象
    B b;
    C c;
    D d;

    // 公有继承
    b.public_int++;
    // b.protected_int++;
    // b.private_int++;
    b.func();

    // 保护继承
    // c.public_int++;
    // c.protected_int++;
    // c.private_int++;
    c.func();

    // 私有继承
    // d.public_int++;
    // d.protected_int++;
    // d.private_int++;
    d.func();
    return 0;
}
