#include "stdafx.h"

class Bonus
{
    int m_NumberOfBonusesRemaining;
public:
    explicit Bonus(int numberOfBonusesToBeGranted);
    bool GrantForOneBall();
};

