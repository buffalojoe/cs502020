#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("How much change is owed? ");
    }
    while (change < 0);

    int cents = round(change * 100);
    int coins = 0;
    int quarter, dime, nickel, penny;
    quarter = 25;
    dime = 10;
    nickel = 5;
    penny = 1;

    while (cents >= quarter)
    {
        cents = cents - quarter, coins++;
    }
    while (cents >= dime)
    {
        cents = cents - dime, coins++;
    }
    while (cents >= nickel)
    {
        cents = cents - nickel, coins++;
    }
    while (cents >= penny)
    {
        cents = cents - penny, coins++;
    }
    printf("Coins = %i\n", coins);
}