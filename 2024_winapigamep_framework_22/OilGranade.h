#pragma once
#include "NewPorjectile.h"
class OilGranade :
    public NewPorjectile
{
    void Render(HDC hdc) override;
    void Summoner() override;
};

