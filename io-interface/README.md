# io-interface

記事：[入出力インターフェイス](https://pc-labo.online/2023/07/07/input-output-interface/)

## ファイル

- `list_devices.py`：OSに合ったコマンドで、接続されているUSB機器の一覧を表示するPythonプログラム

## 実行方法

**自分のPC**で実行してください。CodespacesやWSLでは、実機のUSBは見えません。

Linux：

```bash
python3 list_devices.py
```

Windows：

```powershell
python list_devices.py
```

## 対応OS

| OS | 実行されるコマンド |
|---|---|
| Windows | `Get-PnpDevice -Class USB`（PowerShell） |
| Linux | `lsusb` |

## 注意

Linuxで `lsusb` が見つからない場合は、`usbutils` パッケージが必要です。

```bash
sudo apt install usbutils
```
