#pragma once
#include"GamePlayer.h"

class GamePlayManager
{
	DECLARE_SINGLE(GamePlayManager);

public:
	
	bool IsBlackTurn;

	GamePlayer gamePlayers[2] = {GamePlayer(true), GamePlayer(false)};

	void TurnEnd() {IsBlackTurn = !IsBlackTurn;}

	GamePlayer CurrentGamePlayer() {return gamePlayers[IsBlackTurn ? 0 : 1];}

	void LateUpdate();

	void Win(bool isBlack);

};

