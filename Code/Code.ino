// IMPORT LIBRARYS & HEADERFILES
#ifndef DEVICE_H
#define DEVICCE_H
#include "header/device.h"
#endif

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET 7        // Reset pin #
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define LED_BUILT_IN 25

/****** Bitmaps ******/
/*
 * Made with Marlin Bitmap Converter
 * https://marlinfw.org/tools/u8glib/converter.html
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
unsigned char hoehe1[][45] = {
    {0x00, 0x00, 0x00, // ........................
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
    0x00, 0x00, 0x00}  // ........................
};
unsigned char bitmap_satelite[][16] = {
    // Satelite 0
    {
        0x00,0x00, // ................
        0x01,0x80, // .......##.......
        0x01,0x80, // .......##.......
        0x01,0x80, // .......##.......
        0x01,0x80, // .......##.......
        0x03,0x80, // ......###.......
        0x3F,0x00, // ..######........
        0x3E,0x80  // ..#####.#.......
    },
    // Satelite 1
    {
        0x00,0x00, // ................
        0x01,0x80, // .......##.......
        0x01,0x80, // .......##.......
        0x01,0x80, // .......##.......
        0x05,0x80, // .....#.##.......
        0x03,0x80, // ......###.......
        0x3F,0x00, // ..######........
        0x3E,0x80  // ..#####.#.......
    },
    // Satelite 2
    {
        0x00,0x00, // ................
        0x01,0x80, // .......##.......
        0x0D,0x80, // ....##.##.......
        0x11,0x80, // ...#...##.......
        0x15,0x80, // ...#.#.##.......
        0x03,0x80, // ......###.......
        0x3F,0x00, // ..######........
        0x3E,0x80  // ..#####.#.......
    },
    // Satelite 3
    {
        0x3C,0x00, // ..####..........
        0x41,0x80, // .#.....##.......
        0x4D,0x80, // .#..##.##.......
        0x51,0x80, // .#.#...##.......
        0x55,0x80, // .#.#.#.##.......
        0x03,0x80, // ......###.......
        0x3F,0x00, // ..######........
        0x3E,0x80  // ..#####.#.......
    }};

Bitmap bike[] = {
    {SCREEN_WIDTH - 30, 0, 30, 22, 88, bitmap_bike[0]},
    {SCREEN_WIDTH - 30, 0, 30, 22, 88, bitmap_bike[1]},
    {SCREEN_WIDTH - 30, 0, 30, 22, 88, bitmap_bike[2]}};
Bitmap hoehe[] = {{SCREEN_WIDTH - 17, 41, 17, 15, 45, hoehe1[0]}};
Bitmap satelite[] = {
    {117, 56, 10, 8, 16, bitmap_satelite[0]},
    {117, 56, 10, 8, 16, bitmap_satelite[1]},
    {117, 56, 10, 8, 16, bitmap_satelite[2]},
    {117, 56, 10, 8, 16, bitmap_satelite[3]}};

Animation animation_bike(bike, 750, 3);
Animation animation_hoehe(hoehe, 10000, 1);
Animation animation_satelite(satelite, 1000, 4);

Animation* animation_arr[] = {&animation_bike, &animation_satelite, &animation_hoehe};

/****** Zonen-Einstellungen ******/

Zone z1(0, 0, 3, 4);                            // Zone 1     speed-value
Zone z2(75, 2, 1, 2, "km");                     // Zone 2     "km"
Zone z3(75, 11, 1, 2, "/h");                    // Zone 3     "/h"
Zone z4(50, 24, 2, 5);                          // Zone 4     rpm-value
Zone z5(110, 23, 1, 3, "RPM");                  // Zone 5     "RPM"
Zone z6(110, 32, 1, 3, "Ped");                  // Zone 6     "Ped"
Zone z7(0, 41, 2, 4, "7777");                   // Zone 7     power-value
Zone z8(48, 40, 1, 2, "PW");                    // Zone 8     "PW"
Zone z9(48, 49, 1, 2, "tt");                    // Zone 9     "tt"
Zone z10(62, 41, 2, 4);                         // Zone 10    Höhe über NN -value
Zone z11(0, 57, 1, 5, "12:15");                 // Zone 11    Uhrzeit
Zone z12(35, 57, 1, 10);           // Zone 12    Debug, Output für alles was notwendig ist
Zone z13(105, 57, 1, 2);                        // Zone 13    Satelite Count

