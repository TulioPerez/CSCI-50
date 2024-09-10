import csv

with open("languages.csv", "r") as file:
    reader = csv.DictReader(file)
    prof1, prof2, prof3, prof4, prof5 = 0, 0, 0, 0, 0

    for row in reader:
        prof = row["Proficiency"]
        if prof == "1":
            prof1 += 1
        elif prof == "2":
            prof2 += 1
        elif prof == "3":
            prof3 += 1
        elif prof == "4":
            prof4 += 1
        elif prof == "5":
            prof5 += 1

print(f"1: {prof1}    2: {prof2}    3: {prof3}    4: {prof4}    5: {prof5}")
