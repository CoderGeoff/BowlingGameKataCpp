#include "stdafx.h"
#include "BowlingGame.h"

BowlingGame::BowlingGame()
    : m_RunningTotal(0), m_StrikeBonusActive(false), m_FrameState(std::make_unique<FrameState>())
{
}

void BowlingGame::Roll(int pins)
{
    if (m_FrameState->IsSpare())
    {
        m_RunningTotal += pins;
    }
    if (m_StrikeBonusActive)
    {
        m_RunningTotal += pins;
        m_StrikeBonusActive = false;
    }
    if (m_FrameState->IsStrike())
    {
        m_RunningTotal += pins;
        m_StrikeBonusActive = true;
    }
    m_RunningTotal += pins;
    m_FrameState->Roll(pins);
}

int BowlingGame::Score()
{
    return m_RunningTotal;
}
