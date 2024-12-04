#pragma once
#include "NewPorjectile.h"
class Granade :
    public NewPorjectile
{
public:
    Granade() :NewPorjectile()
    {
        Init();
    }

    virtual void Init() override;
    void Render(HDC hdc) override;
    void Summoner() override;
};

