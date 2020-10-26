#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Checks that the user only enters one CLA. The CLA must be an upper- or lowercase combination of
    //  26 letters, containing each letter of the alphabet and no duplicates.
    if (argc == 2)
    {
        int duplicate = 0;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (strlen(argv[1]) != 26 || (!isalpha(argv[1][i])))
            {
                printf("Key must be 26 characters long and contain only ");
                printf("alphabetical characters.\n");
                exit(1);
            }
            else if ((strlen(argv[1]) == 26) && (duplicate <= 26))
            {
                for (int j = 0; j < strlen(argv[1]); j++)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        ++duplicate;
                    }
                }
                if (duplicate > 26)
                {
                    printf("Key must not contain duplicate alphabetic characters.\n");
                    exit(1);
                }
            }
            else
            {
                continue;
            }
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }

    // PASSED ALL KEY CHECKS -- This portion of the program creates ciphertext from plaintext
    string plaintext = get_string("plaintext: ");
    
    char alphabetLower[] = "abcdefghijklmnopqrstuvwxyz\0";
    char alphabetUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
    int diff[60];

    // Create an array that measures the difference between the key and alphabetical value it replaces
    for (int i = 0; i < 26; i++)
    {
        if (islower(argv[1][i]))
        {
            diff[i] = (int) argv[1][i] - (int) alphabetLower[i];
        }
        else
        {
            diff[i] = (int) argv[1][i] - (int) alphabetUpper[i];
        }
    }

    int ciphertext[150];
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if ((int) plaintext[i] == (int) alphabetLower[j])
                {
                    ciphertext[i] = (int) plaintext[i] + diff[j];
                    break;
                }
            }
        }
        else if (isupper(plaintext[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if ((int) plaintext[i] == (int) alphabetUpper[j])
                {
                    ciphertext[i] = (int) plaintext[i] + diff[j];
                    break;
                }
            }
        }
        else
        {
            ciphertext[i] = (int) plaintext[i];
        }
    }

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", (char) ciphertext[i]);
    }
    printf("\n");
}