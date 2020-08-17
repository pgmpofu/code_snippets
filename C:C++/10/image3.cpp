/* image3.hpp */

#include <stdint.h> // for uint8_t
#include <fstream>
#include "image3.hpp"

using namespace std;

Image image;

Image::Image() : rows(0), cols(0), pixels(NULL) {}

/* Frees all memory allocated for img */
Image::~Image()
{
    if (pixels)
    {
        delete[] pixels;
    }
}

/* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolour. Returns 0 on success, or a
     non-zero error code.*/
/* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolour. Returns 0 on success, or a non-zero error code.*/
int Image::resize(unsigned int width, unsigned int height, uint8_t fillcolour)
{
    if (pixels != NULL)
    {
        delete[] pixels;
    }
    cols = height;
    rows = width;
    unsigned int len = width * height;

    if (len < 0)
    {
        return 1;
    }
    else
    {
        for (unsigned int i = 0; i < len; i++)
        {
            *pixels[i] = fillcolour;
        }
        return 0;
    }

    return 1;
}

/* Sets the colour of the pixel at (x,y) to colour. Returns 0 on
     success, else a non-zero error code. If (x,y) is not a valid
     pixel, the call fails and the image does not change.*/
int Image::set_pixel(unsigned int x, unsigned int y, uint8_t colour)
{
    for (unsigned int i = 0; i < image.rows; i++)
    {
        for (unsigned int j = 0; j < image.cols; j++)
        {
            if (i == x && j == y)
            {
                *image.pixels[(i * image.cols) + j] = colour;
                return 0;
            }
        }
    }
    return 1;
}

/* Gets the colour of the pixel at (x,y) and stores at the address
     pointed to by colourp. Returns 0 on success, else a non-zero error
     code. */
int Image::get_pixel(unsigned int x, unsigned int y, uint8_t *colourp)
{
    for (unsigned int i = 0; i < image.rows; i++)
    {
        for (unsigned int j = 0; j < image.cols; j++)
        {
            if (i == x && y == j)
            {
                colourp = image.pixels[(i * image.cols) + j];
                return 0;
            }
        }
    }
    return 1;
}

/* Saves the image in the file filename. In a format that can be
     loaded by load(). Returns 0 on success, else a non-zero error
     code. */
int Image::save(const char *filename)
{
    if (filename)
    {
        ifstream image_file;
        if (image_file)
        {
            image_file.open(filename);
            if (image_file.is_open() && image.pixels != NULL)
            {
                for (unsigned int i = 0; i < image.rows * image.cols; i++)
                {
                    image_file >> image.pixels[i];
                }
            }
        }
        return 0;
    }
    return 1;
}

/* Load the an image from the file filename, replacing the current
     image size and data. The file is in a format that was saved by
     save(). Returns 0 success, else a non-zero error code . */
int Image::load(const char *filename)
{
    if (filename)
    {
        ifstream image_file;
        if (image_file)
        {
            ifstream mySource;
            image_file.open(filename, ios_base::binary);
            image_file.seekg(0, ios_base::end);
            int size = image_file.tellg();
            delete[] image.pixels;
            if (image_file.is_open())
            {
                for (int i = 0; i < size; i++)
                {
                    image_file >> image.pixels[i];
                }
            }
        }
        return 0;
    }
    return 1;
}
