import csv
from collections import Counter

# same as open_dict_reader2 but with built-in object Counter
with open("study.csv", "r") as file:
    reader = csv.DictReader(file)
    # create new dict called counts
    counts = Counter()

    for row in reader:
        # isolate every language key in every row
        language = row["language"]
        # initialize or increment counter's indexed language
        counts[language] += 1

# # print the counts alphabetized
# for language in sorted(counts):
#     print(f"{language}: {counts[language]}")

# print the counts sorted by language's count value using Counter's built-in sorting method
for language, count in counts.most_common():
    print(f"{language}: {counts[language]}")
