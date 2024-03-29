//https://elektro.turanis.de/html/prj166/index.html

#ifndef TINYGPS_H
#define TINYGPS_H
#include <TinyGPS++.h>
#endif



class GPSSensor
{
private:
    int8_t m_pin_rx = 0;            // RX Pin on GPS Modul to this pin
    int8_t m_pin_tx = 1;            // TX Pin on GPS Modul to this pin
    uint16_t m_baudrate = 9600;     // Baudrate of GPS Modul
    TinyGPSPlus m_tinyGPS;          // GPS Modul Object to decode serial
    UART* m_uart;

    uint16_t m_year;
    uint8_t m_hour, m_minute, m_second, m_centisecond, m_month, m_day;
    double m_latitude, m_longitude, m_altitude;
    double m_speed_mps, m_speed_kph;
    String m_date;
    String m_time_1; // Time with :
    String m_time_2; // Time with _
public:
    double m_satellites;

private:
    void calcTime()
    {
        char buffer[8];
        sprintf(buffer, "%02d:%02d:%02d", m_hour, m_minute, m_second);
        m_time_1 = buffer;
        sprintf(buffer, "%02d_%02d_%02d", m_hour, m_minute, m_second);
        m_time_2 = buffer;
    }

    void calcDate()
    {
        char buffer[10];
        sprintf(buffer, "%04d-%02d-%02d", m_year, m_month, m_day);
        m_date = buffer;
    }
public:
    GPSSensor(UART *_uart);
    ~GPSSensor();

    void update()
    {
        while (m_uart->available() > 0)
        {
            m_tinyGPS.encode(m_uart->read());
            if (m_tinyGPS.location.isUpdated())
            {
                if (m_tinyGPS.satellites.isValid())
                {
                    m_satellites = double(m_tinyGPS.satellites.value());
                } else
                {
                    m_satellites = 0;
                }
                
                if (m_tinyGPS.date.isValid())
                {
                    m_day = m_tinyGPS.date.day();
                    m_month = m_tinyGPS.date.month();
                    m_year = m_tinyGPS.date.year();
                } else
                {
                    m_day = 0;
                    m_month = 0;
                    m_year = 0;
                }

                if (m_tinyGPS.time.isValid())
                {
                    m_centisecond = m_tinyGPS.time.centisecond();
                    m_second = m_tinyGPS.time.second();
                    m_minute = m_tinyGPS.time.minute();
                    m_hour = m_tinyGPS.time.hour() + 1;
                    if (m_hour > 23)
                    {
                        m_hour = 0;
                        m_day++;
                    }
                    
                } else
                {
                    m_centisecond = 0;
                    m_second = 0;
                    m_minute = 0;
                    m_hour = 0;
                }

                if (m_tinyGPS.location.isValid())
                {
                    m_latitude = m_tinyGPS.location.lat();
                    m_longitude = m_tinyGPS.location.lng();
                } else
                {
                    m_latitude = 0;
                    m_longitude = 0;
                }
                
                if (m_tinyGPS.altitude.isValid())
                {
                    m_altitude = m_tinyGPS.altitude.meters();
                } else
                {
                    m_altitude = 0;
                }
                
                if (m_tinyGPS.speed.isValid())
                {
                    m_speed_kph = m_tinyGPS.speed.kmph();
                    m_speed_mps = m_tinyGPS.speed.mps();
                } else
                {
                    m_speed_kph = 0;
                    m_speed_mps = 0;
                }
                calcDate();
                calcTime();
            }
        }
    }

    double* getLatitudeRef()
    {
        return &m_latitude;
    }

    double* getLongitudeRef()
    {
        return &m_longitude;
    }

    double* getAltitudeRef()
    {
        return &m_altitude;
    }

    double* getSpeedRef(String _type)
    {
        if (_type == "kph")
        {
            return &m_speed_kph;
        } else
        {
            return &m_speed_mps;
        }
    }

    double* getSatelitesRef()
    {
        return &m_satellites;
    }

    String* getTimeRef(bool _type = false) // false= ":", true= "_"
    {
        if (_type)
        {
            return &m_time_2;
        } else
        {
            return &m_time_1;
        }
    }

    String* getDateRef()
    {
        return &m_date;
    }
};

GPSSensor::GPSSensor(UART *_uart)
{
    m_uart = _uart;
    m_uart->begin(m_baudrate);
}

GPSSensor::~GPSSensor()
{
}


