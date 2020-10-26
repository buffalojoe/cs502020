#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int ("Height: ");
    }
    while (height <= 0 || height > 8);

    for (i = 0; i < height; row++)
    {
        printf("#");
    }
    printf("\n");
}