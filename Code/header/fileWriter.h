#ifndef SD_H
#define SD_H
#include <SD.h>
#endif

#ifndef GPSSENSOR_H
#define GPSSENSOR_H
#include "gpsSensor.h"
#endif

#ifndef TIMER_H
#define TIMER_H
#include "timer.h"
#endif

class FileWriter
{
    private:
    SDClass* m_SD;
    GPSSensor* m_GPS;
    Timer m_TrackerTimer = Timer(1000);
    File myFile;
    String filename;
    uint8_t m_pin_cs;
    public:
    FileWriter(SDClass* _SD, GPSSensor* _GPS, uint8_t _pin_cs);
    ~FileWriter();

    void init()
    {
        m_SD->begin(m_pin_cs);
        m_TrackerTimer.init();
    }

    void createFile()
    {
        // Create CSV-File
        filename = "testfile.csv";
        myFile = SD.open(filename, FILE_WRITE);
        myFile.println("Time,Latitude,Longitude,Altitude,Heartrate,Cadence");
        myFile.close();
        // Check if File got created
        if (!SD.exists(filename))
        {  
            digitalWrite(25, HIGH);
            delay(500);
            digitalWrite(25, LOW);
        }
        m_TrackerTimer.start();
    }
    
    void addTrackpoint()
    {
        myFile = SD.open(filename, FILE_WRITE);
        myFile.print(m_GPS->getDate());
        myFile.print("T");
        myFile.print(m_GPS->getTime());
        myFile.print("z,");
        myFile.print(m_GPS->getLatitude(), 6);
        myFile.print(",");
        myFile.print(m_GPS->getLongitude(), 6);
        myFile.print(",");
        myFile.print(m_GPS->getAltitude(), 2);
        myFile.print(",");
        myFile.print(54);
        myFile.print(",");
        myFile.print("RPM"); //Pedal_RPM.m_ptr_var, 2);
        myFile.println();
        myFile.close();
    }

    void update()
    {
        m_TrackerTimer.update();
        if (m_TrackerTimer.isFinished())
        {
            addTrackpoint();
            m_TrackerTimer.start();
        }
        
    }
};

FileWriter::FileWriter(SDClass* _SD, GPSSensor* _GPS, uint8_t _pin_cs)
{
    m_SD = _SD;
    m_GPS = _GPS;
    m_pin_cs = _pin_cs;
    
}

FileWriter::~FileWriter()
{

}