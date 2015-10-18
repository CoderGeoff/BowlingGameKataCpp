#pragma once
class FrameState
{
    int m_CurrentFrameScore;
    bool m_IsAtEndOfFrame;
    int m_BallCountInCurrentFrame;
public:
    FrameState();
    bool IsSpare();
    void Roll(int pins);
    bool IsStrike();
};

