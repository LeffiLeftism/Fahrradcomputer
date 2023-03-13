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
    unsigned int m_x;                       // x-Position
    unsigned int m_y;                       // y-Position
    unsigned int m_width;                   // Breite
    unsigned int m_height;                  // Höhe
    unsigned char m_map[MAX_BITMAP_LENGTH]; // Bitmap Pixel
    bool m_inverted;                        // Invertierte Darstellung
    unsigned int m_len;                     // Länge der Bitmap Pixel

public:
    // Constructor - Destructor
    Bitmap();
    Bitmap(unsigned int x, unsigned int y, unsigned int _width,
           unsigned int _height, unsigned int _len, unsigned char _map[]);
    ~Bitmap();
    // Functions
    void print(Adafruit_SSD1306* display)
    {
        display->drawBitmap(m_x, m_y, m_map, m_width, m_height, 1);
    }
};

Bitmap::Bitmap() {}
Bitmap::Bitmap(unsigned int _x, unsigned int _y, unsigned int _width,
               unsigned int _height, unsigned int _len, unsigned char _map[])
{
    m_x = _x;
    m_y = _y;
    m_width = _width;
    m_height = _height;
    m_len = _len;
    for (size_t i = 0; i < m_len; i++)
    {
        m_map[i] = _map[i];
    }
}

Bitmap::~Bitmap()
{
}
