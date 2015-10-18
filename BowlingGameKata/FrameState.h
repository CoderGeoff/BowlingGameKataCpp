#pragma once
class FrameState
{
    int m_CurrentFrameScore;
    int m_BallCountInCurrentFrame;
    bool IsAtEndOfFrame();
public:
    FrameState();
    bool IsSpare();
    void Roll(int pins);
    bool IsStrike();
};

