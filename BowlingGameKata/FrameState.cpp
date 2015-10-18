#include "stdafx.h"
#include "FrameState.h"

static const int MaximumFrameScore = 10;

FrameState::FrameState() : m_CurrentFrameScore(0), m_BallCountInCurrentFrame(0)
{
}

bool FrameState::IsSpare()
{
    return m_CurrentFrameScore == MaximumFrameScore && m_BallCountInCurrentFrame == 2;
}

void FrameState::SetStateToStartOfFrame()
{
    m_BallCountInCurrentFrame = 0;
    m_CurrentFrameScore = 0;
}

void FrameState::Roll(int pins)
{
    if (IsAtEndOfFrame())
    {
        SetStateToStartOfFrame();
    }
    m_CurrentFrameScore += pins;
    m_BallCountInCurrentFrame++;
}

bool FrameState::IsStrike()
{
    return m_CurrentFrameScore == MaximumFrameScore && m_BallCountInCurrentFrame == 1;
}

bool FrameState::IsAtEndOfFrame()
{
    return m_BallCountInCurrentFrame == 2 || m_CurrentFrameScore == MaximumFrameScore;
}
