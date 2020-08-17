#include <iostream>
#include <assert.h>
#include "image.hpp"

using namespace std;

Image image;

/* Constructs an image of 0x0 pixels. */
Image::Image() : cols(0), rows(0), pixels(NULL){};

/* Frees all memory allocated for img */
Image::~Image()
{
    if (pixels)
    {
        delete[] pixels;
    }
}

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
    pixels = new uint8_t[len];

    if (len < 0)
    {
        return 1;
    }
    else
    {
        for (unsigned int i = 0; i < len; i++)
        {
            pixels[i] = fillcolour;
        }
        return 0;
    }

    return 1;
}

/* Sets the colour of the pixel at (x,y) to colour. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel(unsigned int x, unsigned int y, uint8_t colour)
{
    if (pixels)
    {
        pixels[x + rows * y] = colour;
        return 0;
    }
    return 1;
}

/* Gets the colour of the pixel at (x,y) and stores at the address pointed to 
     by colourp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel(unsigned int x, unsigned int y, uint8_t *colourp)
{
    if (pixels)
    {
        if (colourp)
        {
            if (x >= 0 && x <= rows && y >= 0 && y <= cols && (x + rows * y < rows * cols))
            {
                *colourp = pixels[x + rows * y];
                return 0;
            }
        }
    }
    return 1;
}
