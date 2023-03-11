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
    Bitmap m_maps[MAX_MAPS];      // Maximals Anzahl Bitmaps für eine Animation
    uint8_t m_maps_count;         // Genutzte Anzahl Bitmaps für eine Animation
    uint8_t m_frame = 0;          // Aktuell angezeigte Bitmap
    uint8_t m_direction = 1;      // Richtung um durch das Array zu bewegen
    double* m_ptr_threshold_d = nullptr;      // double
    uint32_t* m_ptr_threshold_i = nullptr;    // int
    uint32_t m_delay;             // ms zwischen Bitmaps
    uint32_t m_timer;        // 
    bool m_animate;               // Animation gestartet
    
public:
    // Constructor - Destructor
    Animation(Bitmap _maps[], uint32_t _delay, uint8_t _maps_count);
    ~Animation();
    // Functions
    void start()
    {
        m_animate = true;
        m_timer = millis();
    }

    void stop()
    {
        m_animate = false;
    }

    void update(Adafruit_SSD1306* display)
    {
        if ((*m_ptr_threshold_d > 0 || *m_ptr_threshold_i > 0) && 
            !m_animate)
        {
            start();
        } else if (
            ((*m_ptr_threshold_d == 0 && m_ptr_threshold_i == nullptr)||
            (*m_ptr_threshold_i == 0 && m_ptr_threshold_d == nullptr)) &&
            m_animate)
        {
            stop();
        }
        if (((millis() - m_timer) > m_delay) && m_animate)
        {
            if (m_maps_count > 1) {
                m_frame += m_direction;
                if (m_frame > m_maps_count - 2 || m_frame == 0) {
                m_direction *= -1;
                }
            }
            m_timer = millis();
        }
        m_maps[m_frame].print(display);
    }

    void setFrame(unsigned int _frame) {
        m_animate = false;
        m_frame = _frame;
    }

    void setThreshold(double* _ptr_threshold_d)
    {
        m_ptr_threshold_d = _ptr_threshold_d;
    }

    void setThreshold(uint32_t* _ptr_threshold_i)
    {
        m_ptr_threshold_i = _ptr_threshold_i;
    }
};

Animation::Animation(Bitmap _maps[], uint32_t _delay, uint8_t _maps_count)
{
    m_delay = _delay;
    for (size_t i = 0; i < MAX_MAPS; i++)
    {
        m_maps[i] = _maps[i];
    }
    if (_maps_count > MAX_MAPS)
    {
        m_maps_count = MAX_MAPS;
    } else {
        m_maps_count = _maps_count;
    }
    m_animate = false;
}

Animation::~Animation()
{
}


