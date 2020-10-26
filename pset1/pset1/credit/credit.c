#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long ccInput;
    do
    {
        ccInput = get_long("Credit Card Number: \n");
    }
    while (ccInput < 0);

    long ccNumber = ccInput;
    int digits = 0;

    while (ccInput > 0)
    {
        ccInput /= 10;
        digits++;
    }

    if (digits != 13 && digits != 15 && digits != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        
        int ccDigits[digits];
        for (int i = 0; i < digits; i++)
        {
            ccDigits[i] = ccNumber % 10;
            ccNumber /= 10;
        }
    
        int d1 = 0;
        int d2 = 0;
        int sumTemp = 0;
        int sum1 = 0;
        for (int i = 1; i < digits; i = i + 2)
        {
            sumTemp = (ccDigits[i] * 2);
            if (sumTemp >= 10)
            {
                d1 = sumTemp / 10;
                d2 = sumTemp % 10;
                sumTemp = d1 + d2;
            }
            sum1 = sum1 + sumTemp;
        }
    
        int sum2 = 0;
        for (int i = 0; i < digits; i = i + 2)
        {
            sum2 = sum2 + ccDigits[i];
        }
    
        int sumfinal = sum1 + sum2;
        if (sumfinal % 10 != 0)
        {
            printf("INVALID\n");
        }
        else
        {
            if ((digits == 13 || digits == 16) && (ccDigits[12] == 4 || ccDigits[15] == 4))
            {
                printf("VISA\n");
            }
            else if ((digits == 15 && ccDigits[14] == 3) && (ccDigits[13] == 4 || ccDigits[13] == 7))
            {
                printf("AMEX\n");
            }
            else if ((digits == 16 && ccDigits[15] == 5) && 
                     (ccDigits[14] == 1 || ccDigits[14] == 2 || ccDigits[14] == 3 || ccDigits[14] == 4 || ccDigits[14] == 5))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}


