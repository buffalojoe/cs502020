#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
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

        if (cursor == NULL)
        {
            return false;
        }
    }

    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int h = (int) tolower(word[0]);
    return h;
    /*unsigned long h = 5381;
    int c = 0;

    while (c == *word++)
        h = ((h << 5) + h) + tolower(c);

    return h % N;*/
}

int word_count = 0;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dictptr = fopen(dictionary, "r");

    if (dictptr == NULL)
    {
        return false;
    }

    char word[LENGTH];
    while (fscanf(dictptr, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        int h = hash(n->word);

        node *head = table[h];

        n->next = table[h];
        table[h] = n;
        word_count++;
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

        free(cursor);

    }

    return true;
}
