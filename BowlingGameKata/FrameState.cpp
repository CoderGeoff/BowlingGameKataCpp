#include "stdafx.h"
#include "FrameState.h"


FrameState::FrameState() : m_CurrentFrameScore(0)
{
}

bool FrameState::IsSpare()
{
    const int MaximumFrameScore = 10;
    return m_CurrentFrameScore == MaximumFrameScore;
}

void FrameState::Roll(int pins)
{
    m_CurrentFrameScore += pins;
}
