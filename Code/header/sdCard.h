#include <SD.h>

class SDCard
{
    private:
        File myFile;
        String fileName;
    public:
    // Constructor - Destructor
    SDCard();
    ~SDCard();
    
    public:
    
};

SDCard::SDCard()
{

}
SDCard::~SDCard()
{
    
}

/*
    sprintf(date1, "%4d-%02d-%02dT%02d:%02d:%02dZ",year, month, day, hour,minute,second);
    Serial.println(date1);

    dataFile = SD.open(filepath, FILE_WRITE);
    unsigned long filesize = dataFile.size();
    // back up the file pointer to just before the closing tags
    filesize -= 27;
    dataFile.seek(filesize);
    dataFile.print(F("<trkpt lat=\"")); 
    dataFile.print(latitude,7);
    dataFile.print(F("\" lon=\""));
    dataFile.print(longitude,7);
    dataFile.println(F("\">"));
    dataFile.print(F("<time>"));
    dataFile.print(date1);
    dataFile.println(F("</time>"));      
    dataFile.print(F("<ele>")); 
    dataFile.print(falt,1);
    dataFile.print(F("</ele>\r\n<hdop>")); 
    //dataFile.print(F("<hdop>")); 
    dataFile.print(h_dop1,3);
    dataFile.println(F("</hdop>\r\n</trkpt>"));
    dataFile.print(F("</trkseg>\r\n</trk>\r\n</gpx>\r\n"));
    dataFile.close();
*/