#pragma once

class SceneManager;
class UIManager
{
	DECLARE_SINGLE(UIManager);
public:
	float widMax = SCREEN_WIDTH;
	float heiMax = SCREEN_HEIGHT;
public:
	void Update();
	void Render(HDC _hdc);
};

