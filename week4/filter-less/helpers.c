#include "helpers.h"
#include <cs50.h>
#include <math.h>

int clamp(int value);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Isolate pixel
            RGBTRIPLE pixel = image[i][j];

            // Take average of red, green and blue
            int average_color = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);

            // Update pixel's color values with new (grayscale) value
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average_color;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // declare and initialize new color values
    int sepia_red, sepia_green, sepia_blue = 0;

    RGBTRIPLE sepia_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            sepia_red = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            sepia_green = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            sepia_blue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            // clamp values to min of 0 and maximum of 255
            sepia_red = clamp(sepia_red);
            sepia_green = clamp(sepia_green);
            sepia_blue = clamp(sepia_blue);

            // Update pixel's colors with sepia values
            sepia_image[i][j].rgbtRed = sepia_red;
            sepia_image[i][j].rgbtGreen = sepia_green;
            sepia_image[i][j].rgbtBlue = sepia_blue;

            // Update the image's pixel with new color
            image[i][j] = sepia_image[i][j];
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        // Only loop halfway through
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp_pixel = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp_pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of original image
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Duplicate image
            image_copy[i][j] = image[i][j];
        }
    }

    // Initialize variables for sum of each color value
    float red_sum, green_sum, blue_sum = 0;

    // Use counter to keep track of (current pixel + surrounding pixels) and use in determining average
    int counter = 0;

    // Loop through rows
    for (int row = 0; row < height; row++)
    {
        // Loop through columns
        for (int col = 0; col < width; col++)
        {
            // Loop through 2D array rows
            for (int arr_row = row - 1; arr_row <= row + 1; arr_row++)
            {
                // Loop through 2D array columns
                for (int arr_col = col - 1; arr_col <= col + 1; arr_col++)
                {
                    if (arr_col < width && arr_row < height && arr_col >= 0 && arr_row >= 0)
                    {
                        red_sum += image_copy[arr_row][arr_col].rgbtRed;
                        green_sum += image_copy[arr_row][arr_col].rgbtGreen;
                        blue_sum += image_copy[arr_row][arr_col].rgbtBlue;

                        // Counter to keep track of number of surrounding pixels
                        counter++;
                    }
                }
            }

            // Calculate average of red value of surrounding pixels and round to prevent truncation
            image[row][col].rgbtRed = round(red_sum / counter);
            image[row][col].rgbtGreen = round(green_sum / counter);
            image[row][col].rgbtBlue = round(blue_sum / counter);

            // Reset RGB sum values & counter to prepare for next pixel
            red_sum = green_sum = blue_sum = counter = 0;
        }
    }

    return;
}

// Clamp functionality as in java
int clamp(int value)
{
    if (value < 0)
    {
        return 0;
    }
    else if (value > 255)
    {
        return 255;
    }

    // Value is not less than 0 or greater than 255
    return value;
}
