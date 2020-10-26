#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompts the user for their first name then returns Hello, <input>
    string firstname = get_string("What is your name?\n");
    printf("Hello, %s\n", firstname);
}