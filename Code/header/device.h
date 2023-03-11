#ifndef BUTTON_H
#define BUTTON_H
#include "button.h"
#endif

#ifndef BILDSCHIRM_H
#define BILDSCHIRM_H
#include "bildschirm.h"
#endif

#ifndef MAGNETSENSOR_H
#define MAGNETSENSOR_H
#include "MagnetSensor.h"
#endif

#ifndef GPSSENSOR_H
#define GPSSENSOR_H
#include "gpsSensor.h"
#endif


class Device
{
private:
    Button** m_ptr_arr_btn;
    Bildschirm** m_ptr_arr_bildschirm;
    MagnetSensor** m_ptr_arr_magnetsensor;
    Adafruit_SSD1306* m_display;
    GPSSensor* m_GPS;
    
    void updateButtons()
    {
        for (size_t i = 0; i < (sizeof(*m_ptr_arr_btn)/sizeof(Button)); i++)
        {
            (*(m_ptr_arr_btn + i))->update();
        }
    }

    void updateSensors()
    {
        for (size_t i = 0; i < (sizeof(*m_ptr_arr_magnetsensor)/sizeof(MagnetSensor)); i++)
        {
            (*(m_ptr_arr_magnetsensor + i))->update();
        }
        m_GPS->update();
    }

public:
    Device(Button** _ptr_arr_btn, Bildschirm** _ptr_arr_bildschirm, MagnetSensor** _ptr_arr_magnetsensor, Adafruit_SSD1306* _display, GPSSensor* _GPS);
    ~Device();

    void init()
    {
        // Initialize Buttons
        for (size_t i = 0; i < (sizeof(m_ptr_arr_btn)/sizeof(Button)); i++)
        {
            (*(m_ptr_arr_btn + i))->init();
        }
    }

    void print(){
        updateSensors();
        /*
        Print here:
        - Add Animations to Bildschirm
        - Let Hoehe be an animation
        */
    }
};

Device::Device(Button** _ptr_arr_btn, Bildschirm** _ptr_arr_bildschirm, MagnetSensor** _ptr_arr_magnetsensor, Adafruit_SSD1306* _display, GPSSensor* _GPS)
{
    m_ptr_arr_btn = _ptr_arr_btn;
    m_ptr_arr_bildschirm = _ptr_arr_bildschirm;
    m_display = _display;
    m_ptr_arr_magnetsensor = _ptr_arr_magnetsensor;
    m_GPS = _GPS;
}

Device::~Device()
{

}
