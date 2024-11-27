#pragma once

class SceneManager;
class MapManager
{
	DECLARE_SINGLE(MapManager);
public:
	MapManager();
	~MapManager();
public:
	void Render(HDC _hdc);
public:
	int mapW = 10;
	int mapH = 10;
	int mapArr[10][10] = {0, {0,} };
};

