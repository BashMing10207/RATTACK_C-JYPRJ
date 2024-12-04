#pragma once
#include"pch.h"
#include"GamePlayer.h"

class GamePlayManager
{
	DECLARE_SINGLE(GamePlayManager);

public:
	
	bool IsBlackTurn;

	GamePlayer gamePlayers[2]{GamePlayer(),GamePlayer()};

	void TurnEnd() 
	{
		IsBlackTurn = !IsBlackTurn;
	}


};

