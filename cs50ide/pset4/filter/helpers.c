#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int counter, totalRed, totalGreen, totalBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter = 0, totalRed = 0, totalGreen = 0, totalBlue = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        totalRed += temp[i + k][j + l].rgbtRed;
                        totalGreen += temp[i + k][j + l].rgbtGreen;
                        totalBlue += temp[i + k][j + l].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round((float)totalRed / counter);
            image[i][j].rgbtGreen = round((float)totalGreen / counter);
            image[i][j].rgbtBlue = round((float)totalBlue / counter);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int GxRed, GyRed, GxGreen, GyGreen, GxBlue, GyBlue;

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            GxRed = 0, GyRed = 0, GxGreen = 0, GyGreen = 0, GxBlue = 0, GyBlue = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        GxRed += temp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                        GyRed += temp[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];

                        GxGreen += temp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                        GyGreen += temp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];

                        GxBlue += temp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                        GyBlue += temp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                    }
                }
            }

            int red = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            int green = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            int blue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));

            image[i][j].rgbtRed = (red > 255) ? 255 : red;
            image[i][j].rgbtGreen = (green > 255) ? 255 : green;
            image[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }
}

