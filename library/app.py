import os

from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker
from helpers import login_required,usd
from werkzeug.security import check_password_hash, generate_password_hash
import requests

app = Flask(__name__)

# Check for environment variable
if not os.getenv("DATABASE_URL"):
    raise RuntimeError("DATABASE_URL is not set")

# Configure session to use filesystem
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)
app.config['DEBUG'] = True

# Set up database
engine = create_engine(os.getenv("DATABASE_URL"))
db = scoped_session(sessionmaker(bind=engine))

# todo


@app.route("/",methods = ["GET","POST"])
def redirec():
    #redirect to search
    return redirect("/search")

@app.route("/search",methods = ["GET","POST"])
def search():
    #if method is post get all results like the give string in that query and put them in a list
    if request.method == "POST":
        if not request.form.get("search"):
            return render_template("error.html", message = "Error, No Input in Search Bar")
        if not request.form.get("type"):
            return render_template("error.html", messsage = "Error, No Type Entered")
        search = request.form.get("search")
        results = db.execute("SELECT * FROM books WHERE UPPER ("+ request.form.get("type")+") LIKE :a",{"a":"%" + search.upper() + "%"}).fetchall()
        if not results:
            return render_template("none.html")
        return render_template("searched.html",results=results)
    if request.method == "GET":
        # if method is get return search html
        return render_template("search.html")

@app.route("/login",methods = ["GET","POST"])
def login():
    if request.method == "POST":
        #if method is post make session user id and then send home
        session.clear()
        if not request.form.get("username"):
            return render_template("error.html", message = "Must Provide a Username YOU STUPID!!!")
        if not request.form.get("password"):
            return render_template("error.html", message = "Must Provide A Password You Stupid")
        result = db.execute("SELECT id,password FROM users WHERE username = :username",{"username":request.form.get("username")}).fetchone()
        if not result:
            return render_template("error.html",message = "Username Incorrect")
        if result.password != request.form.get("password"):
            return render_template("error.html",message="Password Incorrect")
        session["user_id"] = result.id
        return redirect("/")
    else:
        #if method is get promt the user to login
        return render_template("login.html")

@app.route("/search/<int:book_id>", methods = ["GET","POST"])
def book(book_id):
    if request.method == "POST":
        # if method is post add comment to db and send user to search/book "get" method
        if not request.form.get("rating"):
            return render_template("error.html", message = "must submit a rating")
        if not request.form.get("review"):
            return render_template("error.html", message = "must submit a review")
        db.execute("INSERT INTO comments (userid,bookid,review,rating) VALUES(:userid,:bookid,:review,:rating)",{"userid":session["user_id"],"bookid":book_id,"review":request.form.get("review"),"rating":request.form.get("rating")})
        db.commit()
        return redirect(f"/search/{book_id}")
    if request.method == "GET":
        #if method is get go grab the ratings and reviews from db/api and show them on the books webpage
        bats = db.execute("SELECT * FROM books WHERE books.id = :book_id",{"book_id":book_id}).fetchone()
        jim = requests.get("https://www.goodreads.com/book/review_counts.json", params={"key":"jPaOEGt4V2tESVflVGY2g", "isbns": bats.ibsn})
        jim = jim.json()
        hats = db.execute("SELECT username,rating,review FROM comments JOIN users ON users.id = comments.userid WHERE comments.bookid = :book_id",{"book_id":book_id}).fetchall()
        crush =  db.execute("SELECT COUNT(*) AS count_1 FROM comments WHERE comments.bookid = :book_id",{"book_id":book_id}).fetchone()
        armor = int(jim["books"][0]["ratings_count"])
        ham = float(jim["books"][0]["average_rating"]) * armor
        for hat in hats:
            ham += hat.rating
        ham /= (crush.count_1 + armor)
        jims = {"ratings":jim["books"][0]["ratings_count"] + crush.count_1,"avg": usd(ham)}
        return render_template("hats.html", hats = hats, good = jims, bats = bats,book_id = book_id)



@app.route("/register",methods=["GET","POST"])
def register():
    session.clear()
    if request.method == "POST":
        # if method is post add user to db and then return if it was successful or not
        if not request.form.get("username"):
            return render_template("error.html", message = "Must Provide a Username YOU STUPID!!!")
        if not request.form.get("password"):
            return render_template("error.html", message = "Must Provide A Password You Stupid")
        password = request.form.get("password")
        result = db.execute("SELECT * FROM users WHERE username = :username",{"username":request.form.get("username")}).fetchone()
        if result:
            return render_template("error.html",message ="Username Taken")
        db.execute("INSERT INTO users (username,password) VALUES (:username,:password)",{"username":request.form.get("username"),"password":password})
        db.commit()
        results = db.execute("SELECT id FROM users WHERE username = :username",{"username":request.form.get("username")}).fetchone()
        session["user_id"]= results.id
        return render_template("registered.html")
    else:
        #if method is get return register webpage
        return render_template("register.html")

@app.route("/logout",methods =["GET", "POST"])
def logout():
    #logs the user out of the website
    session.clear()

    return redirect("/")

@app.route("/api/<int:isbn>")
def test(isbn):
    chase = db.execute("SELECT * FROM books WHERE books.ibsn = :ibsn",{"ibsn":f"{isbn}"}).fetchone()
    vinny = db.execute("SELECT COUNT(rating) AS review_count FROM comments WHERE comments.bookid = :bookid",{"bookid":chase.id}).fetchone()
    minny = db.execute("SELECT AVG(rating) AS avg FROM comments WHERE comments.bookid = :bookid",{"bookid":chase.id}).fetchone()
    thief = {"title": chase.title,"author": chase.author,"year": chase.year,"isbn":isbn,"review_count":vinny.review_count,"average_score":f"{usd(minny.avg)}"}
    return jsonify(thief)
