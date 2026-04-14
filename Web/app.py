from flask import Flask, render_template, request, redirect, session
import sqlite3

app = Flask(__name__)
app.secret_key = "secret"

def get_db():
    return sqlite3.connect("database.db")

@app.route('/')
def home():
    if 'user' not in session:
        return redirect('/login')
    db = get_db()
    cur = db.cursor()
    cur.execute("SELECT * FROM students")
    data = cur.fetchall()
    return render_template('index.html', students=data)

@app.route('/login', methods=['GET','POST'])
def login():
    if request.method == 'POST':
        if request.form['username']=="admin" and request.form['password']=="admin":
            session['user']="admin"
            return redirect('/')
    return render_template('login.html')

@app.route('/logout')
def logout():
    session.pop('user', None)
    return redirect('/login')

@app.route('/add', methods=['POST'])
def add():
    db = get_db()
    cur = db.cursor()
    cur.execute("INSERT INTO students VALUES (?,?,?,?,?,?)", (
        request.form['name'],
        request.form['gender'],
        request.form['mark'],
        request.form['income'],
        request.form['aadhar'],
        request.form['account']
    ))
    db.commit()
    return redirect('/')

@app.route('/delete/<name>')
def delete(name):
    db = get_db()
    cur = db.cursor()
    cur.execute("DELETE FROM students WHERE name=?", (name,))
    db.commit()
    return redirect('/')

if __name__ == '__main__':
    db = get_db()
    db.execute("CREATE TABLE IF NOT EXISTS students(name text, gender text, mark text, income text, aadhar text, account text)")
    db.close()
    app.run(debug=True)
