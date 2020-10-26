#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Prompts the user for text and counts the number of characters in the text
    string inputtext = get_string("Text: \n");
    int charcount = strlen(inputtext);

    // Determines the number of letters (no symbols or spaces included) in the provided text
    float letters = 0;
    for (int i = 0; i < charcount; i++)
    {
        if (((int) inputtext[i] >= 65 && (int) inputtext[i] <= 90) || ((int) inputtext[i] >= 97 && (int) inputtext[i] <= 122))
        {
            letters++;
        }
    }
    // Determines the number of words in the provided text
    // Counts how many spaces are in the text
    float words = 1;
    for (int i = 0; i < charcount; i++)
    {
        if ((int) inputtext[i] == 32)
        {
            words++;
        }
    }
    //Determines the number of sentences in the provided text by counting periods, exclamation marks, and question marks.
    float sentences = 0;
    for (int i = 0; i < charcount; i++)
    {
        if ((int) inputtext[i] == 33 || (int) inputtext[i] == 46 || (int) inputtext[i] == 63)
        {
            sentences++;
        }    
    }
    
    // Average number of letter per 100 words in the text.
    float L = (100 / words) * letters;
    // Average number of sentences per 100 words in the text.
    float S = (100 / words) * sentences;
    
    // Coleman-Liau Index computation
    float index = (0.0588 * L - 0.296 * S - 15.8);
    int rindex = round(index);
    
    // Prints the appropriate grade level based on the value of C-L Index
    if (rindex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rindex >= 1 && rindex < 16)
    {
        printf("Grade %i\n", rindex);
    }
    else
    {
        printf("Grade 16+\n");
    }
}