#ifndef SD_H
#define SD_H
#include <SD.h>
#endif

#ifndef TIMER_H
#define TIMER_H
#include "timer.h"
#endif

#ifndef GPSSENSOR_H
#define GPSSENSOR_H
#include "gpsSensor.h"
#endif


class FileWriter
{
    private:
    File m_myFile;
    Timer m_Timer_fileoutput = Timer(1000);
    GPSSensor* m_GPS;
    SDClass* m_SD;

    uint8_t m_pin_cs;
    String m_name;
    String m_extension;
    String m_filename;
    bool m_created, m_recording;

    public:
    FileWriter();
    FileWriter(uint8_t _pin_cs, GPSSensor* _GPS, SDClass* _SD, String _extension);
    ~FileWriter();

    private:
    void setFilename()
    {
        if (m_GPS->m_satellites > 0)
        {
            m_name = *(m_GPS->getTimeRef(true));
        }
        else
        {
            m_name = "noGPS";
        }
        m_filename = m_name + "." + m_extension;
    }

    void createFile()
    {
        setFilename();
        m_myFile = m_SD->open(m_filename, FILE_WRITE);
        m_myFile.println("Time,Latitude,Longitude,Altitude"); //Heartrate and Cadence not collected
        m_myFile.close();
        m_created = true;
        m_Timer_fileoutput.start();
    }

    void addTrackpoint()
    {
        m_myFile = SD.open(m_filename, FILE_WRITE);
        m_myFile.print(*(m_GPS->getDateRef()));
        m_myFile.print("T");
        m_myFile.print(*(m_GPS->getTimeRef()));
        m_myFile.print("z,");
        m_myFile.print(*(m_GPS->getLatitudeRef()), 6);
        m_myFile.print(",");
        m_myFile.print(*(m_GPS->getLongitudeRef()), 6);
        m_myFile.print(",");
        m_myFile.print(*(m_GPS->getAltitudeRef()), 2);
        //m_myFile.print(",");
        // m_myFile.print(64); Heartrate not collected
        // m_myFile.print(",");
        // m_myFile.print(Pedal_RPM.m_ptr_var, 2);
        m_myFile.println();
        m_myFile.close();
    }

    
    public:
    void init()
    {
        m_SD->begin(m_pin_cs);
        m_Timer_fileoutput.init();
    }

    void startRecording()
    {
        if (!m_recording)
        {
            createFile();
            m_recording = true;
        }
    }

    void stopRecording()
    {
        m_recording = false;
    }

    void update()
    {
        m_Timer_fileoutput.update();
        if (m_Timer_fileoutput.isFinished() && m_recording)
        {
            m_Timer_fileoutput.start();
            addTrackpoint();
        }
    }

};

FileWriter::FileWriter()
{

}

FileWriter::FileWriter(uint8_t _pin_cs, GPSSensor* _GPS, SDClass* _SD, String _extension = "csv")
{   
    m_extension = _extension;
    m_GPS = _GPS;
    m_SD = _SD;
    m_pin_cs = _pin_cs;
    m_created = false;
    m_recording = false;
}
FileWriter::~FileWriter()
{

}