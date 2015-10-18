#pragma once
#include <memory>
#include "FrameState.h"

class BowlingGame
{
    int m_RunningTotal;
    std::unique_ptr<FrameState> m_FrameState;
public:
    BowlingGame();
    void Roll(int pins);
    int Score();
};

