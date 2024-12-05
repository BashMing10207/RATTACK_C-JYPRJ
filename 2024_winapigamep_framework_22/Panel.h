#pragma once
#include "UI.h"
class Panel :
    public UI
{
public:
    // UI을(를) 통해 상속됨
    void Init() override;
    void Update() override;
    void Render(HDC _hdc) override;
    void RenderText(HDC _hdc) override;

private:
    SIZE textSize;
};

