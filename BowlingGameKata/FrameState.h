#pragma once
class FrameState
{
    int m_CurrentFrameScore;
public:
    FrameState();
    bool IsSpare();
    void Roll(int pins);
};

