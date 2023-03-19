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

#ifndef TIMER_H
#define TIMER_H
#include "timer.h"
#endif


class ScreenManager
{
private:
    Button** m_ptr_arr_btn;
    Bildschirm** m_ptr_arr_bildschirm;
    Adafruit_SSD1306* m_display;
    void(*m_fct_ptr_up)(int8_t*, uint8_t) = nullptr;
    void(*m_fct_ptr_down)(int8_t*, uint8_t) = nullptr;
    void(*m_fct_ptr_set)(int8_t*, uint8_t) = nullptr;
    void(*m_fct_ptr_enter)(int8_t*, uint8_t) = nullptr;
    Timer m_Timer_selected_zone = Timer(10000);
public:
    int8_t m_selected_bildschirm;
    int8_t m_selected_zone;
    uint8_t m_count_btn;
    uint8_t m_count_bildschirm;


    pair btn_fct[1][13][3] = { // Bildschirm - Zone - Button
        // Bildschirm 1
        { // Button 0, 1, 2
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 18), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z1
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z2
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z3
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z4
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z5
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z6
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z7
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z8
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z9
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z10
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z11
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)},      // z12
            {pair(&m_fct_ptr_down, &m_selected_zone, 1), pair(&m_fct_ptr_enter, &m_selected_zone, 1), pair(&m_fct_ptr_up, &m_selected_zone, 1)}}      // z13
    };

    void updateButtons()
    {
        for (size_t i = 0; i < m_count_btn; i++)
        {
            (*(m_ptr_arr_btn + i))->update();
        }
    }

    void runBtnFct()
    {
        m_Timer_selected_zone.update();
        if (m_Timer_selected_zone.isFinished())
        {
            m_selected_zone = -1;
        }
        for (size_t i = 0; i < m_count_btn; i++)
        {
            Button* btn = m_ptr_arr_btn[i];
            if (btn->getWasPressed() && !btn->getIsPressed())
            {
                m_Timer_selected_zone.start();
                btn->resetWasPressed();
                pair usedPair = btn_fct[0][0][i];
                usedPair.run();

                // check zone selectability
                checkSelectable:
                while (usedPair.getPtr() == &m_selected_zone && !m_ptr_arr_bildschirm[m_selected_bildschirm]->getZoneSelectable(m_selected_zone) &&
                m_selected_zone < m_ptr_arr_bildschirm[m_selected_bildschirm]->getMaxZones())
                {
                    if (usedPair.getFctPtr() == &m_fct_ptr_up)
                    {
                        m_selected_zone++;
                    } else if (usedPair.getFctPtr() == &m_fct_ptr_down)
                    {
                        m_selected_zone--;
                    }
                }
                if (m_selected_zone < 0)
                {
                    m_selected_zone = m_ptr_arr_bildschirm[m_selected_bildschirm]->getMaxZones() - 1;
                    goto checkSelectable;
                } else if (m_selected_zone >= m_ptr_arr_bildschirm[m_selected_bildschirm]->getMaxZones())
                {
                    m_selected_zone = 0;
                    goto checkSelectable;
                }
            }
        }
    }

public:
    ScreenManager(
        Button** _ptr_arr_btn, uint8_t _count_btn, 
        Bildschirm** _ptr_arr_bildschirm, uint8_t _count_bildschirm,
        Adafruit_SSD1306* _display,
        void(*_fct_ptr_up)(int8_t*, uint8_t),
        void(*_fct_ptr_down)(int8_t*, uint8_t),
        void(*_fct_ptr_set)(int8_t*, uint8_t),
        void(*_fct_ptr_enter)(int8_t*, uint8_t));
    ~ScreenManager();

    void init()
    {
        m_Timer_selected_zone.init();            
        m_Timer_selected_zone.start();
        // Initialize Buttons
        for (size_t i = 0; i < m_count_btn; i++)
        {
            (*(m_ptr_arr_btn + i))->init();
        }
    }

    void update()
    {
        updateButtons();
        runBtnFct();
    }

    void print()
    {
        m_display->clearDisplay();
        (*(m_ptr_arr_bildschirm + m_selected_bildschirm))->print(m_display, m_selected_zone);
        m_display->display();
    }

    bool tester()
    {
        return m_selected_zone >= (*(m_ptr_arr_bildschirm + m_selected_bildschirm))->getMaxZones();
    }
};

ScreenManager::ScreenManager(
    Button** _ptr_arr_btn, uint8_t _count_btn, 
    Bildschirm** _ptr_arr_bildschirm, uint8_t _count_bildschirm, 
    Adafruit_SSD1306* _display,
    void(*_fct_ptr_up)(int8_t*, uint8_t),
    void(*_fct_ptr_down)(int8_t*, uint8_t),
    void(*_fct_ptr_set)(int8_t*, uint8_t),
    void(*_fct_ptr_enter)(int8_t*, uint8_t))
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
    m_selected_zone = 0;
}

ScreenManager::~ScreenManager()
{
}
