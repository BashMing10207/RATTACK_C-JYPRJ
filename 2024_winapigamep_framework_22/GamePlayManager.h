#pragma once
#include"GamePlayer.h"

class GamePlayManager
{
	DECLARE_SINGLE(GamePlayManager);

public:
	
	bool isStart = false, isrestart=false;

	bool IsBlackTurn = true;

	vector<GamePlayer*> gamePlayers{new GamePlayer(true), new GamePlayer(false)};


	GamePlayer* CurrentGamePlayer() {return gamePlayers[IsBlackTurn ? 0 : 1];}

	void Update();

	void Win(bool isBlack);

	void TurnEnd();

	bool isEditing = false;
};