Zone *zonen_dashboard[] = {&z1, &z2, &z3, &z4, &z5, &z6, &z7, &z8, &z9, &z10, &z11, &z12, &z13};

Bildschirm B_dashboard(zonen_dashboard, 13, animation_arr, 3);
Bildschirm* bildschirm_arr[] = {&B_dashboard};

/****** KOM Ports ******/

UART uart_0(0,1);
MbedI2C I2C_base(4, 5);
MbedSPI spi_0(16,19,18);

/****** Peripherals ******/

MagnetSensor Pedal_RPM(2, 60000, 1);
MagnetSensor Wheel_Speed(3, 7974, 1);
GPSSensor GPS(&uart_0);
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &I2C_base, OLED_RESET);
Button btn_left(10);
Button btn_middle(11);
Button btn_right(12);

MagnetSensor* ms_arr[] = {&Pedal_RPM, &Wheel_Speed};
Button* btn_arr[] = {&btn_left, &btn_middle, &btn_right};

FileWriter filewriter(17, &GPS, &SD);
Device main_device(btn_arr, 3, bildschirm_arr, 1, ms_arr, 2, &oled, &GPS, &filewriter);

/****** Variablen ******/

static unsigned int aktiverBildschirm = 0; // Trackt den aktiven Bildschirm über alle Bildschirme hinweg

// -------------------- CODE --------------------

void setup()
{
    pinMode(LED_BUILT_IN, OUTPUT); 
    delay(2000);
    main_device.init();

    attachInterrupt(digitalPinToInterrupt(Pedal_RPM.m_SensorPin), interrupt_func1, LOW);
    attachInterrupt(digitalPinToInterrupt(Wheel_Speed.m_SensorPin), interrupt_func2, LOW);
    
    // Set Animation Thresholds
    animation_bike.setThreshold(&Pedal_RPM.m_ptr_var);
    animation_satelite.setThreshold(&GPS.m_satellites);
    delay(2000);
    if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        error();
    }
    z12.setVal(404, 0);
    oled.display();
    delay(800);
    while (!(GPS.getSatelites() > 0))
    {
        GPS.update();
        delay(1);
    }
    filewriter.startRecording();
}

void loop()
{
    main_device.update();
    setZoneValues();
    main_device.print();
}
// ------------------ Interrupt Funktionen ------------------

void interrupt_func1()
{
    Pedal_RPM.interrupt();
    while (digitalRead(Pedal_RPM.m_SensorPin) == 0)
    {
        delay(1);
    }
}

void interrupt_func2()
{
    Wheel_Speed.interrupt();
    while (digitalRead(Wheel_Speed.m_SensorPin) == 0)
    {
        delay(1);
    }
}

// ------------------ Eigene Funktionen ------------------

void setZoneValues()
{
    z1.setVal(Wheel_Speed.m_ptr_var, 1);
    z4.setVal(Pedal_RPM.m_ptr_var, 1);
    z10.setVal(GPS.getAltitude(), 0);
    z11.setVal(GPS.getTime());
    z13.setVal(String(GPS.getSatelites()));
}

void error()
{
    bool state = LOW;
    while (1)
    {
        digitalWrite(LED_BUILT_IN, state);
        state = !state;
        delay(500);
    }
}

void tester()
{
    digitalWrite(LED_BUILT_IN, HIGH);
    delay(200);
    digitalWrite(LED_BUILT_IN, LOW);
}



