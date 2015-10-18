#include "stdafx.h"
#include "FrameState.h"

static const int MaximumFrameScore = 10;

FrameState::FrameState() : m_CurrentFrameScore(0), m_IsAtEndOfFrame(true)
{
}

bool FrameState::IsSpare()
{
    return m_CurrentFrameScore == MaximumFrameScore && m_IsAtEndOfFrame;
}

void FrameState::Roll(int pins)
{
    m_CurrentFrameScore = m_IsAtEndOfFrame ? pins : m_CurrentFrameScore + pins;
    m_IsAtEndOfFrame = !m_IsAtEndOfFrame;
}

bool FrameState::IsStrike()
{
    return m_CurrentFrameScore == MaximumFrameScore;
}