#ifndef ZONE_H
#define ZONE_H
#include "zone.h"
#endif

#define MAX_ANZAHL_ZONEN 10


class Bildschirm
{
private:
    unsigned int count_zonen = 0;      // Anzahl aller Zonen
    unsigned int selectable_zonen = 0; // Anzahl auswählbarer Zonen
    bool inverted = false;             // Invertierte Darstellung
public:                                //
    Zone zonen[MAX_ANZAHL_ZONEN];      //
    bool active = false;               // Bildschirm aktiv angezeigt

    // Constructor - Destructor
    Bildschirm(Zone _zonen[MAX_ANZAHL_ZONEN], unsigned int _count_zonen);
    ~Bildschirm();

    // Functions
    void print(Adafruit_SSD1306 &display)
    {
        // display.clearDisplay();
        for (size_t i = 0; i < count_zonen; i++)
        {
            zonen[i].print(display);
        }
        // display.display();
    }
};

Bildschirm::Bildschirm(Zone _zonen[MAX_ANZAHL_ZONEN], unsigned int _count_zonen)
{
    count_zonen = _count_zonen;
    for (size_t i = 0; i < MAX_ANZAHL_ZONEN; i++)
    {
        if (_zonen[i].selectable)
            selectable_zonen++;
        zonen[i] = _zonen[i];
    }
}

Bildschirm::~Bildschirm()
{
}
