#pragma once
class FrameState
{
    int m_CurrentFrameScore;
    bool m_IsSecondBallOfFrame;
public:
    FrameState();
    bool IsSpare();
    void Roll(int pins);
};

