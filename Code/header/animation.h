#ifndef ADAFRUIT_SSD1306_H
#define ADAFRUIT_SSD1306_H
#include <Adafruit_SSD1306.h>
#endif

#ifndef BITMAP_H
#define BITMAP_H
#include "bitmap.h"
#endif

#define MAX_MAPS 4


class Animation
{
private:
    Bitmap maps[MAX_MAPS]; // Maximals Anzahl Bitmaps für eine Animation
    uint8_t maps_count;    // Genutzte Anzahl Bitmaps für eine Animation
    unsigned int delay;    // ms zwischen Bitmaps
    int frame = 0;         // Aktuell angezeigte Bitmap
    bool animate = false;  // Animation gestartet
    unsigned long timer;   //
    int direction = 1;     // Richtung um durch das Array zu bewegen

public:
    // Constructor - Destructor
    Animation(Bitmap _maps[], unsigned int _delay, uint8_t _maps_count);
    ~Animation();
    // Functions
    void start()
    {
        animate = true;
        timer = millis();
    }

    void stop()
    {
        animate = false;
    }

    void update(Adafruit_SSD1306 &display)
    {
        if (millis() - timer > delay && animate)
        {
            frame += direction;
            if (frame > maps_count - 1)
            {
                frame -= 2;
                direction = -1;
            }
            else if (frame < 0)
            {
                frame += 2;
                direction = 1;
            }
            timer = millis();
        }
        maps[frame].print(display);
    }

    void setFrame(unsigned int _frame) {
        animate = false;
        frame = _frame;
    }

    bool get_animate() {
        return animate;
    }
};

Animation::Animation(Bitmap _maps[], unsigned int _delay, uint8_t _maps_count)
{
    delay = _delay;
    for (size_t i = 0; i < MAX_MAPS; i++)
    {
        maps[i] = _maps[i];
    }
    if (_maps_count > MAX_MAPS)
    {
        maps_count = MAX_MAPS;
    } else {
        maps_count = _maps_count;
    }
    
}

Animation::~Animation()
{
}
