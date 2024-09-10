// For i from 0 to n-1
//      Find the smallest number between numbers[i] and numbers[n-1]
//          Swap smallest number with numbers[i]

// O(n^2) because it is linear
// As numbers are sorted, no need to check again from beginning, so (n-1) becomes (n-1) + (n-2)... simply put, this is n(n-1)/2

#include <cs50.h>
#include <stdio.h>

#define SIZE 5

int main(void)
{
    int numbers[SIZE] = {0, 5, 1, 3, 4};

    // Print unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i", numbers[i]);
    }
    printf("\n");

    // Sort array with Selection Sort
    for (int i = 0; i < SIZE - 1; i++)
    {
        int smallest = numbers[i];
        int index = i;

        for (int j = i; j < SIZE; j++)
        {
            if (numbers[j] < smallest)
            {
                smallest = numbers[j];
                index = j;
            }
        }

        int temp = numbers[i];
        numbers[i] = smallest;
        numbers[index] = temp;
    }

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i", numbers[i]);
    }
    printf("\n");
}