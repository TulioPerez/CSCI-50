// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Create pointer of type FILE for input file and determine scaling factor
    FILE *input = fopen(argv[1], "r");

    // Null check input file
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create pointer of type FILE for output file
    FILE *output = fopen(argv[2], "w");

    // Null check the output file
    if (output == NULL)
    {
        printf("Could not open file.\n");
        // fclose(input);
        return 1;
    }

    // Volume amplification factor
    float factor = atof(argv[3]);

    // Create unsigned, 8bit value that is equal to header size
    uint8_t header[HEADER_SIZE];

    // Already null checked - Copy header from input to output file
    fread(&header, HEADER_SIZE, 1, input);
    fwrite(&header, HEADER_SIZE, 1, output);

    // Create buffer to read samples from input file then write data to output file
    int16_t buffer;

    // Read samples from input file and write updated data to output file
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Update volume of sample by amplification factor
        buffer *= factor;

        // write updated sample to new file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files to prevent memory leaks
    fclose(input);
    fclose(output);
}


// personal note -=):
// valgrind ./volume input.wav output.wav 4
