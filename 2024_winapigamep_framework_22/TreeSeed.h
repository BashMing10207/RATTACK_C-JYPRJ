#pragma once
#include "NewPorjectile.h"
class TreeSeed : public NewPorjectile
{
public:
    TreeSeed() :NewPorjectile()
    {
        Init();
    }

    virtual void Init() override;
    void Render(HDC hdc) override;
    void Summoner() override;

};