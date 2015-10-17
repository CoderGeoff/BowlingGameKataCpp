#include "stdafx.h"
#include "FrameState.h"


FrameState::FrameState() : m_CurrentFrameScore(0), m_IsSecondBallOfFrame(true)
{
}

bool FrameState::IsSpare()
{
    const int MaximumFrameScore = 10;
    return m_CurrentFrameScore == MaximumFrameScore && m_IsSecondBallOfFrame;
}

void FrameState::Roll(int pins)
{
    m_CurrentFrameScore += pins;
    m_IsSecondBallOfFrame = !m_IsSecondBallOfFrame;
}
