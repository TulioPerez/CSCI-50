// Declares a dictionary's functionality

// This ensures that clang will only compile the following once
#ifndef DICTIONARY_H
#define DICTIONARY_H

// Include bool - defined elsewhere in the project
#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Function prototypes
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
