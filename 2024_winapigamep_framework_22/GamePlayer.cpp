#include"pch.h"
#include "GamePlayer.h"
#include"Stone.h"
#include"LineComponent.h"

GamePlayer::GamePlayer(bool isNigger)
{
	this->isNigger = isNigger;
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

void GamePlayer::LataUpdate()
{
	for (int i = 0; i < stones.size(); i++)
	{
		stones[i].GetComponent<LineComponent>()->LateUpdate(); // �ϴ� ��� ���� ��ȣ�ۿ��� ������Ʈ ��Ű��.
	}

}

