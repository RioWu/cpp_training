#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[5];
    arr[0] = 1;
    printf("%p\n",arr);
    printf("%p\n",&arr[0]);
    printf("%d\n",arr[0]);
    printf("%d\n",*&arr[0]);

    return 0; 
}
