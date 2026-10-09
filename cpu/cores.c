#define _POSIX_C_SOURCE 200809L
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TOTAL_WORK 800000000ULL   /* 全体の計算回数（8億回） */
#define MAX_THREADS 64

typedef struct {
    uint64_t count;    /* このスレッドが行う計算回数 */
    uint64_t result;   /* 計算結果（計算が省略されないように使う） */
} Task;

/* 実時間（秒）を返す */
static double now_sec(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

/* 単純な計算をcount回繰り返す（メモリにはほとんど触らない） */
static void *worker(void *arg) {
    Task *t = (Task *)arg;
    uint64_t x = 1;
    uint64_t sum = 0;
    for (uint64_t i = 0; i < t->count; i++) {
        x = x * 6364136223846793005ULL + 1442695040888963407ULL;
        sum += x >> 33;
    }
    t->result = sum;
    return NULL;
}

/* 全体の計算をn_threads個のスレッドに分けて実行し、かかった時間を返す */
static double run(int n_threads, uint64_t *check) {
    pthread_t th[MAX_THREADS];
    Task task[MAX_THREADS];

    double start = now_sec();
    for (int i = 0; i < n_threads; i++) {
        task[i].count = TOTAL_WORK / n_threads;
        if ((uint64_t)i < TOTAL_WORK % (uint64_t)n_threads) {
            task[i].count++;   /* 割り切れない分は、先頭のスレッドに1回ずつ追加する */
        }
        task[i].result = 0;
        pthread_create(&th[i], NULL, worker, &task[i]);
    }
    for (int i = 0; i < n_threads; i++) {
        pthread_join(th[i], NULL);
    }
    double elapsed = now_sec() - start;

    *check = 0;
    for (int i = 0; i < n_threads; i++) {
        *check += task[i].result;
    }
    return elapsed;
}

int main(int argc, char *argv[]) {
    long cores = sysconf(_SC_NPROCESSORS_ONLN);   /* 使えるコアの数 */
    if (argc > 1) cores = atol(argv[1]);          /* 引数があれば、その数を使う */
    if (cores < 1) cores = 1;
    if (cores > MAX_THREADS) cores = MAX_THREADS;

    printf("比較に使うスレッド数: %ld\n", cores);
    printf("全体の計算回数: %llu 回\n\n", (unsigned long long)TOTAL_WORK);

    uint64_t check;
    double t1 = run(1, &check);
    printf("スレッド数 1: %6.3f 秒\n", t1);

    /* コア数が2以上なら、コア数のスレッドに分けて実行する */
    if (cores >= 2) {
        double tn = run((int)cores, &check);
        printf("スレッド数 %ld: %6.3f 秒\n", cores, tn);
        printf("\n速くなった倍率: %.2f 倍\n", t1 / tn);
    } else {
        printf("コアが1つなので、比較はできません。\n");
    }

    printf("（確認用: %llu）\n", (unsigned long long)check);
    return 0;
}