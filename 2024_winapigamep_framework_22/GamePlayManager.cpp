#pragma once
#include "pch.h"
#include "GamePlayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "BackGroundObject.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Core.h"

//void GamePlayManager::TurnEnd()


void GamePlayManager::Update()
{
	if (isStart)
	{
		gamePlayers[0]->Update();
		gamePlayers[1]->Update();

		gamePlayers[IsBlackTurn ? 0 : 1]->LateUpdate();

		if (::GET_KEYDOWN(KEY_TYPE::SPACE))
		{

			TurnEnd();
		}
	}
	if (isrestart)
	{
		if (::GET_KEYDOWN(KEY_TYPE::ENTER))
		{
			isrestart = false;
			gamePlayers[0]->items.clear();
			gamePlayers[1]->items.clear();
			GET_SINGLE(SceneManager)->LoadScene(L"IntroScene");
		}
	}

	if (::GET_KEYDOWN(KEY_TYPE::TAB))
	{
		GET_SINGLE(Core)->isPostProcess = (GET_SINGLE(Core)->isPostProcess + 1) % 4;
	}
}

void GamePlayManager::Win(bool isBlack)
{
	GET_SINGLE(ResourceManager)->LoadSound(L"Ace", L"Sound\\5Kill.mp3", false);
	GET_SINGLE(ResourceManager)->Play(L"Ace");

	Object* pObj4;

	if (isBlack)
		pObj4 = new BackGroundObject(L"Texture\\BlackWin.bmp", false);
	else
		pObj4 = new BackGroundObject(L"Texture\\WhiteWin.bmp", false);

	pObj4->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pObj4, LAYER::UI);

	isStart = false;
	isrestart = true;
	gamePlayers[0]->deadStonecnt = 0;
	gamePlayers[1]->deadStonecnt = 0;

}

void GamePlayManager::TurnEnd()
{
	IsBlackTurn = !IsBlackTurn;
	CurrentGamePlayer()->EndTurnReward();
}