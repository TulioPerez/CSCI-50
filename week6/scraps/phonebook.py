import csv
import sys

if len(sys.argv) != 2:
    sys.exit("Usage: python phonebook.py data.csv")

f = open(sys.argv[1])
reader = csv.DictReader(f)

# check if fields exists by getting field names first:
fields = reader.fieldnames
print(fields)

# if "name" not in fields or "number" not in fields:
#     sys.exit("File must have name and number columns")

persons = []

for row in reader:
    name = row["name"]
    number = row["number"]
    persons.append(row)
    print(f"{name}'s phone number is {number}")

for person in persons:
    name = persons["name"]
    if name == "David":
        print("David's number found")

f.close()
