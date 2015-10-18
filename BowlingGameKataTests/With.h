#include "DoRoll.h"

template <class WithT>
class WithClass
{
    WithT* m_Object;
public:
    explicit WithClass(WithT* object) : m_Object(object) {}
    DoRoll<WithT> Roll(int pins) { return DoRoll<WithT>(m_Object, pins); }
};

template <class WithT>
WithClass<WithT> With(WithT* object) { return WithClass<WithT>(object); }