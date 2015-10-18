#pragma once
class FrameState
{
    int m_CurrentFrameCount;
    int m_CurrentFrameScore;
    int m_BallCountInCurrentFrame;
    bool IsAtEndOfFrame() const;
    void SetStateToStartOfFrame();
public:
    FrameState();
    void Roll(int pins);
    bool IsStrike() const;
    bool IsSpare() const;
    bool IsBonusBall() const;
};

