#pragma once
#include "pch.h"
#include "GamePlayManager.h"
#include "InputManager.h"


void GamePlayManager::TurnEnd()
{
	IsBlackTurn = !IsBlackTurn;

}

void GamePlayManager::Update()
{
	gamePlayers[0].Update();
	gamePlayers[1].Update();

	gamePlayers[IsBlackTurn ? 0 : 1].LateUpdate();
}

void GamePlayManager::Win(bool isBlack)
{

}
