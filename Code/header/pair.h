struct pair
{
private:
    void(**m_fct_ptr_btn)(int8_t*, uint8_t) = nullptr;
    int8_t* m_ptr;
    uint8_t m_stepsize;
public:
    pair()
    {
        m_fct_ptr_btn = nullptr;
        m_ptr = nullptr;
        m_stepsize = 0;
    }
    pair(void(**_fct_ptr_btn)(int8_t*, uint8_t), int8_t* _ptr, uint8_t _m_stepsize)
    {
        m_fct_ptr_btn = _fct_ptr_btn;
        m_ptr = _ptr;
        m_stepsize = _m_stepsize; 
    }

    void run()
    {
        if (m_fct_ptr_btn != nullptr)
        {
        (*m_fct_ptr_btn)(m_ptr, m_stepsize); 
        }
    }
    int8_t* getPtr()
    {
        return m_ptr;
    }

    void (**getFctPtr())(int8_t*, uint8_t)
    {
        return m_fct_ptr_btn;
    }
};
