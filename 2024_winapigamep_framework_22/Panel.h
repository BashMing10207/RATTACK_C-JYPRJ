#pragma once
#include "UI.h"
class Panel :
    public UI
{
public:
    // UI��(��) ���� ��ӵ�
    void Init() override;
    void Update() override;
    void Render(HDC _hdc) override;
    void RenderText(HDC _hdc) override;

private:
    SIZE textSize;
};

