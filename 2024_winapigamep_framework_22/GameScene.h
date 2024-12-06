#pragma once
#include "Scene.h"
#include "UI.h"
class GameScene :
    public Scene
{
public:
    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
private:
    vector<UI*> m_Items;
};

