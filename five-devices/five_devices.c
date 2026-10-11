#include <stdio.h>

int main(void) {
    /* 【記憶】入力した値や計算の結果は、変数に保存される（主記憶装置に置かれる） */
    int japanese;
    int math;
    int total;
    double average;

    /* 【入力】キーボードから点数を受け取る */
    printf("国語の点数を入力してください: ");
    if (scanf("%d", &japanese) != 1) {
        printf("数字を入力してください。\n");
        return 1;
    }
    printf("数学の点数を入力してください: ");
    if (scanf("%d", &math) != 1) {
        printf("数字を入力してください。\n");
        return 1;
    }

    /* 【演算】合計と平均を計算する */
    total = japanese + math;
    average = total / 2.0;

    /* 【出力】計算結果をディスプレイに表示する */
    printf("\n合計: %d 点\n", total);
    printf("平均: %.1f 点\n", average);

    /* 【制御】平均点によって、実行する処理を切り替える */
    if (average >= 60.0) {
        printf("結果: 合格\n");
    } else {
        printf("結果: 不合格\n");
    }

    return 0;
}
