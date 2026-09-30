# shell

記事：[Linux「コマンドラインとシェル」](https://pc-labo.online/2023/08/11/linux-command-line-and-shell/)

## ファイル

- `hello.sh`：ユーザー名と、今のシェルを表示するシェルスクリプト

## 実行方法

```bash
cd shell
chmod +x hello.sh
./hello.sh
```

## 確認すること

- 先頭の `#!/bin/bash` で、どのシェルで実行するかを指定している
- コマンドをファイルにまとめると、シェルが順に実行してくれる
