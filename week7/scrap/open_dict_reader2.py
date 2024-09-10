import csv

with open("study.csv", "r") as file:
    reader = csv.DictReader(file)

    # create new dict called counts
    counts = {}

    for row in reader:
        language = row["language"]

        # if language is found as a key in counts, increment its value in the counts dict
        if language in counts:
            counts[language] += 1

        # if not a language in counts, initialize its value to 1
        else:
            counts[language] = 1

# # print the counts alphabetized
# for language in sorted(counts):
#     print(f"{language}: {counts[language]}")

# print the counts sorted by language's count value and reverse the list so that highest is first
for language in sorted(counts, key=counts.get, reverse=True):
    print(f"{language}: {counts[language]}")
