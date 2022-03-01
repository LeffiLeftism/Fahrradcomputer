#ifndef ADAFRUIT_GFX_H
#define ADAFRUIT_GFX_H
#include <Adafruit_GFX.h>
#endif

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


class Zone
{
public:
    unsigned int x;            // Position x
    unsigned int y;            // Position y
    unsigned int width;        // Breite in Pixeln
    unsigned int height;       // Höhe in Pixeln
    unsigned int textSize = 3; // Textgröße
    unsigned int countChars;   // Anzahl Zeichen
    bool inverted = false;     // Invertierte Darstellung
    bool visible = false;      // Sichtbar
    String val;                // Inhalt
                               // public:                        //
    bool selectable = false;   // Auswählbar
    bool selected = false;     // Ausgewählt

    // Constructor - Destructor
    Zone();
    Zone(unsigned int _x, unsigned int _y, unsigned int _textSize, unsigned int _countChars);
    ~Zone();

    // Functions
    void print(Adafruit_SSD1306 &display)
    {
        display.fillRect(x, y, width, height, 0);
        display.setCursor(x, y);
        display.setTextSize(textSize);
        display.setTextColor(1);
        display.print(val);
        if (inverted)
        {
        }
        // display.fillRect(x, y, width, height, 2);
    }

    void setVal(double num, unsigned int dez)
    {
        String strNum = String(num, dez);
        String newVal = "";
        for (size_t i = strNum.length(); i < countChars; i++)
        {
            newVal += " ";
        }
        newVal += strNum;
        val = strNum;
    }

    void setVal(int num)
    {
        String strNum = String(num);
        String newVal = "";
        for (size_t i = strNum.length(); i < countChars; i++)
        {
            newVal += " ";
        }
        newVal += strNum;
        val = strNum;
    }

    void setVal(String _val)
    {
        String newVal = "";
        for (size_t i = 0; i < countChars; i++)
        {
            newVal += _val[i];
        }
        val = newVal;
    }
};

Zone::Zone() {}
Zone::Zone(unsigned int _x, unsigned int _y, unsigned int _textSize, unsigned int _countChars)
{
    x = _x;
    y = _y;
    textSize = _textSize;
    countChars = _countChars;
    // Calculated
    width = 6 * countChars * textSize - textSize; // Bestimmt die exakt benötigte Breite für die Zone
    height = textSize * 7 + 1;
}

Zone::~Zone()
{
}