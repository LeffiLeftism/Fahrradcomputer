#define PI_PICO

// IMPORT LIBRARYS & HEADERFILES
#ifndef ANIMATION_H
#define ANIMATION_H
#include "header/animation.h"
#endif

#ifndef BITMAP_H
#define BITMAP_H
#include "header/bitmap.h"
#endif

#ifndef BILDSCHIRM_H
#define BILDSCHIRM_H
#include "header/bildschirm.h"
#endif

#ifndef ZONE_H
#define ZONE_H
#include "header/zone.h"
#endif

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET 7        // Reset pin #
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#ifdef PI_PICO
MbedI2C I2C_base(4, 5);
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &I2C_base, OLED_RESET);
#define LED_BUILT_IN 25
#else
#include <Wire.h> // SDA: A4 - SCL: A5
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define LED_BUILT_IN 13
#endif

/****** Bitmaps ******/
/**
 * Made with Marlin Bitmap Converter
 * https://marlinfw.org/tools/u8glib/converter.html
 *
 *
 */

unsigned char bitmap_bike[][88] = {
    // Bike 1
    {0x01, 0xC0, 0x00, 0x00,
     0x03, 0xE0, 0x00, 0x00,
     0x03, 0x60, 0x00, 0x00,
     0x03, 0xE4, 0x00, 0x00,
     0x01, 0xCF, 0x00, 0x00,
     0x00, 0x1B, 0x80, 0x00,
     0x01, 0xF0, 0xE0, 0x00,
     0x03, 0xE0, 0x70, 0x00,
     0x00, 0x03, 0xF0, 0x00,
     0x1F, 0xC7, 0xE7, 0xC0,
     0x3F, 0xE6, 0x0F, 0xE0,
     0x70, 0x76, 0x1C, 0x70,
     0x60, 0x33, 0x38, 0x38,
     0xE0, 0x3B, 0x70, 0x1C,
     0xC0, 0x1B, 0x60, 0x0C,
     0xC0, 0x18, 0x60, 0x0C,
     0xC0, 0x18, 0x60, 0x0C,
     0xC0, 0x38, 0x60, 0x0C,
     0xE0, 0x70, 0x70, 0x1C,
     0x70, 0xE0, 0x38, 0x38,
     0x3F, 0xE0, 0x1F, 0xF0,
     0x1F, 0x80, 0x0F, 0xE0},
    // Bike 2
    {0x01, 0xC0, 0x00, 0x00,
     0x03, 0xE0, 0x00, 0x00,
     0x03, 0x60, 0x00, 0x00,
     0x03, 0xE4, 0x00, 0x00,
     0x01, 0xCF, 0x00, 0x00,
     0x00, 0x1B, 0x80, 0x00,
     0x01, 0xF0, 0xE0, 0x00,
     0x03, 0xE0, 0x70, 0x00,
     0x00, 0x00, 0x30, 0x00,
     0x1F, 0xC1, 0xF7, 0xC0,
     0x3F, 0xE3, 0xCF, 0xE0,
     0x70, 0x73, 0x1C, 0x70,
     0x60, 0x33, 0x38, 0x38,
     0xE0, 0x3B, 0x70, 0x1C,
     0xC0, 0x1B, 0x60, 0x0C,
     0xC0, 0x1B, 0x60, 0x0C,
     0xC0, 0x1B, 0x60, 0x0C,
     0xC0, 0x38, 0x60, 0x0C,
     0xE0, 0x70, 0x70, 0x1C,
     0x70, 0xE0, 0x38, 0x38,
     0x3F, 0xE0, 0x1F, 0xF0,
     0x1F, 0x80, 0x0F, 0xE0},
    // Bike 3
    {0x01, 0xC0, 0x00, 0x00,
     0x03, 0xE0, 0x00, 0x00,
     0x03, 0x60, 0x00, 0x00,
     0x03, 0xE4, 0x00, 0x00,
     0x01, 0xCF, 0x00, 0x00,
     0x00, 0x1B, 0x80, 0x00,
     0x01, 0xF0, 0xE0, 0x00,
     0x03, 0xE0, 0x70, 0x00,
     0x00, 0x00, 0x30, 0x00,
     0x1F, 0xC0, 0x77, 0xC0,
     0x3F, 0xE0, 0xEF, 0xE0,
     0x70, 0x71, 0xDC, 0x70,
     0x60, 0x31, 0xB8, 0x38,
     0xE0, 0x3B, 0x70, 0x1C,
     0xC0, 0x1B, 0x60, 0x0C,
     0xC0, 0x1B, 0x60, 0x0C,
     0xC0, 0x1B, 0x60, 0x0C,
     0xC0, 0x3B, 0x60, 0x0C,
     0xE0, 0x70, 0x70, 0x1C,
     0x70, 0xE0, 0x38, 0x38,
     0x3F, 0xE0, 0x1F, 0xF0,
     0x1F, 0x80, 0x0F, 0xE0}};

