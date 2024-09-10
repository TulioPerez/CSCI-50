#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Prompt user for raw file if not entered as argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE.raw\n");
        return 1;
    }

    // Input filename provided - set pointer to input file name and null check
    char *input_filename = argv[1];
    FILE *input_file_pointer = fopen(input_filename, "r");

    if (input_file_pointer == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }

    // Define buffer as an array of 512 bytes
    int BUFFER_SIZE = 512;
    BYTE buffer[BUFFER_SIZE];

    // Counter for file naming convention
    int image_counter = 0;

    // Pointer for image file to be written to
    FILE *new_image_pointer = NULL;

    // Name of new image file
    char image_filename[8];

    // While fread returns 512 bytes, create jpg's from data
    while (fread(buffer, 1, BUFFER_SIZE, input_file_pointer) == BUFFER_SIZE)
    {
        // Check for jpg signature values
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if current jpg is not NULL (not first one being processed)
            if (new_image_pointer)
            {
                // It's not first image being processed - close previous file
                fclose(new_image_pointer);
            }

            // Initialize jpg filename with number suffix
            sprintf(image_filename, "%03i.jpg", image_counter);

            // Open new image file for writing
            new_image_pointer = fopen(image_filename, "w");

            // Increment image counter
            image_counter++;
        }

        // If file exists, write to it
        if (new_image_pointer)
        {
            fwrite(buffer, 1, BUFFER_SIZE, new_image_pointer);
        }
    }

    // Close previously open image file
    if (new_image_pointer)
    {
        fclose(new_image_pointer);
    }

    // Close input file
    fclose(input_file_pointer);
    return 0;
}