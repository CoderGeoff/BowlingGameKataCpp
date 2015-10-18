#include "DoRoll.h"

template <class WithT>
class With
{
    WithT* m_Object;
public:
    explicit With(WithT* game) : m_Object(game) {}
    DoRoll<WithT> Roll(int pins) { return DoRoll<WithT>(m_Object, pins); }
};

