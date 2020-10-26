#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int h = hash(word);

    node *cursor = table[h];

    if (table[h] == NULL)
    {
        return false;
    }

    while (strcasecmp(cursor->word, word) != 0)
    {
        cursor = cursor->next;

        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else if (cursor->next == NULL)
        {
            return false;
        }
        else if (cursor->next != NULL && strcasecmp(cursor->word, word) != 0)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long h = 5381;
    int c;

    while (c = *str++)
        h = ((h << 5) + h) + c;

    return h;
}

int word_count = 0;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Declares a file pointer that points to a dictionary file opened for reading
    FILE *dictptr = fopen(dictionary, "r");
    // Checks that the file opened successfully
    if (dictptr == NULL)
    {
        return false;
    }

    // Scan dictionary word by word until the End Of File is reached
    char word[LENGTH + 1];
    while (fscanf(dictptr, "%s", word) != EOF)
    {
        // For each word, create a new node
        node *n = malloc(sizeof(node));
        // Verify that memory allocated successfully
        if (n == NULL)
        {
            return false;
        }

        // Copy the most recently read word into the new node
        strcpy(n->word, word);

        // Run the word through a hash function
        int h = hash(n->word);

        // Initialize a head to point to the hashtable index calculated with the
        //  function above
        node *head = table[h];

        if (head == NULL)
        {
            table[h] = n;
            word_count++;
        }
        else
        {
            n->next = table[h];
            table[h] = n;
            word_count++;
        }
    }

    fclose(dictptr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        node *cursor = table[i];
        node *temp = table[i];

        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }

    return true;
}