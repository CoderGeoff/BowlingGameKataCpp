#include "stdafx.h"
#include "Bonus.h"

Bonus::Bonus(int numberOfBonusesToBeGranted) : m_NumberOfBonusesRemaining(numberOfBonusesToBeGranted)
{
}

bool Bonus::GrantForOneBall()
{
    return true;
}