#pragma once
#include "Object.h"
#include "Texture.h"
class BackGroundObject : public Object
{
public:
	BackGroundObject(wstring str,bool isTrasn);
	void Init() override;
	void Update() override;
	void Render(HDC _hdc) override;
	Texture* m_pTex;
	bool isTransfer = false;
};

