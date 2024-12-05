
#include "pch.h"
#include "GamePlayManager.h"


void GamePlayManager::LateUpdate()
{
	gamePlayers[IsBlackTurn ? 0 : 1].LataUpdate();
}

void GamePlayManager::Win(bool isBlack)
{

}
