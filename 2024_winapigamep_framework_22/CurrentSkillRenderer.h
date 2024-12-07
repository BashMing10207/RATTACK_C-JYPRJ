#pragma once
#include "Component.h"
#include "Texture.h"
class CurrentSkillRenderer :
    public Component
{
public:
    CurrentSkillRenderer();
    ~CurrentSkillRenderer();

    // Component을(를) 통해 상속됨
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    Texture* m_pTex;
   

};


