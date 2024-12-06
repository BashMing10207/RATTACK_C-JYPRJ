#include"pch.h"
#include "GamePlayer.h"
#include"GamePlayManager.h"
#include"Stone.h"
#include"LineComponent.h"
#include "InputManager.h"

GamePlayer::GamePlayer(bool isNigger)
{
	this->isBlack = isNigger;
}

GamePlayer::~GamePlayer()
{

}

void GamePlayer::Init()
{

}

void GamePlayer::SetPlayer()
{
	selectecIndex = 0;

}

void GamePlayer::AddItem(Item item)
{
	items.push_back(item);
}

void GamePlayer::UseItemIdx(int idx)
{
	items.erase(items.begin() + idx);
}

void GamePlayer::Update()
{
	for (int i = 0; i < stones.size(); i++)
	{
		Vec2 pos = stones[i]->GetPos();

		if (!(pos.x > 167 && pos.x < 1364 && pos.y > 24 && pos.y < 612))
		{
			stones[i]->Die();
			stones.erase(stones.begin() + i);
			deadStonecnt++;

			if (stones.size() == 0)
			{
				GET_SINGLE(GamePlayManager)->Win(isBlack);
			}
		}
	}



}

void GamePlayer::LateUpdate()
{
	for (int i = 0; i < stones.size(); i++)
	{
		stones[i]->GetComponent<LineComponent>()->LateUpdate2(); // 일단 모든 돌의 상호작용을 업데이트 시키기.
	}
}

