#pragma once
#include"Stone.h"
#include "Item.h"

class GamePlayer
{
public:

	int stonecnt = 6, selectecIndex=0, deadStonecnt=0;
	bool isBlack = true;
	vector<Stone*> stones;
	vector<ItemType> items;

	GamePlayer(bool isNigger);
	~GamePlayer();
	void Init();
	void SetPlayer();
	void AddObject(Stone* _obj)
	{
		stones.push_back(_obj);
	}

	void AddItem(ItemType item);
	void UseItemIdx(int idx);
	void Update();
	void LateUpdate();
	void EndTurnReward();
	void UseItem();
	ItemType CurrentItem();
};
