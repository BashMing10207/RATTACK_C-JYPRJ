
#include "pch.h"
#include "GamePlayManager.h"


void GamePlayManager::Update()
{
	gamePlayers[IsBlackTurn ? 0 : 1].Update();
}

void GamePlayManager::Win(bool isBlack)
{

}
