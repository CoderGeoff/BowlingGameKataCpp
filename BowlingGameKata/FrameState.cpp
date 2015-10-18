#include "stdafx.h"
#include "FrameState.h"

static const int MaximumFrameScore = 10;
static const int FinalFrameNumber = 9;

FrameState::FrameState() : m_CurrentFrameCount(0), m_CurrentFrameScore(0), m_BallCountInCurrentFrame(0)
{
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

bool FrameState::IsStrike() const
{
    if (IsBonusBall()) return false;
    return m_CurrentFrameScore == MaximumFrameScore && m_BallCountInCurrentFrame == 1;
}

bool FrameState::IsSpare() const
{
    return m_CurrentFrameScore == MaximumFrameScore && m_BallCountInCurrentFrame == 2;
}

bool FrameState::IsAtEndOfFrame() const
{
    if (m_CurrentFrameCount == FinalFrameNumber) return false;
    return m_BallCountInCurrentFrame == 2 || m_CurrentFrameScore == MaximumFrameScore;
}

void FrameState::SetStateToStartOfFrame()
{
    m_BallCountInCurrentFrame = 0;
    m_CurrentFrameScore = 0;
    m_CurrentFrameCount++;
}

bool FrameState::IsBonusBall() const
{
    return m_CurrentFrameCount == FinalFrameNumber && m_CurrentFrameScore >= MaximumFrameScore;
}