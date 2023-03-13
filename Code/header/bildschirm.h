#ifndef ZONE_H
#define ZONE_H
#include "zone.h"
#endif

#ifndef ANIMATION_H
#define ANIMATION_H
#include "animation.h"
#endif

class Bildschirm
{
private:
    Zone **m_ptr_zonen;                    // Zeigt auf Array, welches die Zonen enthält
    Animation** m_ptr_arr_animation;
    uint8_t m_count_zonen = 0;      // Anzahl aller Zonen
    uint8_t m_selectable_zonen = 0; // Anzahl auswählbarer Zonen
    uint8_t m_count_animation;
    bool m_inverted = false;             // Invertierte Darstellung
    bool m_active = false;                 // Bildschirm aktiv angezeigt
    
public:     
    // Constructor - Destructor
    Bildschirm(
        Zone **zonen, uint8_t _count_zonen,
        Animation** _ptr_arr_animation, uint8_t _count_animation);
    ~Bildschirm();

    // Functions
    void print(Adafruit_SSD1306* display)
    {
        // display.clearDisplay();
        for (size_t i = 0; i < m_count_zonen; i++)
        {
            // zonen[i].print(display);
            (*(m_ptr_zonen + i))->print(display);
        }
        for (size_t i = 0; i < m_count_animation; i++)
        {
            (*(m_ptr_arr_animation + i))->update(display);
        }
    }
};

Bildschirm::Bildschirm(
    Zone **zonen, uint8_t _count_zonen,
    Animation** _ptr_arr_animation, uint8_t _count_animation)
{
    m_ptr_zonen = zonen;
    m_count_zonen = _count_zonen;
    m_ptr_arr_animation = _ptr_arr_animation;
    m_count_animation = _count_animation;
}

Bildschirm::~Bildschirm()
{
}
