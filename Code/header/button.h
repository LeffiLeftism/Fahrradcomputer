class Button
{
    private:
    uint8_t m_pin;
    bool m_isPressed = false;
    bool m_wasPressed = false;
    public:
    
    Button(uint8_t _pin);
    ~Button();

    private:

    public:
    void init()
    {
        pinMode(m_pin, INPUT_PULLUP);
    }

    void update()
    {
        m_isPressed = !digitalRead(m_pin);
        if (m_isPressed)
        {
            m_wasPressed = true;
            delay(20);
        }
    }

    bool getIsPressed()
    {
        return m_isPressed;
    }

    bool getWasPressed()
    {
        return m_wasPressed;
    }

    void resetWasPressed()
    {
        m_wasPressed = false;
    }
};

Button::Button(uint8_t _pin)
{
    m_pin = _pin;
}
Button::~Button()
{

}
