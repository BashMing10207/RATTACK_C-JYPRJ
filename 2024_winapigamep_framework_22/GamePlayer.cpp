#include"pch.h"
#include "GamePlayer.h"
#include"GamePlayManager.h"
#include"Stone.h"
#include"LineComponent.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "UI.h"
#include "Panel.h"
#include "GameScene.h"

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

void GamePlayer::AddItem(ItemType item)
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

			//if (stones.size() <= 0)
			if (deadStonecnt >= 5 || stones.size() <= 0)
			{
				GET_SINGLE(GamePlayManager)->Win(!isBlack);
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

void GamePlayer::EndTurnReward()
{
	AddItem((ItemType::Move));
	for (int i = 0; i < deadStonecnt; i++)
	{
		AddItem((ItemType)(rand() % 10));
	}
}

void GamePlayer::UseItem()
{		
	items.erase(items.begin() + selectecIndex);
	SetItemTexture(L"", L"");

	
}

ItemType GamePlayer::CurrentItem()
{
	if (items.size() > selectecIndex)
	{
		return items[selectecIndex];
	}
	else {
		return ItemType::End;
	}
}

void GamePlayer::SetItemTexture(wstring _name, wstring _texture)
{
	vector<UI*> ui = GET_SINGLE(SceneManager)->GetCurrentScene()->GetUIs();

	for (int i = 0; i < ui.size(); i++)
	{
		Panel* panel = dynamic_cast<Panel*>(ui[i]);
		if (panel)
		{
			panel->SetTexture(_name, _texture);
		}
	}
}

