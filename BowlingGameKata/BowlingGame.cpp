#include "stdafx.h"
#include "BowlingGame.h"

BowlingGame::BowlingGame()
    : m_RunningTotal(0), m_FrameState(std::make_unique<FrameState>())
{
}

void BowlingGame::Roll(int pins)
{
    if (m_FrameState->IsSpare())
    {
        m_RunningTotal += pins;
    }
    m_RunningTotal += pins;
    m_FrameState->Roll(pins);
}

int BowlingGame::Score()
{
    return m_RunningTotal;
}
