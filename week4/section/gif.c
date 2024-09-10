#include <stdbool.h>
#include <stdio.h>


// constant used to compare to gid filename
const char signature[6] = {'G', 'I', 'F', '8', 'A'};

bool is_gif(FILE *f);


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./gif filename\n");
        return 1;
    }

    // Open file
    FILE *f = fopen(argv[1], "r");

    // if file is null
    if (!f)
    {
        printf("Could not retrieve file.\n");
    }

    // Check for Gif signature
    if (is_gif(f))
    {
        printf("Gif\n");
    }

    else
    {
        printf("NOT Gif\n");
    }

    // Close the file
    fclose(f);
}



bool is_gif(FILE *f)
{
    // Read bytes into buffer
    unsigned char buffer[6];
    int bytes = fread(buffer, 1, 6, f);

    // Check number of bytes read
    if (bytes != 6)
    {
        // it was not a proper gif file
        return false;
    }

    // Check that each byte matches
    for (int i = 0; i < 6; i++)
    {
        if (buffer[i] != signature[i])
        {
            // No match
            return false;
        }
    }
    return true;
}