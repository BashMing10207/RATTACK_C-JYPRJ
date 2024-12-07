#pragma once
#include "Scene.h"
#include "UI.h"
#include "Item.h"
class GameScene :
    public Scene
{
public:
    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    wstring ItemTypeToWString(ItemType _item);
    wstring ItemTypeToPath(ItemType _item);
private:
    vector<UI*> m_Items;
};

