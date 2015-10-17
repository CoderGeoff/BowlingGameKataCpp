#pragma once
class BowlingGame
{
    int m_RunningTotal;
public:
    BowlingGame();
    void Roll(int pins);
    int Score();
};

