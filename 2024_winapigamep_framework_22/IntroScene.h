#pragma once
#include "Scene.h"
class IntroScene :
	public Scene
{
public:
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC _hdc) override;
};