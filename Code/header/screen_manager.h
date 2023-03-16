#ifndef BILDSCHIRM_H
#define BILDSCHIRM_H
#include "bildschirm.h"
#endif

#ifndef BUTTON_H
#define BUTTON_H
#include "button.h"
#endif

#ifndef PAIR_H
#define PAIR_H
#include "pair.h"
#endif


class ScreenManager
{
private:
    Button** m_ptr_arr_btn;
    Bildschirm** m_ptr_arr_bildschirm;
    Adafruit_SSD1306* m_display;
    void(*m_fct_ptr_up)(uint8_t*, uint8_t) = nullptr;
    void(*m_fct_ptr_down)(uint8_t*, uint8_t) = nullptr;
    void(*m_fct_ptr_set)(uint8_t*, uint8_t) = nullptr;
    void(*m_fct_ptr_enter)(uint8_t*, uint8_t) = nullptr;

    uint8_t m_selected_bildschirm;
    uint8_t m_selected_zone;
    uint8_t m_count_btn;
    uint8_t m_count_bildschirm;

    pair btn_fct[1][13][3] = { // Bildschirm - Zone - Button
        // Bildschirm 1
        { // Button 0, 1, 2
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z1
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z2
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z3
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z4
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z5
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z6
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z7
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z8
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z9
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z10
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z11
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)},      // z12
            {pair(m_fct_ptr_down, &m_selected_zone, 1), pair(m_fct_ptr_enter, &m_selected_zone, 1), pair(m_fct_ptr_up, &m_selected_zone, 1)}}      // z13
    };

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
        Adafruit_SSD1306* _display,
        void(*_fct_ptr_up)(uint8_t*, uint8_t),
        void(*_fct_ptr_down)(uint8_t*, uint8_t),
        void(*_fct_ptr_set)(uint8_t*, uint8_t),
        void(*_fct_ptr_enter)(uint8_t*, uint8_t));
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
    Adafruit_SSD1306* _display,
    void(*_fct_ptr_up)(uint8_t*, uint8_t),
    void(*_fct_ptr_down)(uint8_t*, uint8_t),
    void(*_fct_ptr_set)(uint8_t*, uint8_t),
    void(*_fct_ptr_enter)(uint8_t*, uint8_t))
{
    m_ptr_arr_btn = _ptr_arr_btn;
    m_count_btn = _count_btn;
    m_ptr_arr_bildschirm = _ptr_arr_bildschirm;
    m_count_bildschirm = _count_bildschirm;

    m_fct_ptr_up = _fct_ptr_up;
    m_fct_ptr_down = _fct_ptr_down;
    m_fct_ptr_set = _fct_ptr_set;
    m_fct_ptr_enter = _fct_ptr_enter;

    m_display = _display;
    m_selected_bildschirm = 0;
}

ScreenManager::~ScreenManager()
{
}
