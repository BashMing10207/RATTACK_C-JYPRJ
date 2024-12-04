#pragma once
#include "NewPorjectile.h"
class BlackHoleGranade :
    public NewPorjectile
{
    void Render(HDC hdc) override;
    void Summoner() override;
};

