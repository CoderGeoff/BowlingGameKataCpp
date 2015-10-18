#include "stdafx.h"
#include "FrameState.h"

static const int MaximumFrameScore = 10;

FrameState::FrameState() : m_CurrentFrameScore(0), m_IsAtEndOfFrame(true), m_BallCountInCurrentFrame(0)
{
}

bool FrameState::IsSpare()
{
    return m_CurrentFrameScore == MaximumFrameScore && m_BallCountInCurrentFrame == 2;
}

void FrameState::Roll(int pins)
{
    if (m_IsAtEndOfFrame)
    {
        m_BallCountInCurrentFrame = 0;
    }
    m_BallCountInCurrentFrame++;
    m_CurrentFrameScore = m_IsAtEndOfFrame ? pins : m_CurrentFrameScore + pins;
    m_IsAtEndOfFrame = m_BallCountInCurrentFrame == 2 || pins == MaximumFrameScore;
}

bool FrameState::IsStrike()
{
    return m_CurrentFrameScore == MaximumFrameScore && m_BallCountInCurrentFrame == 1;
}