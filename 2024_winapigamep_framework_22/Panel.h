#pragma once
#include "UI.h"
class Panel :
    public UI
{
    // UI��(��) ���� ��ӵ�
    void Init() override;
    void Update() override;
    void Render(HDC _hdc) override;
    void RenderText(HDC _hdc) override;

private:
    SIZE textSize;
};

