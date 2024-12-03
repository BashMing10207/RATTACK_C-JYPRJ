#pragma once
#include "NewPorjectile.h"
class Granade :
    public NewPorjectile
{
    void Render(HDC hdc) override;
    void Summoner() override;
};

