#pragma once
#include "Object.h"
class Potal :
    public Object
{
public:
    // Object��(��) ���� ��ӵ�
    void Update() override;
    void Render(HDC _hdc) override;

};

