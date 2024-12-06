#include "pch.h"
#include "GameScene.h"
#include "Enemy.h"
#include"BackGroundObject.h"
#include"Stone.h"
#include"Collider.h"
#include "GamePlayManager.h"
#include "Panel.h"
#include "Button.h"
void GameScene::Init()
{

	for(int i = 0; i < 5; i++)
	{
		Button* panel = new Button;
		panel->SetActive(true);
		//panel->SetHasPanel(true);
		panel->SetPos({ 465 + i * 150.f, SCREEN_HEIGHT - 100.f });
		panel->SetSize({ 100.f, 150.f });
		panel->Init();
		AddUI(panel, LAYER::UI);
	}

	/*for (size_t i = 0; i < 100; i++)
	{
		Object* obj = new Enemy;
		obj->SetPos({ (float)(rand() % SCREEN_WIDTH),
				(float)(rand() % SCREEN_HEIGHT)});
		obj->SetSize({100, 100});
		AddObject(obj, LAYER::ENEMY);

	}*/

	Object* obj = new BackGroundObject(L"Texture\\Map.bmp",false);
	obj->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2-80 });
	AddObject(obj, LAYER::BACKGROUND);

	for (int i = 0; i < 5; i++)
	{
		//Object* stone = new Stone;
		
			Stone* pObj4 = new Stone(true);
			pObj4->SetPos({ 320.f,60.f + 65*i });
			pObj4->SetSize({ 50.f,50.f });
			pObj4->SetName(L"Stone");
			pObj4->Init();
			pObj4->GetComponent<Collider>()->mass = 20;
			AddObject(pObj4, LAYER::PLAYER);
			GET_SINGLE(GamePlayManager)->gamePlayers[0].stones.push_back(pObj4);
		

		//Object* stone2 = new Stone;
		
			Stone* pObj2 = new Stone(false);
			pObj2->SetPos({ 1100.f,60.f + 65 * i });
			pObj2->SetSize({ 50.f,50.f });
			pObj2->SetName(L"Stone");
			pObj2->Init();
			pObj2->GetComponent<Collider>()->mass = 20;
			AddObject(pObj2, LAYER::PLAYER);
			GET_SINGLE(GamePlayManager)->gamePlayers[1].stones.push_back(pObj2);
	}
}

void GameScene::Update()
{
}
