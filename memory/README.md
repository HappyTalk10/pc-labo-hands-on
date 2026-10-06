# memory

記事：[メモリの種類](https://pc-labo.online/2023/07/01/memory/)

## ファイル

- `cache.c`：同じ量のデータを、順番に読む場合と飛び飛びに読む場合で、時間を比べるCプログラム

## 実行方法

```bash
gcc -O1 cache.c -o cache
./cache
```

## 確認すること

順番に読むほうが速くなることが多いです。近くのデータは、まとめてキャッシュ（SRAM）に読み込まれるためです。差の大きさは、環境によって変わります。

## 注意

約256MBのメモリを使います。

## 関連コマンド（記事で使用）

```bash
free -h
df -h /dev/shm ~
lscpu | grep -i cache
```
