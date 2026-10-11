# pc-labo-hands-on

[PC-LABO](https://pc-labo.online/)（つくって学ぶ体験型ブログ）の記事で使うコードをまとめたリポジトリです。

記事を読みながら、コマンドを打ち、プログラムを動かして、仕組みを確かめられます。

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/HappyTalk10/pc-labo-hands-on)

## 記事とフォルダの対応

| 記事 | フォルダ | ファイル | 実行する場所 |
|---|---|---|---|
| [OS（Operating System）とは？](https://pc-labo.online/2023/08/31/operating-system/) | [`os/`](https://github.com/HappyTalk10/pc-labo-hands-on/blob/main/os) | `pid.c` | Codespaces |
| [Linux「コマンドラインとシェル」](https://pc-labo.online/2023/08/11/linux-command-line-and-shell/) | [`shell/`](https://github.com/HappyTalk10/pc-labo-hands-on/blob/main/shell) | `hello.sh` | Codespaces |
| [メモリの種類](https://pc-labo.online/2023/07/01/memory/) | [`memory/`](https://github.com/HappyTalk10/pc-labo-hands-on/blob/main/memory) | `cache.c` | Codespaces |
| [入出力インターフェイス](https://pc-labo.online/2023/07/07/input-output-interface/) | [`io-interface/`](https://github.com/HappyTalk10/pc-labo-hands-on/blob/main/io-interface) | `list_devices.py` | 自分のPC |
| [記憶装置の種類](https://pc-labo.online/2023/06/30/storage-device/) | [`storage/`](https://github.com/HappyTalk10/pc-labo-hands-on/blob/main/storage) | `memory_vs_file.c` | Codespaces |
| [CPU](https://pc-labo.online/2023/06/29/cpu/) | [`cpu/`](https://github.com/HappyTalk10/pc-labo-hands-on/blob/main/cpu) | `bits.c`、`cores.c` | Codespaces |
| [コンピュータの五大装置](https://pc-labo.online/2023/06/28/five-major-computer-devices/) | [`five-devices/`](https://github.com/HappyTalk10/pc-labo-hands-on/blob/main/five-devices) | `five_devices.c` | Codespaces |
| [ネットワーク](https://pc-labo.online/2023/09/01/network/) | [`network/`](https://github.com/HappyTalk10/pc-labo-hands-on/blob/main/network) | （READMEのみ） | Codespaces |

## 使い方

1. 上の「Open in GitHub Codespaces」ボタンから、Codespacesを起動する
2. ターミナルで、記事に対応するフォルダへ移動する（例：`cd os`）
3. 各フォルダの `README.md` の手順で実行する

## 注意

- `io-interface/` は、自分のPCに接続されている機器を調べるプログラムです。CodespacesやWSLでは、実機のUSBは見えません。
- `memory/cache.c` は、約256MBのメモリを使います。
- `storage/memory_vs_file.c` は、約256MBのメモリを使い、128MBの一時ファイルを作ります（終了時に削除されます）。
- `cpu/cores.c` は、コアが1つの環境では速さを比べられません。Codespacesでは、マシンタイプによってコアの数が変わります。
- `network/` は、コマンドだけで体験できます。Webサーバーを動かすため、ターミナルを2つ使います。
- 実行結果や表示は、環境によって変わります。