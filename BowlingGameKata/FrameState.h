#pragma once
class FrameState
{
    int m_CurrentFrameScore;
    int m_BallCountInCurrentFrame;
    bool IsAtEndOfFrame();
    void SetStateToStartOfFrame();
public:
    FrameState();
    void Roll(int pins);
    bool IsStrike();
    bool IsSpare();
};

