import os

from flask import Flask, redirect, render_template, request, session
from flask_socketio import SocketIO, emit
from flask_session import Session
from helpers import login_required
import csv
import random
import time

app = Flask(__name__)
app.config["SECRET_KEY"] = os.getenv("SECRET_KEY")
app.config['DEBUG'] = True
socketio = SocketIO(app)

#config session
app.config["SESSION_PERMANENT"] = True
#creates a permanent session and stores it in the users memory
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


#room names
rooms = set()
roomsdict = {}


@app.route("/")
@login_required
def index():
    return render_template("index.html", title  = "Rooms", rooms = rooms)

@app.route("/rooms/<string:reddead>", methods = ["GET"])
@login_required
def room(reddead):
    try:
        charles = session[f"{reddead}"]
    except:
        session[f"{reddead}"] = hex(random.randint(0,16777216))
    try:
        return render_template("chat.html", chats = roomsdict[f"{reddead}"], title = "Rooms")
    except:
        roomsdict.update({f"{reddead}":[]})
        return render_template("chat.html", chats = roomsdict[f"{reddead}"], title = "Rooms")

@socketio.on("chat")
def chat(chat):
    timestamp = time.localtime()
    coffee = str(chat["url"][28:].strip("?"))
    if len(roomsdict[coffee]) > 99:
        roomsdict[coffee].remove(roomsdict[coffee][0])
    roomsdict[coffee].append({"name":session["username"],"message":chat["text"],"timestamp":time.strftime("%H:%M:%S", timestamp),"color":f"#{session[coffee].strip('0x')}"})
    emit("chatted",{"name":session["username"],"message":chat["text"],"timestamp":time.strftime("%H:%M:%S", timestamp),"color":f"#{session[coffee].strip('0x')}"}, broadcast = True)




@app.route("/create", methods = ["GET", "POST"])
@login_required
def create():
    if request.method == "POST":
        if not request.form.get("room"):
            return render_template("error.html", message = "You must submit a room")
        if request.form.get("room") in rooms:
            return render_template("error.html", message = "room already created")
        rooms.add(request.form.get("room").strip(" ").strip("?"))
        return redirect(f"/rooms/{request.form.get('room')}")
    if request.method == "GET":
        return render_template("create.html", title = "Rooms")

@socketio.on("check")
def check(check):
    jimmy = True
    if check["type"] == "Room Name":
        if check["name"].strip(" ").strip("?") not in rooms:
            emit('checked', {"success":True} , broadcast =  True)
        else:
            emit('checked', {"success":False} , broadcast =  True)
    else:
        with open("usernames.csv", newline = '') as cfile:
            file = csv.reader(cfile)
            for row in file:
                if check["name"] == row[0]:
                    jimmy = False
        if jimmy:
            emit('checked', {"success":True} , broadcast =  True)
        else:
            emit('checked', {"success":False} , broadcast =  True)

@app.route('/login', methods = ["GET","POST"])
def register():
    if request.method == "POST":
        if not request.form.get("name"):
            return render_template("error.html", message = "must submit a name")
        with open("usernames.csv", newline = '') as cfile:
            file = csv.reader(cfile)
            for row in file:
                if request.form.get("name") == row[0]:
                    return render_template("error.html", message = "username taken")
        with open("usernames.csv", "a", newline = '') as bob:
            file = csv.writer(bob)
            file.writerow([f'{request.form.get("name")}'])
        session["username"] = request.form.get("name")
        return redirect("/")
    if request.method == "GET":
        return render_template("name.html", title = "Rooms")




if __name__ == '__main__':
    app.run(debug=True, host="0.0.0.0")
