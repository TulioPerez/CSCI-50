#include <stdio.h>
#include <cs50.h>

// I/O commands
// fopen - open a file
// fclose - close a file
// fprintf - print to a file
// fscanf - take in data from a file
// fread - read data from file
// fwrite - write data from a file
// fseek - jump to a different location in a file

int main(void)
{
    // /r = reading /w = writing /a = appending /rb : read binary /wb = write binary
    FILE *file = fopen("phonebook.csv", "a");

    // NULL check if file does not exist
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("number ");

    // print new alues to the file
    fprintf(file, "%s, %s\n", name, number);
    fclose(file);
}