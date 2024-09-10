#include <cs50.h>
#include <stdio.h>

// global variable declarations
long inputNumber = 0;
int firstDigit;
int secondDigit;
int totalDigits;
string cardType;

// method signature declarations
void assignInitialValues(long n);
string checkCardValidity();
bool checkLuhn(long n);

int main(void)
{
    // prompt user to input credit card number to check (auto repeats if anything except digits are entered)
    inputNumber = get_long("Number: ");

    // use inputNumber to assign values to totalDigits, firstDigit & secondDigit
    assignInitialValues(inputNumber);
    checkCardValidity(inputNumber);
}

// helper function that assigns totalDigits, firstDigit & secondDigit
void assignInitialValues(long n)
{
    // incrementally remove the last digit from the number until there are only 2 digits left
    while (n >= 100)
    {
        n /= 10;
        // assign last 2 digits to secondDigit, initially
        secondDigit = n;
        totalDigits++;
    }

    // perform modulus operator one more time to get the first digit
    firstDigit = n / 10;

    // isolate the second digit by subtracting the first digit
    secondDigit = (n - (firstDigit * 10));

    // account for these remaining 2 digits in totalDigit count
    totalDigits += 2;
}

// driver function that determines eligibility of a card
string checkCardValidity()
{
    // assign cardType variable value if inputNumber is a valid combination of initial and total digits
    // check for AMEX card number conventions
    if (totalDigits == 15 && (firstDigit == 3 && ((secondDigit == 4 || secondDigit == 7))))
    {
        cardType = "AMEX";
    }

    // check for MASTERCARD card number conventions
    else if (totalDigits == 16 && ((firstDigit == 5 && (secondDigit == 1 || secondDigit == 2 || secondDigit == 3 ||
                                                        secondDigit == 4 || secondDigit == 5)) ||
                                   (firstDigit == 2 && secondDigit == 2)))
    {
        cardType = "MASTERCARD";
    }

    // check for VISA card number conventions
    else if ((totalDigits == 13 || totalDigits == 16) && firstDigit == 4)
    {
        cardType = "VISA";
    }

    else
    {
        // cancel further checks and return "INVALID" card type
        cardType = "INVALID";
        printf("%s\n", cardType);
        return cardType;
    }

    // card passed initial checks - continue with Luhn's Algorithm check
    if (checkLuhn(inputNumber))
    {
        printf("%s\n", cardType);
        return cardType;
    }
    else
    {
        // card failed Luhn's Algorithm check - return "INVALID" card type
        cardType = "INVALID";
        printf("%s\n", cardType);
        return cardType;
    }
}

// helper function to check card number for Luhn's Algorithm
bool checkLuhn(long n)
{
    // initialize variables for odd and even digits, as well as a temp variable used in algorithm
    int oddSum = 0;
    int evenSum = 0;
    int temp;

    // outer loop to isolate individual digits in inputNumber
    for (int i = 0; n > 0; i++)
    {
        // isolate last digit
        temp = n % 10;

        // if its index is odd - multiply by 2
        if (i % 2 != 0)
        {
            // multiply temp by 2
            temp *= 2;
            // if temp has 2 digits, add digits individually to oddSum:
            if (temp > 9)
            {
                // add first digit
                oddSum += temp % 10;
                temp /= 10;

                // add second digit
                oddSum += temp;
            }

            // temp is only 1 digit - add to oddSum
            else
            {
                oddSum += temp;
            }
        }

        // digit's index is even - add to evenSum
        else
        {
            evenSum += temp;
        }
        // remove isolated digit from inputNumber
        n /= 10;
    }

    // is modulus 10 of oddSum and evenSum == 0?
    if ((oddSum + evenSum) % 10 == 0)
    {
        // yes - test passed
        return true;
    }
    else
    {
        // no - test failed
        return false;
    }

    return false;
}
