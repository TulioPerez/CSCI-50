// copy from file to file
#include <stdio.h>
#include <stdint.h>

// raw, unsigned, 8 bit, non-negative value
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // read and write binary data
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;

    // while there are bytes to read in the file 2:43:48
    // get bytes from address of b
    // copy 1 byte at a time
    // read bytes from source file
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}