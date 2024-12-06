
#include "pch.h"
#include "GamePlayManager.h"
#include "InputManager.h"


void GamePlayManager::Update()
{
	gamePlayers[IsBlackTurn ? 0 : 1].Update();

	gamePlayers[0].LateUpdate();
	gamePlayers[1].LateUpdate();

	if (::GET_KEYDOWN(KEY_TYPE::ENTER))
	{
		GET_SINGLE(GamePlayManager)->TurnEnd();
	}
}

void GamePlayManager::Win(bool isBlack)
{

}
