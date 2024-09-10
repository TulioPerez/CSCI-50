from flask import Flask, render_template, request

# tell framework to treat app.py as a web application:

# make app == return value of FLask function; pass in name of this file
app = Flask(__name__)


# as argument to the following route function, specify the route for which we are implementing some code - "/" is the default
@app.route("/")

# define function:
def index():

    # 1 display python
    # run python file - 'show source' shows text of python file:
    # return "hello, world"

    # 2 display html via flask
    # run from templates folder - 'show source' shows actual html:
    # return render_template("index.html")

    # 3 display html via flask & insert kvp's
    # run from templates folder - use jinja placeholder to display data in html:
    # args is a dict that comes with flask - when reuest to server is made, it puts all the key value pairs of the url
    name = request.args.get("name", "world")

    # make placeholder in index == name, defined above
    return render_template("index.html", placeholder=name)
