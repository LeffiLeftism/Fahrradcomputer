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

#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
#include "screen_manager.h"
#endif

class Device
{
private:
    MagnetSensor** m_ptr_arr_magnetsensor;
    GPSSensor* m_GPS;
    FileWriter* m_filewriter;
    ScreenManager* m_screenmanager;
    
    uint8_t m_count_magnetsensor;
    uint8_t m_count_animation;

    void updateSensors()
    {
        for (size_t i = 0; i < m_count_magnetsensor; i++)
        {
            (*(m_ptr_arr_magnetsensor + i))->update();
        }
        m_GPS->update();
    }

public:
    Device(
        MagnetSensor** _ptr_arr_magnetsensor, uint8_t _count_magnetsensor,
        GPSSensor* _GPS, FileWriter* _filewriter, ScreenManager* _screenmanager);
    ~Device();

    void init()
    {
        for (size_t i = 0; i < m_count_magnetsensor; i++)
        {
            (*(m_ptr_arr_magnetsensor + i))->init();
        }
        
        m_filewriter->init();
        m_screenmanager->init();
    }

    void update()
    {
        updateSensors();
        m_filewriter->update();
        m_screenmanager->update();
    }

    void print()
    {
        m_screenmanager->print();
    }
};

Device::Device(
        MagnetSensor** _ptr_arr_magnetsensor, uint8_t _count_magnetsensor, 
        GPSSensor* _GPS, FileWriter* _filewriter, ScreenManager* _screenmanager)
{
    m_ptr_arr_magnetsensor = _ptr_arr_magnetsensor;
    m_count_magnetsensor = _count_magnetsensor;

    m_GPS = _GPS;
    m_filewriter = _filewriter;
    m_screenmanager = _screenmanager;
}

Device::~Device()
{

}
