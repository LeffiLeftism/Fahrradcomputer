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

#ifndef FILEWRITER_H
#define FILEWRITER_H
#include "fileWriter.h"
#endif


class Device
{
private:
    Button** m_ptr_arr_btn;
    Bildschirm** m_ptr_arr_bildschirm;
    MagnetSensor** m_ptr_arr_magnetsensor;
    Adafruit_SSD1306* m_display;
    GPSSensor* m_GPS;
    FileWriter* m_filewriter;

    uint8_t m_selected_bildschirm;
    uint8_t m_count_btn;
    uint8_t m_count_bildschirm;
    uint8_t m_count_magnetsensor;
    uint8_t m_count_animation;
    
    void updateButtons()
    {
        for (size_t i = 0; i < m_count_btn; i++)
        {
            (*(m_ptr_arr_btn + i))->update();
        }
    }

    void updateSensors()
    {
        for (size_t i = 0; i < m_count_magnetsensor; i++)
        {
            (*(m_ptr_arr_magnetsensor + i))->update();
        }
        m_GPS->update();
    }

public:
    Device(Button** _ptr_arr_btn, uint8_t _count_btn, 
        Bildschirm** _ptr_arr_bildschirm, uint8_t _count_bildschirm,
        MagnetSensor** _ptr_arr_magnetsensor, uint8_t _count_magnetsensor,
        Adafruit_SSD1306* _display, GPSSensor* _GPS, FileWriter* _filewriter);
    ~Device();

    void init()
    {
        // Initialize Buttons
        for (size_t i = 0; i < m_count_btn; i++)
        {
            (*(m_ptr_arr_btn + i))->init();
        }
        for (size_t i = 0; i < m_count_magnetsensor; i++)
        {
            (*(m_ptr_arr_magnetsensor + i))->init();
        }
        
        m_filewriter->init();

    }

    void update()
    {
        updateSensors();
        updateButtons();
        m_filewriter->update();
    }

    void print(){
        m_display->clearDisplay();
        (*(m_ptr_arr_bildschirm + m_selected_bildschirm))->print(m_display);
        m_display->display();
    }
};

Device::Device(Button** _ptr_arr_btn, uint8_t _count_btn, 
        Bildschirm** _ptr_arr_bildschirm, uint8_t _count_bildschirm,
        MagnetSensor** _ptr_arr_magnetsensor, uint8_t _count_magnetsensor,
        Adafruit_SSD1306* _display, GPSSensor* _GPS, FileWriter* _filewriter)
{
    m_ptr_arr_btn = _ptr_arr_btn;
    m_count_btn = _count_btn;
    m_ptr_arr_bildschirm = _ptr_arr_bildschirm;
    m_count_bildschirm = _count_bildschirm;
    m_ptr_arr_magnetsensor = _ptr_arr_magnetsensor;
    m_count_magnetsensor = _count_magnetsensor;

    m_display = _display;
    m_GPS = _GPS;
    m_filewriter = _filewriter;
    m_selected_bildschirm = 0;
}

Device::~Device()
{

}
