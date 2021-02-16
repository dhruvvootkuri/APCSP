#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale

int grayscaleavg;

#include <stdio.h>
#include <math.h>
#include <string.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (round(image[i][j].rgbtRed) + round(image[i][j].rgbtBlue) + round(image[i][j].rgbtGreen)) / 3;
            avg = round(avg);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float ogred = image[i][j].rgbtRed;
            float ogblue = image[i][j].rgbtBlue;
            float oggreen = image[i][j].rgbtGreen;
            int sepiared = round(.393 * ogred + .769 * oggreen + .189 * ogblue);
            int sepiagreen = round(.349 * ogred + .686 * oggreen + .168 * ogblue);
            int sepiablue = round(.272 * ogred + .534 * oggreen + .131 * ogblue);
            if (sepiared > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiared;
            }
            if (sepiagreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiagreen;
            }
            if (sepiablue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiablue;
            }
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= (width / 2) - 1; j++)
        {
            //printf("height: %d\n", width);
            //printf("j: %d\n", j);
            int y = width - j - 1;
            int swaptemp1 = image[i][j].rgbtRed;
            int swaptemp2 = image[i][y].rgbtRed;
            swap(&swaptemp1, &swaptemp2);
            image[i][j].rgbtRed = swaptemp1;
            image[i][y].rgbtRed = swaptemp2;

            swaptemp1 = image[i][j].rgbtBlue;
            swaptemp2 = image[i][y].rgbtBlue;
            swap(&swaptemp1, &swaptemp2);
            image[i][j].rgbtBlue = swaptemp1;
            image[i][y].rgbtBlue = swaptemp2;

            swaptemp1 = image[i][j].rgbtGreen;
            swaptemp2 = image[i][y].rgbtGreen;
            swap(&swaptemp1, &swaptemp2);
            image[i][j].rgbtGreen = swaptemp1;
            image[i][y].rgbtGreen = swaptemp2;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Scratch space where we can calculate the averages.
    RGBTRIPLE image_tmp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue_sum = 0;
            float green_sum = 0;
            float red_sum = 0;

            RGBTRIPLE avg;
            int num_values_considered = 1;

            // We need to first consider the pixel itself.
            blue_sum += image[i][j].rgbtBlue;
            green_sum += image[i][j].rgbtGreen;
            red_sum += image[i][j].rgbtRed;

            // See if we can look up.
            const int look_up = (i > 0);
    
            // See if we can look down.
            const int look_down = (i < (height - 1));

            // See if we can look left.
            const int look_left = (j > 0);
            
            // See if we can look right.            
            const int look_right = (j < (width - 1));

            if (look_up)
            {
                blue_sum += image[i - 1][j].rgbtBlue;
                green_sum += image[i - 1][j].rgbtGreen;
                red_sum += image[i - 1][j].rgbtRed;
                num_values_considered++;

                if (look_left)
                {
                    blue_sum += image[i - 1][j - 1].rgbtBlue;
                    green_sum += image[i - 1][j - 1].rgbtGreen;
                    red_sum += image[i - 1][j - 1].rgbtRed;
                    num_values_considered++;
                }

                if (look_right)
                {
                    blue_sum += image[i - 1][j + 1].rgbtBlue;
                    green_sum += image[i - 1][j + 1].rgbtGreen;
                    red_sum += image[i - 1][j + 1].rgbtRed;
                    num_values_considered++;
                }
            }

            if (look_down)
            {
                blue_sum += image[i + 1][j].rgbtBlue;
                green_sum += image[i + 1][j].rgbtGreen;
                red_sum += image[i + 1][j].rgbtRed;
                num_values_considered++;

                if (look_left)
                {
                    blue_sum += image[i + 1][j - 1].rgbtBlue;
                    green_sum += image[i + 1][j - 1].rgbtGreen;
                    red_sum += image[i + 1][j - 1].rgbtRed;
                    num_values_considered++;
                }

                if (look_right)
                {
                    blue_sum += image[i + 1][j + 1].rgbtBlue;
                    green_sum += image[i + 1][j + 1].rgbtGreen;
                    red_sum += image[i + 1][j + 1].rgbtRed;
                    num_values_considered++;
                }
            }

            if (look_left)
            {
                blue_sum += image[i][j - 1].rgbtBlue;
                green_sum += image[i][j - 1].rgbtGreen;
                red_sum += image[i][j - 1].rgbtRed;
                num_values_considered++;
            }

            if (look_right)
            {
                blue_sum += image[i][j + 1].rgbtBlue;
                green_sum += image[i][j + 1].rgbtGreen;
                red_sum += image[i][j + 1].rgbtRed;
                num_values_considered++;
            }

            image_tmp[i][j].rgbtBlue = round(blue_sum / num_values_considered);
            image_tmp[i][j].rgbtGreen = round(green_sum / num_values_considered);
            image_tmp[i][j].rgbtRed = round(red_sum / num_values_considered);
        }
    }

    // Now copy the scratch space into the actual image.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = image_tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = image_tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = image_tmp[i][j].rgbtRed;
        }
    }

    return;
}
