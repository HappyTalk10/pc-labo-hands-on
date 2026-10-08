#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define SIZE_MB 128                              /* 扱うデータ量（MB） */
#define SIZE ((size_t)SIZE_MB * 1024 * 1024)     /* バイト数に変換 */
#define FILENAME "testfile.bin"                  /* 書き込み先のファイル */

/* 現在時刻を秒（小数）で返す。I/Oの待ち時間も含めた実時間を測る */
static double now_sec(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

static void report(const char *label, double sec) {
    printf("%-26s: %8.3f 秒  (%9.1f MB/秒)\n", label, sec, SIZE_MB / sec);
}

/* buf の内容をファイルに書き込み、かかった時間を返す。失敗したら -1 */
static double write_file(const unsigned char *buf, int use_fsync) {
    FILE *fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    double start = now_sec();
    if (fwrite(buf, 1, SIZE, fp) != SIZE) {
        perror("fwrite");
        fclose(fp);
        return -1;
    }
    fflush(fp);                    /* Cのバッファ → OSへ渡す */
    if (use_fsync) {
        fsync(fileno(fp));         /* OSのキャッシュ → 記憶装置へ書き切る */
    }
    double elapsed = now_sec() - start;

    fclose(fp);
    return elapsed;
}

int main(void) {
    unsigned char *src = malloc(SIZE);
    unsigned char *dst = malloc(SIZE);
    if (src == NULL || dst == NULL) {
        perror("malloc");
        return 1;
    }

    /* 計測前に両方のメモリを使い始めておく（初回アクセスの遅れを除くため） */
    for (size_t i = 0; i < SIZE; i++) {
        src[i] = (unsigned char)(i * 31);
    }
    memset(dst, 0, SIZE);

    printf("データ量: %d MB\n\n", SIZE_MB);

    /* ① 主記憶 → 主記憶（コピー） */
    double start = now_sec();
    memcpy(dst, src, SIZE);
    double t_mem = now_sec() - start;
    report("① メモリ上でコピー", t_mem);

    /* ② ファイルに書き込む（fsyncなし） */
    double t_file = write_file(src, 0);
    if (t_file < 0) return 1;
    report("② ファイルへ書き込み", t_file);

    /* ③ ファイルに書き込み、記憶装置に書き切るまで待つ（fsyncあり） */
    double t_sync = write_file(src, 1);
    if (t_sync < 0) return 1;
    report("③ ファイルへ書き込み+fsync", t_sync);

    printf("\n倍率：③は①の約 %.1f 倍の時間\n", t_sync / t_mem);
    printf("（確認用: dst の末尾 = %d）\n", dst[SIZE - 1]);

    remove(FILENAME);
    free(src);
    free(dst);
    return 0;
}
