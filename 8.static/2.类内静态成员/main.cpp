class A {
   public:
    // 会报错：带有类内初始值设定项的成员必须为常量
    // static int i = 5;
    static int i;
    const static int j = 5;
};
int A::i = 8;
int main(int argc, char const* argv[]) {
    const int* p1 = &A::i;
    /*
      运行时会报错，因为j会被优化成编译期常量，所以会报找不到符号
      Undefined symbols for architecture x86_64:
      "A::j", referenced from:
        _main in main-03641e.o
      ld: symbol(s) not found for architecture x86_64
      clang: error: linker command failed with exit code 1 (use -v to see invocation)
    */
    const int* p2 = &A::j;
    return 0;
}
