import cs50


def main():
    # Prompt user for input string
    while True:
        text = cs50.get_string("Text: ")
        # If input string is not empty, break
        if text != "":
            break

    # Get coleman index and print result
    print(get_coleman_index(text))


# Function to generate & return values for total letters, words and sentences using same loop for efficiency
def get_counts(s):
    # Iterate over chars in string. Increment letter_count every time that char.isalpha() == True (or 1)
    letter_count = sum(1 for char in s if char.isalpha())

    # Get length of word list resulting from splitting the input string
    word_count = len(s.split())

    # Count the number of sentence-ending punctuation marks to get sentence_count
    sentence_count = 0
    for c in s:
        if c == "." or c == "!" or c == "?":
            sentence_count += 1

    # Return all count results
    return letter_count, word_count, sentence_count


# Function to calculate the Coleman Index for a given string
def get_coleman_index(s):
    # Declare and populate return values for all counts using get_counts function
    letter_count, word_count, sentence_count = get_counts(s)

    # Generate values for letters and sentences per 100 words
    L = (letter_count / word_count) * 100
    S = (sentence_count / word_count) * 100

    # Evaluate for Coleman Index value
    coleman_index = round(0.0588 * L - 0.296 * S - 15.8)

    # Return the corresponding return value
    if coleman_index < 1:
        return "Before Grade 1"
    elif 1 <= coleman_index <= 16:
        return f"Grade {coleman_index}"
    else:
        return "Grade 16+"


# Run the main function
main()
