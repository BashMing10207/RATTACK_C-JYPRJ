#pragma once
#include "UI.h"

struct UIPosition
{
	float x;
	float y;
	float width;
	float height;
};

class UIManager
{
	DECLARE_SINGLE(UIManager);
public:
	void Init();
	void Render(HDC _hdc);

	vector<UI*> m_vecItemUIs;

};
