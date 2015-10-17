#pragma once
class BowlingGame
{
private:
    int m_RunningTotal;
public:
    BowlingGame();
    void Roll(int pins);
    int Score();
};

