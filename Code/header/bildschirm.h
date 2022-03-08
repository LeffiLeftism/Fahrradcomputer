#ifndef ZONE_H
#define ZONE_H
#include "zone.h"
#endif

class Bildschirm
{
private:
    unsigned int m_count_zonen = 0;      // Anzahl aller Zonen
    unsigned int m_selectable_zonen = 0; // Anzahl auswählbarer Zonen
    bool m_inverted = false;             // Invertierte Darstellung
public:                                  //
    Zone **ptr_zonen;                    // Zeigt auf Array, welches die Zonen enthält
    bool active = false;                 // Bildschirm aktiv angezeigt

    // Constructor - Destructor
    Bildschirm(Zone **zonen, unsigned int _count_zonen);
    ~Bildschirm();

    // Functions
    void print(Adafruit_SSD1306 &display)
    {
        // display.clearDisplay();
        for (size_t i = 0; i < m_count_zonen; i++)
        {
            // zonen[i].print(display);
            (*(ptr_zonen + i))->print(display);
        }
        // display.display();
    }
};

Bildschirm::Bildschirm(Zone **zonen, unsigned int _count_zonen)
{
    m_count_zonen = _count_zonen;
    ptr_zonen = zonen;
}

Bildschirm::~Bildschirm()
{
}
