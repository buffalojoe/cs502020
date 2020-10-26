#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i;
    int j;


    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            float localAvg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            image[i][j].rgbtRed = image[i][j].rgbtGreen =  image[i][j].rgbtBlue = round(localAvg);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i;
    int j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp[height][width];

            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = temp[i][j].rgbtRed;

            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = temp[i][j].rgbtGreen;

            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i;
    int j;
    RGBTRIPLE blur[height][width];
    float localAvg;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {


            if (i == 0 && j == 0)
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                            image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                             image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.0);
            }
            else if ((i == 0) && (j == width - 1))
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
                                            image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 4.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                             image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4.0);
            }
            else if ((i == height - 1) && (j == 0))
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed +  image[i - 1][j].rgbtRed +
                                            image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 4.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                              image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 4.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                                             image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 4.0);
            }
            else if ((i == height - 1) && (j == width - 1))
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed +
                                            image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed) / 4.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen +
                                              image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen) / 4.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue +
                                             image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue) / 4.0);
            }
            else if (i == 0 && j > 0)
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                            image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 6.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                             image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.0);
            }
            else if (i > 0 && j == 0)
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed +
                                            image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i - 1][j].rgbtRed) / 6.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen +
                                              image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen) / 6.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue +
                                             image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue) / 6.0);
            }
            else if (i > 0 && (j == width - 1))
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                            image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed) / 6.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                              image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen) / 6.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                             image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue) / 6.0);
            }
            else if ((i == height - 1) && j > 0)
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed +
                                            image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 6.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
                                              image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                                             image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.0);
            }
            else
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1]
                                            [j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j - 1].rgbtRed +
                                            image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 9.0);

                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1]
                                              [j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
                                              image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 9.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1]
                                             [j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                                             image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 9.0);
            }
        }
    }
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = blur[i][j].rgbtRed;
            image[i][j].rgbtGreen = blur[i][j].rgbtGreen;
            image[i][j].rgbtBlue = blur[i][j].rgbtBlue;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int i;
    int j;
    float gx;
    float gy;
    RGBTRIPLE edge[height][width];

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                gx = ((image[i][j + 1].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                gy = ((image[i + 1][j].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                float redCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                gy = ((image[i + 1][j].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                float greenCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));
                gy = ((image[i + 1][j].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));
                float blueCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                edge[i][j].rgbtRed = redCompute > 255 ? 255 : round(redCompute);
                edge[i][j].rgbtGreen = greenCompute > 255 ? 255 : round(greenCompute);
                edge[i][j].rgbtBlue = blueCompute > 255 ? 255 : round(blueCompute);

            }
            else if ((i == 0) && (j == width - 1))
            {
                gx = ((image[i][j - 1].rgbtRed * -2) - (image[i + 1][j - 1].rgbtRed));
                gy = ((image[i + 1][j].rgbtRed * 2) + (image[i + 1][j - 1].rgbtRed));
                float redCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j - 1].rgbtGreen * -2) - (image[i + 1][j - 1].rgbtGreen));
                gy = ((image[i + 1][j].rgbtGreen * 2) + (image[i + 1][j - 1].rgbtGreen));
                float greenCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j - 1].rgbtBlue * -2) - (image[i + 1][j - 1].rgbtBlue));
                gy = ((image[i + 1][j].rgbtBlue * 2) + (image[i + 1][j - 1].rgbtBlue));
                float blueCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                edge[i][j].rgbtRed = redCompute > 255 ? 255 : round(redCompute);
                edge[i][j].rgbtGreen = greenCompute > 255 ? 255 : round(greenCompute);
                edge[i][j].rgbtBlue = blueCompute > 255 ? 255 : round(blueCompute);
            }
            else if ((i == height - 1) && (j == 0))
            {
                gx = ((image[i][j + 1].rgbtRed * 2) + (image[i - 1][j + 1].rgbtRed));
                gy = ((image[i - 1][j].rgbtRed * -2) - (image[i - 1][j + 1].rgbtRed));
                float redCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j + 1].rgbtGreen * 2) + (image[i - 1][j + 1].rgbtGreen));
                gy = ((image[i - 1][j].rgbtGreen * -2) - (image[i - 1][j + 1].rgbtGreen));
                float greenCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j + 1].rgbtBlue * 2) + (image[i - 1][j + 1].rgbtBlue));
                gy = ((image[i - 1][j].rgbtBlue * -2) - (image[i - 1][j + 1].rgbtBlue));
                float blueCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                edge[i][j].rgbtRed = redCompute > 255 ? 255 : round(redCompute);
                edge[i][j].rgbtGreen = greenCompute > 255 ? 255 : round(greenCompute);
                edge[i][j].rgbtBlue = blueCompute > 255 ? 255 : round(blueCompute);
            }
            else if ((i == height - 1) && (j == width - 1))
            {
                gx = ((image[i][j - 1].rgbtRed * -2) - (image[i - 1][j - 1].rgbtRed));
                gy = ((image[i - 1][j].rgbtRed * -2) - (image[i - 1][j - 1].rgbtRed));
                float redCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j - 1].rgbtGreen * -2) - (+image[i - 1][j - 1].rgbtGreen));
                gy = ((image[i - 1][j].rgbtGreen * -2) - (+image[i - 1][j - 1].rgbtGreen));
                float greenCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j - 1].rgbtBlue * -2) - (image[i - 1][j - 1].rgbtBlue));
                gy = ((image[i - 1][j].rgbtBlue * -2) - (image[i - 1][j - 1].rgbtBlue));
                float blueCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                edge[i][j].rgbtRed = redCompute > 255 ? 255 : round(redCompute);
                edge[i][j].rgbtGreen = greenCompute > 255 ? 255 : round(greenCompute);
                edge[i][j].rgbtBlue = blueCompute > 255 ? 255 : round(blueCompute);
            }
            else if (i == 0 && j > 0)
            {
                gx = ((image[i][j - 1].rgbtRed * -2) - (image[i + 1][j - 1].rgbtRed) +
                      (image[i][j + 1].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                gy = ((image[i + 1][j - 1].rgbtRed) + (image[i + 1][j].rgbtRed * 2) +
                      (image[i + 1][j + 1].rgbtRed));
                float redCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j - 1].rgbtGreen * -2) - (image[i + 1][j - 1].rgbtGreen) +
                      (image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                gy = ((image[i + 1][j - 1].rgbtGreen) + (+image[i + 1][j].rgbtGreen * 2) +
                      (image[i + 1][j + 1].rgbtGreen));
                float greenCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i][j - 1].rgbtBlue * -2) - (image[i + 1][j - 1].rgbtBlue) +
                      (image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));
                gy = ((image[i + 1][j - 1].rgbtBlue) + (image[i + 1][j].rgbtBlue * 2) +
                      (image[i + 1][j + 1].rgbtBlue));
                float blueCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                edge[i][j].rgbtRed = redCompute > 255 ? 255 : round(redCompute);
                edge[i][j].rgbtGreen = greenCompute > 255 ? 255 : round(greenCompute);
                edge[i][j].rgbtBlue = blueCompute > 255 ? 255 : round(blueCompute);
            }
            else if (i > 0 && j == 0)
            {
                gx = ((image[i - 1][j + 1].rgbtRed) + (image[i][j + 1].rgbtRed * 2) +
                      (image[i + 1][j + 1].rgbtRed));
                gy = ((-image[i - 1][j + 1].rgbtRed) - (image[i - 1][j].rgbtRed * 2) +
                      (image[i + 1][j + 1].rgbtRed) + (image[i + 1][j].rgbtRed * 2));
                float redCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i - 1][j + 1].rgbtGreen) + (image[i][j + 1].rgbtGreen * 2) +
                      (image[i + 1][j + 1].rgbtGreen));
                gy = ((-image[i - 1][j + 1].rgbtGreen) - (image[i - 1][j].rgbtGreen * 2) +
                      (image[i + 1][j + 1].rgbtGreen) + (image[i + 1][j].rgbtGreen * 2));
                float greenCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((image[i - 1][j + 1].rgbtBlue) + (image[i][j + 1].rgbtBlue * 2) +
                      (image[i + 1][j + 1].rgbtBlue));
                gy = ((-image[i - 1][j + 1].rgbtBlue) - (image[i - 1][j].rgbtBlue * 2) +
                      (image[i + 1][j + 1].rgbtBlue) + (image[i + 1][j].rgbtGreen * 2));
                float blueCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                edge[i][j].rgbtRed = redCompute > 255 ? 255 : round(redCompute);
                edge[i][j].rgbtGreen = greenCompute > 255 ? 255 : round(greenCompute);
                edge[i][j].rgbtBlue = blueCompute > 255 ? 255 : round(blueCompute);
            }
            else if (i > 0 && (j == width - 1))
            {
                gx = ((-image[i - 1][j - 1].rgbtRed) - (image[i][j - 1].rgbtRed * 2) -
                      (image[i + 1][j - 1].rgbtRed));
                gy = ((-image[i - 1][j - 1].rgbtRed) - (image[i - 1][j].rgbtRed * 2) +
                      (image[i + 1][j - 1].rgbtRed) + (image[i + 1][j].rgbtRed * 2));
                float redCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((-image[i - 1][j - 1].rgbtGreen) - (image[i][j - 1].rgbtGreen * 2) -
                      (image[i + 1][j - 1].rgbtGreen));
                gy = ((-image[i - 1][j - 1].rgbtGreen) - (image[i - 1][j].rgbtGreen * 2) +
                      (image[i + 1][j - 1].rgbtGreen) + (image[i + 1][j].rgbtGreen * 2));
                float greenCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((-image[i - 1][j - 1].rgbtBlue) - (image[i][j - 1].rgbtBlue * 2) -
                      (image[i + 1][j - 1].rgbtBlue));
                gy = ((-image[i - 1][j - 1].rgbtBlue) - (image[i - 1][j].rgbtBlue * 2) +
                      (image[i + 1][j - 1].rgbtBlue) + (image[i + 1][j].rgbtBlue * 2));
                float blueCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                edge[i][j].rgbtRed = redCompute > 255 ? 255 : round(redCompute);
                edge[i][j].rgbtGreen = greenCompute > 255 ? 255 : round(greenCompute);
                edge[i][j].rgbtBlue = blueCompute > 255 ? 255 : round(blueCompute);
            }
            else if ((i == height - 1) && j > 0)
            {
                gx = ((-image[i - 1][j - 1].rgbtRed) - (image[i][j - 1].rgbtRed * 2) +
                      (image[i - 1][j + 1].rgbtRed) + (image[i][j + 1].rgbtRed * 2));
                gy = ((-image[i - 1][j - 1].rgbtRed) - (image[i - 1][j].rgbtRed * 2) -
                      (image[i - 1][j + 1].rgbtRed));
                float redCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((-image[i - 1][j - 1].rgbtGreen) - (image[i][j - 1].rgbtGreen * 2) +
                      (image[i - 1][j + 1].rgbtGreen) + (image[i][j + 1].rgbtGreen * 2));
                gy = ((-image[i - 1][j - 1].rgbtGreen) - (image[i - 1][j].rgbtGreen * 2) -
                      (image[i - 1][j + 1].rgbtGreen));
                float greenCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((-image[i - 1][j - 1].rgbtBlue) - (image[i][j - 1].rgbtBlue * 2) +
                      (image[i - 1][j + 1].rgbtBlue) + (image[i][j + 1].rgbtBlue * 2));
                gy = ((-image[i - 1][j - 1].rgbtBlue) - (image[i - 1][j].rgbtBlue * 2) -
                      (image[i - 1][j + 1].rgbtBlue));
                float blueCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                edge[i][j].rgbtRed = redCompute > 255 ? 255 : round(redCompute);
                edge[i][j].rgbtGreen = greenCompute > 255 ? 255 : round(greenCompute);
                edge[i][j].rgbtBlue = blueCompute > 255 ? 255 : round(blueCompute);
            }
            else
            {
                gx = ((-image[i - 1][j - 1].rgbtRed) - (image[i][j - 1].rgbtRed * 2) - (image[i + 1][j - 1].rgbtRed) +
                      (image[i - 1][j + 1].rgbtRed) + (image[i][j + 1].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                gy = ((-image[i - 1][j - 1].rgbtRed) - (image[i - 1][j].rgbtRed * 2) - (image[i - 1][j + 1].rgbtRed) +
                      (image[i + 1][j - 1].rgbtRed) + (image[i + 1][j].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed));
                float redCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((-image[i - 1][j - 1].rgbtGreen) - (image[i][j - 1].rgbtGreen * 2) - (image[i + 1][j - 1].rgbtGreen) +
                      (image[i - 1][j + 1].rgbtGreen) + (image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                gy = ((-image[i - 1][j - 1].rgbtGreen) - (image[i - 1][j].rgbtGreen * 2) - (image[i - 1][j + 1].rgbtGreen) +
                      (image[i + 1][j - 1].rgbtGreen) + (image[i + 1][j].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen));
                float greenCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                gx = ((-image[i - 1][j - 1].rgbtBlue) - (image[i][j - 1].rgbtBlue * 2) - (image[i + 1][j - 1].rgbtBlue) +
                      (image[i - 1][j + 1].rgbtBlue) + (image[i][j + 1].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));
                gy = ((-image[i - 1][j - 1].rgbtBlue) - (image[i - 1][j].rgbtBlue * 2) - (image[i - 1][j + 1].rgbtBlue) +
                      (image[i + 1][j - 1].rgbtBlue) + (image[i + 1][j].rgbtBlue * 2) + (image[i + 1][j + 1].rgbtBlue));
                float blueCompute = sqrt(pow(gx, 2) + (pow(gy, 2)));

                edge[i][j].rgbtRed = redCompute > 255 ? 255 : round(redCompute);
                edge[i][j].rgbtGreen = greenCompute > 255 ? 255 : round(greenCompute);
                edge[i][j].rgbtBlue = blueCompute > 255 ? 255 : round(blueCompute);
            }
        }
    }
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = edge[i][j].rgbtRed;
            image[i][j].rgbtGreen = edge[i][j].rgbtGreen;
            image[i][j].rgbtBlue = edge[i][j].rgbtBlue;
        }
    }
}
