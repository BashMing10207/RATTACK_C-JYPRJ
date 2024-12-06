#pragma once
#include "pch.h"
#include "GamePlayManager.h"
#include "InputManager.h"


void GamePlayManager::Update()
{
	gamePlayers[0].Update();
	gamePlayers[1].Update();

	if (::GET_KEYDOWN(KEY_TYPE::ENTER))
	{
		GET_SINGLE(GamePlayManager)->TurnEnd();
	}
	gamePlayers[IsBlackTurn ? 0 : 1].LateUpdate();
}

void GamePlayManager::Win(bool isBlack)
{

}
