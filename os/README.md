# os

記事：[OS（Operating System）とは？](https://pc-labo.online/2023/08/31/operating-system/)

## ファイル

- `pid.c`：自分のプロセスID（PID）を表示するCプログラム

## 実行方法

```bash
cd os
gcc pid.c -o pid
./pid
./pid
```

## 確認すること

同じプログラムでも、実行するたびにPIDが変わります。OSは、起動したプログラムを別々のプロセスとして管理しています。
