#include <stdio.h>

int main(void) {
    printf("char      : %zu バイト\n", sizeof(char));
    printf("int       : %zu バイト\n", sizeof(int));
    printf("long      : %zu バイト\n", sizeof(long));
    printf("long long : %zu バイト\n", sizeof(long long));
    printf("ポインタ  : %zu バイト（%zu ビット）\n",
           sizeof(void *), sizeof(void *) * 8);
    return 0;
}
