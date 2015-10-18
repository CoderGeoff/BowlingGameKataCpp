#pragma once
#include <memory>
#include "FrameState.h"
#include "Bonus.h"
#include <list>

class BowlingGame
{
    int m_RunningTotal;
    bool m_StrikeBonusActive;
    std::unique_ptr<FrameState> m_FrameState;
    std::list<std::shared_ptr<Bonus>> m_Bonuses;
    int BonusFromSparesAndStrikes(int pins) const;
public:
    BowlingGame();
    void Roll(int pins);
    int Score();
};

