import sqlite3

con = sqlite3.connect(":memory:")

# 表を3つ作る。電話番号は students だけが持つ
con.execute("CREATE TABLE students (id INTEGER PRIMARY KEY, name TEXT, phone TEXT)")
con.execute("CREATE TABLE courses (student_id INTEGER, subject TEXT)")
con.execute("CREATE TABLE loans (student_id INTEGER, book TEXT)")

con.execute("INSERT INTO students VALUES (1, '山田太郎', '090-9999-9999')")
con.execute("INSERT INTO courses VALUES (1, '情報基礎')")
con.execute("INSERT INTO loans VALUES (1, 'ITパスポート入門')")

# 電話番号が変わった。1か所を更新するだけでよい
con.execute("UPDATE students SET phone = '090-1111-1111' WHERE id = 1")

# 学籍番号で表をつなぐ
sql_courses = """
SELECT s.name, s.phone, c.subject
FROM students s JOIN courses c ON c.student_id = s.id
"""
sql_loans = """
SELECT s.name, s.phone, l.book
FROM students s JOIN loans l ON l.student_id = s.id
"""

for row in con.execute(sql_courses):
    print("履修管理:", row)
for row in con.execute(sql_loans):
    print("図書貸出:", row)
