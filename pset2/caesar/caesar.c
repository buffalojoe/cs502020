#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }

    int argLen = strlen(argv[1]);
    int digitChecker = 0;

    for (int t = 0; t < argLen - 1; t++)
    {
        if (!isalpha(argv[1][t]))
        {
            ++digitChecker;
        }
        if (digitChecker > 0)
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }

    string plaintext = get_string("plaintext: ");
    int key = atoi(argv[1]);
    int plainlength = strlen(plaintext);
    int cipherarray[plainlength];

    for (int i = 0; i < plainlength; i++)
    {
        if ((int) plaintext[i] >= 65 && (int) plaintext[i] <= 90)
        {
            cipherarray[i] = (int) plaintext[i] + key;
            if (cipherarray[i] > 90)
                do
                {
                    cipherarray[i] -= 26;
                }
                while (cipherarray[i] > 90);
        }
        else if ((int) plaintext[i] >= 97 && (int) plaintext[i] <= 122)
        {
            cipherarray[i] = (int) plaintext[i] + key;
            if (cipherarray[i] > 122)
                do
                {
                    cipherarray[i] -= 26;
                }
                while (cipherarray[i] > 122);
        }
        else
        {
            cipherarray[i] = (int) plaintext[i];
        }
    }

    printf("ciphertext: ");
    for (int j = 0; j < plainlength; j++)
    {
        printf("%c", cipherarray[j]);
    }
    printf("\n");
}