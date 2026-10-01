# database

記事：[データベースの基本](https://pc-labo.online/2023/07/27/database/)

## ファイル

- `file_demo.py`：データをファイルで管理すると、同じデータが2か所に重複し、更新で食い違うことを確かめるPythonプログラム
- `db_demo.py`：データをデータベース（SQLite）で管理すると、1か所の更新で済むことを確かめるPythonプログラム

## 実行方法

```bash
cd database
python3 file_demo.py
python3 db_demo.py
```

`file_demo.py` を実行すると、同じフォルダに `courses.csv` と `library.csv` ができます（`.gitignore` で除外しています）。

## 確認すること

- `file_demo.py`：履修管理だけ電話番号を更新すると、図書貸出のデータが古いままになる
- `db_demo.py`：電話番号を持つ表が1つだけなので、どちらの結果も新しい電話番号になる

## 次に読む

[基本情報技術者試験問題に挑戦しよう！「関係モデル」をPython＋SQLiteでつくって学ぶ](https://pc-labo.online/2024/01/15/lets-try-fe-exam-sample-questions-relationship-model/)
