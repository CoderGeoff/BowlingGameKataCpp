#pragma once
class FrameState
{
    int m_CurrentFrameScore;
    bool m_IsAtEndOfFrame;
public:
    FrameState();
    bool IsSpare();
    void Roll(int pins);
};

