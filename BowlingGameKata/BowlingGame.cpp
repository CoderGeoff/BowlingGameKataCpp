#include "stdafx.h"
#include "BowlingGame.h"
#include <algorithm>

BowlingGame::BowlingGame()
    : m_RunningTotal(0), m_StrikeBonusActive(false), m_FrameState(std::make_unique<FrameState>())
{
}

void BowlingGame::Roll(int pins)
{
    m_RunningTotal += BonusFromSparesAndStrikes(pins);
    m_RunningTotal += pins;
    m_FrameState->Roll(pins);

    if (m_FrameState->IsStrike() || m_FrameState->IsSpare())
    {
        int bonusBallCount = m_FrameState->IsSpare() ? 1 : 2;
        m_Bonuses.push_back(std::make_shared<Bonus>(bonusBallCount));
    }
}

int BowlingGame::Score()
{
    return m_RunningTotal;
}

int BowlingGame::BonusFromSparesAndStrikes(int pins) const
{
    auto spareAndStrikeBonusCounter = [](const std::shared_ptr<Bonus>& bonus) -> bool { return bonus->GrantForOneBall(); };
    int numberOfSpareAndStrikeBonusesActive = std::count_if(m_Bonuses.begin(), m_Bonuses.end(), spareAndStrikeBonusCounter);
    return pins * numberOfSpareAndStrikeBonusesActive;
}

