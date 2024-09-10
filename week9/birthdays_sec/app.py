import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # TODO error checking
        if not name or not month or not day:
            print("mising name or month or day")
            return redirect("/")

        # TODO month and day must be ints, default is string
        try:
            month = int(month)
        except ValueError:
            return redirect("/")

        try:
            day = int(day)
        except ValueError:
            return redirect("/")

        # TODO Insert into database - auto assigns id and returns it
        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)
        print(f"{name}'s id is {id}")

        return redirect("/")

    else:
        # TODO: Display the entries in the database on index.html
        # query for all bdays
        birthdays = db.execute("SELECT * FROM birthdays")
        print(birthdays)

        return render_template("index.html", birthdays = birthdays)
