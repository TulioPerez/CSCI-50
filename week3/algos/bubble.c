// Repeat n-1 times (last item will automatically be in correct place, so n-1 instead of just n)
//      For i from 0 to n-2
//          If numbers[i] and numbers[i+2] are out of order
//              Swap them
//      If no swaps occur
//          Quit

// O(n^2)

#include <cs50.h>
#include <stdio.h>

// Define size
#define SIZE 5

int main(void)
{
    int numbers[SIZE] = {0, 2, 1, 3, 4};

    // Print unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i", numbers[i]);
    }
    printf("\n");

    // Sort array with Bubble Sort
    for (int i = 0; i < SIZE; i++)
    {
        bool swaps = false;

        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swaps = true;
            }
        }

        if (swaps == false)
        {
            break;
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i", numbers[i]);
    }
    printf("\n");
}