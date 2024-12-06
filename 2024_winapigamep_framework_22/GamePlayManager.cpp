#pragma once
#include "pch.h"
#include "GamePlayManager.h"
#include "InputManager.h"


//void GamePlayManager::TurnEnd()


void GamePlayManager::Update()
{
	gamePlayers[0]->Update();
	gamePlayers[1]->Update();

	gamePlayers[IsBlackTurn ? 0 : 1]->LateUpdate();

	if (::GET_KEYDOWN(KEY_TYPE::ENTER))
	{
		
		TurnEnd();
	}
}

void GamePlayManager::Win(bool isBlack)
{

}

void GamePlayManager::TurnEnd()
{
	CurrentGamePlayer()->EndTurnReward();
	IsBlackTurn = !IsBlackTurn;
}