#pragma once
#include "Object.h"
class Potal :
    public Object
{
public:
    // Object을(를) 통해 상속됨
    void Update() override;
    void Render(HDC _hdc) override;

};

