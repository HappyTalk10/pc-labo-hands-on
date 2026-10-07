import platform
import subprocess

commands = {
    "Windows": ["powershell", "-Command", "Get-PnpDevice -Class USB"],
    "Linux": ["lsusb"],
}

os_name = platform.system()
print(f"OS: {os_name}")

if os_name not in commands:
    print("このOSには対応していません（Windows と Linux に対応）")
    raise SystemExit(1)

try:
    result = subprocess.run(commands[os_name], capture_output=True, text=True)
except FileNotFoundError:
    print(f"コマンドが見つかりません: {commands[os_name][0]}")
    print("Linuxの場合は usbutils パッケージが必要です")
    raise SystemExit(1)

print(result.stdout)
