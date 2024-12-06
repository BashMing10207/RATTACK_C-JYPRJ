#pragma once
#include"GamePlayer.h"

class GamePlayManager
{
	DECLARE_SINGLE(GamePlayManager);

public:
	
	bool IsBlackTurn = true;

	vector<GamePlayer> gamePlayers{GamePlayer(true), GamePlayer(false)};

	void TurnEnd();

	GamePlayer CurrentGamePlayer() {return gamePlayers[IsBlackTurn ? 0 : 1];}

	void Update();

	void Win(bool isBlack);

};

