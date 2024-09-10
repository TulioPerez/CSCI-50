# python dna.py databases/small.csv sequences/2.txt

import csv
import sys

def main():

    # TODO: Check for correct command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py DATABASE_file.csv SEQUENCE_file.csv")

    else:
        # TODO: Read database file into a variable
        # Create empty list to store dictionaries
        rows = []
        # Open database csv file as file ("with open" will auto close the file afterwards)
        with open(sys.argv[1]) as file:
            # Read csv file's data and create dict for each row (key = column header; value = corresponding value in each row)
            database = csv.DictReader(file)

            for row in database:
                rows.append(row)
                # print(row)

            # For debugging - print all column headers
            # print(database.fieldnames)



        # TODO: Read DNA sequence & copy file into a variable
        with open(sys.argv[2], 'r') as file2:
            sequence = file2.read()
            # print(sequence)


        # TODO: Find longest match of each STR in DNA sequence
        # Create dict to store all STR counts
        strands = {'AGATC': 0, 'AATG': 0, 'TATC': 0}

        # Loop through strand keys and increment counts for each strand found in sequence
        for key in strands.keys():
            # strands[key] = sequence.count(key)
            longest_run = 0
            current_run = 0

            for char in sequence:
                if char == key[0]:
                    current_run += 1
                    longest_run = max(longest_run, current_run)
                else:
                    current_run = 0

            strands[key] = longest_run
        print(strands)


        # TODO: Check database for matching profiles
        print(f"AGATC: ", {strands['AGATC']}, "AATG: ", {strands['AATG']}, "TATC: ", {strands['TATC']})

        for row in rows:
            if strands['AGATC'] == rows[1] and strands['AATG'] == rows[2] and strands['TATC'] == rows[3]:
                print(f"Math found! It's ", {rows['name']})
                return

        print("No match found!")
                # print(f"1: ", rows[1], "2: ", rows[2], "3: ", rows[3])
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
