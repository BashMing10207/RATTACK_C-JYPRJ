#pragma once
#include "Scene.h"
class IntroScene :
	public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update();
	virtual void Render(HDC _hdc) override;
};

