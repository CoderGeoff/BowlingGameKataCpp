template <class WithT> class With;

template <class WithT>
class DoRoll
{
    WithT* m_Object;
    int m_Pins;

    explicit DoRoll(WithT* object, int pins) : m_Object(object), m_Pins(pins) {}

    friend class With<WithT>;
public:
    void Times(int times)
    {
        for (int i = 0; i < times; ++i)
        {
            m_Object->Roll(m_Pins);
        }
    }
};
