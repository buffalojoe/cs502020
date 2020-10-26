#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = i + 1; j < height; j++)
        {
            printf(" ");
        }
        for (int z = height - i - 1; z < height; z++)
        {
            printf("#");
        }
        printf("  ");
        for (int z = height - i - 1; z < height; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}