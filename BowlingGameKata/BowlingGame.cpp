#include "stdafx.h"
#include "BowlingGame.h"


BowlingGame::BowlingGame()
    : m_RunningTotal(0)
{
}

void BowlingGame::Roll(int pins)
{
    m_RunningTotal += pins;
}

int BowlingGame::Score()
{
    return m_RunningTotal;
}
