# storage

ブログ記事「記憶装置の種類」で使うコードです。

## memory_vs_file.c

メモリ上のコピーと、ファイルへの書き込みの速度を比べます。

- ① メモリ上でコピー
- ② ファイルへ書き込み（fsyncなし）
- ③ ファイルへ書き込み + fsync（記憶装置に書き切るまで待つ）

### 実行方法

```
cd storage
gcc -O2 -o memory_vs_file memory_vs_file.c
./memory_vs_file
```

- 128MBのファイル `testfile.bin` を作り、終了時に削除します。
- 結果は環境（PC、Codespacesなど）によって変わります。
