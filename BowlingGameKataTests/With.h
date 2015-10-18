#include "DoRoll.h"

template <class WithT>
class With
{
    WithT* m_Object;
public:
    explicit With(WithT* object) : m_Object(object) {}
    DoRoll<WithT> Roll(int pins) { return DoRoll<WithT>(m_Object, pins); }
};