unsigned char hoehe1[] = {
    0x00, 0x00, 0x00, // ........................
    0x00, 0x04, 0x00, // .............#..........
    0x71, 0xCE, 0x00, // .###...###..###.........
    0x71, 0xD5, 0x00, // .###...###.#.#.#........
    0x71, 0xC4, 0x00, // .###...###...#..........
    0x71, 0xC4, 0x00, // .###...###...#..........
    0x7F, 0xC4, 0x00, // .#########...#..........
    0x7F, 0xC0, 0x00, // .#########..............
    0x7F, 0xC4, 0x00, // .#########...#..........
    0x71, 0xC4, 0x00, // .###...###...#..........
    0x71, 0xC4, 0x00, // .###...###...#..........
    0x71, 0xD5, 0x00, // .###...###.#.#.#........
    0x71, 0xCE, 0x00, // .###...###..###.........
    0x00, 0x04, 0x00, // .............#..........
    0x00, 0x00, 0x00  // ........................
};

Zone zonen_dashboard[] = {
    {0, 0, 3, 4},    // Zone 1     Geschwindigkeit km/h
    {75, 2, 1, 2},   // Zone 2     Entfernung km
    {75, 11, 1, 2},  // Zone 3     /h
    {50, 24, 2, 5},  // Zone 4     rpm
    {110, 23, 1, 3}, // Zone 5     RPM
    {110, 32, 1, 3}, // Zone 6     Ped
    {0, 41, 2, 4},   // Zone 7     power
    {48, 40, 1, 2},  // Zone 8     power
    {48, 49, 1, 2},  // Zone 9     tt
    {62, 41, 2, 4}}; // Zone 10    Höhe über NN

Bildschirm dashboard(zonen_dashboard, 10);

Bitmap bike[] = {
    {SCREEN_WIDTH - 30, 0, 30, 22, 88, bitmap_bike[0]},
    {SCREEN_WIDTH - 30, 0, 30, 22, 88, bitmap_bike[1]},
    {SCREEN_WIDTH - 30, 0, 30, 22, 88, bitmap_bike[2]}};

Bitmap hoehe(SCREEN_WIDTH - 17, 41, 17, 15, 45, hoehe1);

Animation animation_bike(bike, 750);

// -------------------- CODE --------------------
Zone test(0, 0, 2, 8);

class example
{
public:
    int *m_val;
    Zone **m_z;

public:
    example(int *val, Zone **z);
    ~example();

    void print(Adafruit_SSD1306 &display)
    {
        (*(m_z))->print(display);
        (*(m_z + 1))->print(display);
    }
};

example::example(int *val, Zone **z)
{
    m_val = val;
    m_z = z;
}

example::~example()
{
}

void setup()
{
#ifndef PI_PICO
    Wire.begin();
#endif
    pinMode(LED_BUILT_IN, OUTPUT);
    if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        while (1)
            error();
    }
    // animation_bike.start();

    for (size_t i = 0; i < 10; i++)
    {
        dashboard.zonen[i].setVal(i);
    }

    dashboard.zonen[0].setVal(11.1, 1);
    dashboard.zonen[1].setVal("km");
    dashboard.zonen[2].setVal("/h");
    dashboard.zonen[3].setVal(222.2, 1);
    dashboard.zonen[4].setVal("RPM");
    dashboard.zonen[5].setVal("Ped");
    dashboard.zonen[6].setVal(3333);
    dashboard.zonen[7].setVal("PW");
    dashboard.zonen[8].setVal("tt");
    dashboard.zonen[9].setVal(4444);

    oled.display();
    delay(2000);
    animation_bike.start();

    // --------------------------------------------
    oled.clearDisplay();
    Zone z1(0, 0, 2, 4);
    Zone z2(0, 30, 2, 4);
    Zone *zz[] = {&z1, &z2};
    int a[2];
    a[0] = 5;
    a[1] = 3;
    Zone **prt_z = zz;
    example e(a, prt_z);
    int b = *(e.m_val + 1);
    *e.m_val = 66;
    // dashboard.zonen[9].setVal(b);
    // dashboard.zonen[6].setVal(*e.m_val);
    z1.setVal(6666);
    z2.setVal(9976);
    // z1.print(oled);
    // e.m_z->setVal(6666);
    // e.m_z->print(oled);
    e.print(oled);
    oled.display();
    delay(5000);
}

void loop()
{
    oled.clearDisplay();
    hoehe.print(oled);
    if (millis() > 10000)
        animation_bike.setFrame(int(random(3)));
    dashboard.zonen[0].setVal(millis() / 1000);
    animation_bike.update(oled);
    dashboard.print(oled);
    oled.display();
}

// ------------------ Eigene Funktionen ------------------

void error()
{
    while (1)
    {
        toggle(LED_BUILT_IN);
        delay(100);
    }
}

void toggle(unsigned int pin)
{
    digitalWrite(pin, digitalRead(pin));
}
