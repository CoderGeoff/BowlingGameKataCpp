#include "../BowlingGameKata/BowlingGame.h"

class DoRoll
{
    BowlingGame* m_Game;
    int m_Pins;
    friend class WithGame;
    explicit DoRoll(BowlingGame* game, int pins) : m_Game(game), m_Pins(pins) {}
public:
    void Times(int times)
    {
        for (int i = 0; i < times; ++i)
        {
            m_Game->Roll(m_Pins);
        }
    }
};
