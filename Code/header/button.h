
class Button
{
    private:
    uint8_t m_pin;
    bool m_state;
    public:
    
    Button(uint8_t _pin);
    ~Button();

    private:

    public:
    void init()
    {
        pinMode(m_pin, INPUT);
    }

    void update()
    {
        m_state = digitalRead(m_pin);
    }

    bool read()
    {   
        update();
        return m_state;
    }
};

Button::Button(uint8_t _pin)
{
    m_pin = _pin;
}
Button::~Button()
{

}
