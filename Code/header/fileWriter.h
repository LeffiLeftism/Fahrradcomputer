#ifndef SD_H
#define SD_H
#include <SD.h>
#endif

#ifndef TIMER_H
#define TIMER_H
#include "header/timer.h"
#endif

#ifndef GPSSENSOR_H
#define GPSSENSOR_H
#include "header/gpsSensor.h"
#endif


class FileWriter
{
    private:
    SDClass m_SD;
    File m_myFile;
    Timer m_Timer_fileoutput(1000);
    GPSSensor* m_GPS;

    uint8_t m_pin_cs;
    String m_name, m_extension = ".csv";
    bool m_recording;

    public:
    FileWriter(String _name, String _extension, uint8_t _pin_cs, GPSSensor* _GPS);
    ~FileWriter();

    private:
    String filename()
    {
        m_name = m_GPS->getTime(true);
        return sprintf("%s.%s", m_name, m_extension);
    }

    void createFile()
    {
        m_myFile = m_SD.open(filename(), FILE_WRITE);
        m_myFile.println("Time,Latitude,Longitude,Altitude,Cadence"); //Heartrate not collected
        m_myFile.close();
        m_Timer_fileoutput.start();
    }

    void addTrackpoint()
    {
        m_myFile = SD.open(filename, FILE_WRITE);
        m_myFile.print(GPS.getDate());
        m_myFile.print("T");
        m_myFile.print(GPS.getTime());
        m_myFile.print("z,");
        m_myFile.print(GPS.getLatitude(), 6);
        m_myFile.print(",");
        m_myFile.print(GPS.getLongitude(), 6);
        m_myFile.print(",");
        m_myFile.print(GPS.getAltitude(), 2);
        m_myFile.print(",");
        // m_myFile.print(64); Heartrate not collected
        // m_myFile.print(",");
        m_myFile.print(Pedal_RPM.m_ptr_var, 2);
        m_myFile.println();
        m_myFile.close();
    }

    
    public:
    void startRecording()
    {
        createFile();
        m_recording = true;
    }

    void stopRecording()
    {
        m_recording = false;
    }

    void update()
    {
        if (m_Timer_fileoutput.isFinished() && m_recording)
        {
            m_Timer_fileoutput.start();
            addTrackpoint();
        }
    }

};

FileWriter::FileWriter(uint8_t _pin_cs, GPSSensor* _GPS)
{   
    m_GPS = _GPS;
    m_pin_cs = _pin_cs;
    m_recording = false;

    m_SD.begin(m_pin_cs);
    m_Timer_fileoutput.init();
}
FileWriter::~FileWriter()
{

}