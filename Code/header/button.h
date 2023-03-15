class Button
{
    private:
    uint8_t m_pin;
    bool m_pressed;
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
        m_pressed = false;
        while (!digitalRead(m_pin))
        {
            m_pressed = true;
            // Debounce delay
            delay(30);
        }
    }
};

Button::Button(uint8_t _pin)
{
    m_pin = _pin;
}
Button::~Button()
{

}
