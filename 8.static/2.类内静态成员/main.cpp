class A {
   public:
    // 会报错：带有类内初始值设定项的成员必须为常量
    // 理解：因为静态成员属于整个类，而不属于某个对象，如果在类内初始化，那么会导致每个对象都包含该静态成员，这是矛盾的。
    // 可以配合static/1.全局静态变量 来理解，主要理解声明和定义的区别
    // static int i = 5;
    static int i;
    const static int j = 5;
};
int A::i = 8;
int main(int argc, char const* argv[]) {
    const int* p1 = &A::i;
    /*
      链接时会报错，因为j会被优化成编译期常量，所以会报找不到符号
      Undefined symbols for architecture x86_64:
      "A::j", referenced from:
        _main in main-03641e.o
      ld: symbol(s) not found for architecture x86_64
      clang: error: linker command failed with exit code 1 (use -v to see invocation)
    */
    const int* p2 = &A::j;
    return 0;
}

/*
编译并不会报错，但是查看main.o的符号表可以发现，
nm -C main.o
0000000000000000 T main
0000000000000000 D A::i
                 U A::j
*/
// D The symbol is in the initialized data section.
// U The symbol is undefined.