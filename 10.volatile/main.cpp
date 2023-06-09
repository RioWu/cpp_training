#include <stdio.h>

int main() {
    int x = 10;
    volatile int* p = &x;
    int *q = &x;
    printf("volatile pointer:*p = %d\n", *p);
    printf("normal pointer:*q = %d\n", *q);
  
    x = 20;
    printf("volatile pointer:*p = %d\n", *p);
    printf("normal pointer:*q = %d\n", *q);

    
    return 0;

}