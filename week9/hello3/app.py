from flask import Flask, render_template, request

app = Flask(__name__)


# define routes and their methods
@app.route("/")
def index():
    return render_template("index.html")


# methods=["POST"] is required for post to work in html - "get" method is allowed by default
@app.route("/greet", methods=["POST"])
def greet():
    # use request.form so that the name will be visible in the browser when running the code (required by POST)
    name = request.form.get("name", "world")
    return render_template("greet.html", name=name)
