#pragma once

class SceneManager;
class MapManager
{
	DECLARE_SINGLE(MapManager);
public:
	//MapManager();
	//~MapManager();
public:
	void Render(HDC _hdc);
	void RenderMing(HDC _hdc);
public:
	int mapW = 16;
	int mapH = 10;
	int mapArr[16][10] = {0, {0,} };
public:
	bool isLoadMap = true;
	bool canStart = false;
};

