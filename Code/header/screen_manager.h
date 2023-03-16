#ifndef BILDSCHIRM_H
#define BILDSCHIRM_H
#include "bildschirm.h"
#endif

#ifndef BUTTON_H
#define BUTTON_H
#include "button.h"
#endif


class ScreenManager
{
private:
    Button** m_ptr_arr_btn;
    Bildschirm** m_ptr_arr_bildschirm;
    Adafruit_SSD1306* m_display;

    uint8_t m_selected_bildschirm;
    uint8_t m_count_btn;
    uint8_t m_count_bildschirm;

    void updateButtons()
    {
        for (size_t i = 0; i < m_count_btn; i++)
        {
            (*(m_ptr_arr_btn + i))->update();
        }
    }

public:
    ScreenManager(
        Button** _ptr_arr_btn, uint8_t _count_btn, 
        Bildschirm** _ptr_arr_bildschirm, uint8_t _count_bildschirm,
        Adafruit_SSD1306* _display);
    ~ScreenManager();

    void init()
    {
        // Initialize Buttons
        for (size_t i = 0; i < m_count_btn; i++)
        {
            (*(m_ptr_arr_btn + i))->init();
        }
    }

    void print()
    {
        m_display->clearDisplay();
        (*(m_ptr_arr_bildschirm + m_selected_bildschirm))->print(m_display);
        m_display->display();
    }
};

ScreenManager::ScreenManager(
    Button** _ptr_arr_btn, uint8_t _count_btn, 
    Bildschirm** _ptr_arr_bildschirm, uint8_t _count_bildschirm, 
    Adafruit_SSD1306* _display)
{
    m_ptr_arr_btn = _ptr_arr_btn;
    m_count_btn = _count_btn;
    m_ptr_arr_bildschirm = _ptr_arr_bildschirm;
    m_count_bildschirm = _count_bildschirm;

    m_display = _display;
    m_selected_bildschirm = 0;
}

ScreenManager::~ScreenManager()
{
}
