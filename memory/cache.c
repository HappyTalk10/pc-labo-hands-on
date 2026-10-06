#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N (64 * 1024 * 1024)  /* 整数6,400万個（約256MB） */

int main(void) {
    int *a = malloc(sizeof(int) * (size_t)N);
    if (a == NULL) return 1;
    for (size_t i = 0; i < N; i++) a[i] = 1;

    long sum = 0;

    clock_t t = clock();
    for (size_t i = 0; i < N; i++) sum += a[i];
    printf("順番に読む　　: %.3f 秒\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    t = clock();
    for (size_t s = 0; s < 16; s++)
        for (size_t i = s; i < N; i += 16) sum += a[i];
    printf("飛び飛びに読む: %.3f 秒\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    printf("sum = %ld\n", sum);
    free(a);
    return 0;
}
