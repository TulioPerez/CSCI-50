import csv

with open("languages.csv") as file:
    reader = csv.reader(file)
    next(reader)
    

    for row in reader:
        print(row[0])
