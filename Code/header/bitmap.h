#ifndef ADAFRUIT_SSD1306_H
#define ADAFRUIT_SSD1306_H
#include <Adafruit_SSD1306.h>
#endif
/*
    Displaycolors:
    0: Black
    1: White
    2: Inverse
*/

#define MAX_BITMAP_LENGTH 88


class Bitmap
{
private:
    unsigned int x;                       // x-Position
    unsigned int y;                       // y-Position
    unsigned int width;                   // Breite
    unsigned int height;                  // Höhe
    unsigned char map[MAX_BITMAP_LENGTH]; // Bitmap Pixel
    bool inverted;                        // Invertierte Darstellung
public:
    unsigned int len; // Länge der Bitmap Pixel

    // Constructor - Destructor
    Bitmap();
    Bitmap(unsigned int x, unsigned int y, unsigned int _width,
           unsigned int _height, unsigned int _len, unsigned char _map[]);
    ~Bitmap();
    // Functions
    void print(Adafruit_SSD1306 &display)
    {
        display.drawBitmap(x, y, map, width, height, 1);
        // display.display();
    }
};

Bitmap::Bitmap() {}
Bitmap::Bitmap(unsigned int _x, unsigned int _y, unsigned int _width,
               unsigned int _height, unsigned int _len, unsigned char _map[])
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    len = _len;
    for (size_t i = 0; i < len; i++)
    {
        map[i] = _map[i];
    }
}

Bitmap::~Bitmap()
{
}
