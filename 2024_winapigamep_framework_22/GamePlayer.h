#pragma once
#include"Stone.h"
#include "Item.h"

class GamePlayer
{
public:

	int stonecnt = 6, selectecIndex=0, deadStonecnt=0;
	bool isBlack = true;
	vector<Stone*> stones;
	vector<Item> items;

	GamePlayer(bool isNigger);
	~GamePlayer();
	void Init();
	void SetPlayer();
	void AddObject(Stone* _obj)
	{
		stones.push_back(_obj);
	}

	void AddItem(Item item);
	void UseItemIdx(int idx);
	void Update();
	void LateUpdate();

	void UseItem() {items.erase(items.begin() + selectecIndex);}
};
