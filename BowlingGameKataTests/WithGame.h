#include "DoRoll.h"

template <class WithT>
class WithGame
{
    WithT* m_Object;
public:
    explicit WithGame(WithT* game) : m_Object(game) {}
    DoRoll<WithT> Roll(int pins) { return DoRoll<WithT>(m_Object, pins); }
};

