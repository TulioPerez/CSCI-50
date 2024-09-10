import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE_file.csv SEQUENCE_file.csv")

    # TODO: Read database file into a variable
    # Open database csv file as file ("with open" auto closes the file after opening)
    with open(sys.argv[1]) as file:
        database = list(csv.DictReader(file))

    # Open read and save sequence as file
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Create dict to keep count of each strand max count
    strand_match = {}

    # Iterate through each element in first row of database list
    for i in database[0]:
        # Set strand_match to longest run of  STR in sequence
        strand_match[i] = longest_match(sequence, i)

    # TODO: Check database for matching profiles
    # Default return value
    person = "No Match"

    # Keep count of matching STR values for person in database (value at 0 is 'name')
    person_count = 1

    # Iterate through indexes in rows of database
    for i in range(len(database)):
        # Iterate through keys (STR) in strand matches
        for j in strand_match:
            # Check for match of person and strand count
            if str(strand_match[j]) == database[i][j]:
                person_count += 1

        # Match found! - set person to value and print result
        if person_count == len(strand_match):
            person = database[i]["name"]
            break
        else:
            # Reset Counter
            person_count = 1
    print(person)
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
