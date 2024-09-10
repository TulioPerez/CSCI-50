#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>


// constant used to compare to gid filename
const char signature[6] = {'G', 'I', 'F', '8', 'A'};

bool is_gif(FILE *f);


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // Open files
    FILE *infile = fopen(argv[1], "r"); // r = read
    if (!infile)
    {
        return 1;
    }

    FILE *outfile = fopen(argv[2], "w"); // w = write
    if (!outfile)
    {
        return 1;
    }

    while (true)
    {
        char c = fgetc(infile);

        // if end of file
        if (c == EOF)
        {
            break;
        }
        fputc(c, outfile);
    }

    fclose(infile);
    fclose(outfile);
}