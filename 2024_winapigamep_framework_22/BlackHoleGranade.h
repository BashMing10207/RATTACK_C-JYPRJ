#pragma once
#include "NewPorjectile.h"
class BlackHoleGranade :
    public NewPorjectile
{
public:
    BlackHoleGranade();

    void Render(HDC hdc) override;
    void Summoner() override;
};

