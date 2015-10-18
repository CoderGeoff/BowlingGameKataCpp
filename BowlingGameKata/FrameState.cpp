#include "stdafx.h"
#include "FrameState.h"


FrameState::FrameState() : m_CurrentFrameScore(0), m_IsAtEndOfFrame(true)
{
}

bool FrameState::IsSpare()
{
    const int MaximumFrameScore = 10;
    return m_CurrentFrameScore == MaximumFrameScore && m_IsAtEndOfFrame;
}

void FrameState::Roll(int pins)
{
    if (m_IsAtEndOfFrame)
    {
        m_CurrentFrameScore = 0;
    }
    m_CurrentFrameScore += pins;
    m_IsAtEndOfFrame = !m_IsAtEndOfFrame;
}
