#pragma once
#include "IBonus.h"

class SpareBonus : public IBonus
{
public:
    virtual bool Grant() const override;
    virtual ~SpareBonus() {}
};

