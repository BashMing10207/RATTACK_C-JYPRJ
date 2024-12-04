#pragma once
#include "Trigger.h"
#include "Texture.h"
class TreeWood : public Trigger
{
public:
	TreeWood() : Trigger()
	{
		Init();
	}

	void Init();

	void Render(HDC _hdc) override;
	Texture* m_pTex;
};

