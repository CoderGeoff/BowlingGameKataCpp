#include "DoRoll.h"

class BowlingGame;
class WithGame
{
    BowlingGame* m_Game;
public:
    explicit WithGame(BowlingGame* game) : m_Game(game) {}
    DoRoll Roll(int pins) { return DoRoll(m_Game, pins); }
};

