from flask import Flask, render_template, request

app = Flask(__name__)


# define route and method to handle get and post:
#  GET for default index and POST for form submission
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method=="POST":
        name = request.form.get("name", "world")
        return render_template("greet.html", name=name)

    return render_template("index.html")
