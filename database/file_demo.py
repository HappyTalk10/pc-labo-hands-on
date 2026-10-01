import csv


def write_csv(path, rows):
    with open(path, "w", newline="", encoding="utf-8") as f:
        csv.writer(f).writerows(rows)


def read_csv(path):
    with open(path, newline="", encoding="utf-8") as f:
        return list(csv.reader(f))


# システムごとにファイルを持つ（同じ人の電話番号が2か所にある）
write_csv("courses.csv", [
    ["学籍番号", "氏名", "電話番号", "科目"],
    ["1", "山田太郎", "090-9999-9999", "情報基礎"],
])
write_csv("library.csv", [
    ["学籍番号", "氏名", "電話番号", "貸出図書"],
    ["1", "山田太郎", "090-9999-9999", "ITパスポート入門"],
])

# 電話番号が変わった。履修管理のファイルだけ更新してしまった
rows = read_csv("courses.csv")
rows[1][2] = "090-1111-1111"
write_csv("courses.csv", rows)

print("履修管理の電話番号:", read_csv("courses.csv")[1][2])
print("図書貸出の電話番号:", read_csv("library.csv")[1][2])
