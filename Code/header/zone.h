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
private:
    uint8_t m_x;            // Position x
    uint8_t  m_y;            // Position y
    uint8_t  m_width;        // Breite in Pixeln
    uint8_t  m_height;       // Höhe in Pixeln
    uint8_t  m_textSize = 3; // Textgröße
    uint8_t  m_countChars;   // Anzahl Zeichen
    bool m_inverted = false;     // Invertierte Darstellung
    bool m_visible = false;      // Sichtbar
    bool m_selectable = false;   // Auswählbar
    bool m_selected = false;     // Ausgewählt
    String m_val;                // Inhalt
    
public:
    // Constructor - Destructor
    Zone();
    Zone(uint8_t  _x, uint8_t  _y, uint8_t  _textSize, uint8_t  _countChars);
    Zone(uint8_t  _x, uint8_t  _y, uint8_t  _textSize, uint8_t  _countChars, String _val);
    ~Zone();

    // Functions
    void print(Adafruit_SSD1306* display)
    {
        display->fillRect(m_x, m_y, m_width, m_height, 0);
        display->setCursor(m_x, m_y);
        display->setTextSize(m_textSize);
        display->setTextColor(1);
        display->print(m_val);
        if (m_inverted)
        {
            display->fillRect(m_x, m_y, m_width, m_height, 2);
        }
    }

    void setVal(double num, unsigned int dez)
    {
        String str = String(num, dez);        
        String newVal = "";
        for (size_t i = str.length(); i < m_countChars; i++)
        {
            newVal += " ";
        }
        newVal += str;
        m_val = newVal;
    }

    void setVal(int num)
    {
        String str = String(num);
        String newVal = "";
        for (size_t i = str.length(); i < m_countChars; i++)
        {
            newVal += " ";
        }
        newVal += str;
        m_val = newVal;
    }

    void setVal(String _val)
    {
        String newVal = "";
        for (size_t i = 0; i < m_countChars; i++)
        {
            newVal += _val[i];
        }
        m_val = newVal;
    }
};

Zone::Zone() {}
Zone::Zone(uint8_t  _x, uint8_t  _y, uint8_t  _textSize, uint8_t  _countChars)
{
    m_x = _x;
    m_y = _y;
    m_textSize = _textSize;
    m_countChars = _countChars;
    // Calculated
    m_width = 6 * m_countChars * m_textSize - m_textSize; // Bestimmt die exakt benötigte Breite für die Zone
    m_height = m_textSize * 7 + 1;
}

Zone::Zone(uint8_t  _x, uint8_t  _y, uint8_t  _textSize, uint8_t  _countChars, String _val)
{
    m_x = _x;
    m_y = _y;
    m_textSize = _textSize;
    m_countChars = _countChars;
    // Calculated
    m_width = 6 * m_countChars * m_textSize - m_textSize; // Bestimmt die exakt benötigte Breite für die Zone
    m_height = m_textSize * 7 + 1;
    m_val = _val;
}

Zone::~Zone()
{
}