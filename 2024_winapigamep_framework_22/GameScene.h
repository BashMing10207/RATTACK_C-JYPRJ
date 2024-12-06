#pragma once
#include "Scene.h"
#include "UI.h"
class GameScene :
    public Scene
{
public:
    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
private:
    vector<UI*> m_Items;
};

