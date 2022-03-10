#define COUNT_VALUES 20

class MagnetSensor
{
private:
    unsigned long m_values_diff[COUNT_VALUES]; // Beihaltet die Differenz der Zeitwerte der Aktivierungen
    unsigned int m_index_values = 0;           // Position im values Array des zuletzt geschriebenen Wertes
    unsigned long m_time_lastValue = 0;        // Zeit des letzten Wertes, um Timeout festzustellen
    unsigned long m_time_newValue = 0;         // Zeit des neuen Wertes, um Timeout festzustellen
    bool m_onceFull = false;                   // Values Array gefüllt
    bool m_interrupted = false;                // Interrupt am SensorPin erkannt
    double m_correction_factor = 1;            // Faktor zum Umrechnen/Korrigieren des AVG-Wertes
    unsigned int m_count_magnets = 1;          // Anzahl Magneten, welche Interrupts initiieren

public:
    double m_ptr_var = 0;      // Pointer zur Variablen für average Wert oder Pointer zur Zone oder sowas oder return?
    unsigned char m_SensorPin; // Pin des Sensors

    // Constructor - Destructor
    MagnetSensor(unsigned char SensorPin, unsigned int count_magnets);
    MagnetSensor(unsigned char SensorPin, double correction_factor, unsigned int count_magnets);
    ~MagnetSensor();

public:
    // Functions
    void update()
    {
        checkTimeout();
        if (m_interrupted)
        {
            newValue();
            if (m_onceFull)
            {
                m_ptr_var = 1 / calc_avg() * m_correction_factor;
            }
            m_interrupted = false;
        }
    }

    void interrupt()
    {
        m_interrupted = true;
    }

private:
    double calc_avg()
    {
        unsigned int sum = 0; // Summe aller Werte in m_values_diff
        for (size_t i = 0; i < COUNT_VALUES; i++)
        {
            sum += m_values_diff[i];
        }
        return sum / COUNT_VALUES;
    }

    void newValue()
    {
        if (m_time_newValue != 0)
        {
            m_time_lastValue = m_time_newValue;
        }

        m_time_newValue = millis();
        if (m_time_lastValue != 0)
        {
            m_values_diff[m_index_values] = m_time_newValue - m_time_lastValue;
            m_index_values++;
            if (m_index_values > COUNT_VALUES - 1)
            {
                m_index_values = 0;
                m_onceFull = true;
            }
        }
    }

    void checkTimeout()
    {
        if (millis() - m_time_lastValue > 10000)
        {
            noInterrupts();
            m_onceFull = false;
            m_index_values = 0;
            m_time_lastValue = 0;
            interrupts();
            m_ptr_var = 0;
        }
    }
};

MagnetSensor::MagnetSensor(unsigned char SensorPin, unsigned int count_magnets)
{
    m_count_magnets = count_magnets;
    m_SensorPin = SensorPin;
    pinMode(m_SensorPin, INPUT);
    m_values_diff[0] = millis();
}

MagnetSensor::MagnetSensor(unsigned char SensorPin, double correction_factor, unsigned int count_magnets)
{
    m_count_magnets = count_magnets;
    m_SensorPin = SensorPin;
    m_correction_factor = correction_factor;
    pinMode(m_SensorPin, INPUT);
    m_values_diff[0] = millis();
}

MagnetSensor::~MagnetSensor()
{
}
