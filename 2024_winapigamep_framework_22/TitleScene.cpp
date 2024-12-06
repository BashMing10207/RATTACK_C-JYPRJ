#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "Player.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Stone.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "ResourceManager.h"
#include "UI.h"
#include "Button.h"
#include "Panel.h"
void TitleScene::Init()
{

	{
		Button* btn = new Button;
		btn->SetActive(true);
		btn->SetPos({ 100,100 });
		btn->SetSize({ 100.f, 100.f });
		btn->SetText({ L"�ȳ��ϼ���" });
		btn->Init();
		AddUI(btn, LAYER::UI);
	}

	{
		Panel* panel = new Panel;
		panel->SetActive(true);
		panel->SetPos({ 300,100 });
		panel->SetSize({ 0, 0 });
		panel->SetText({ L"�г��Դϴ�." });
		panel->Init();
		AddUI(panel, LAYER::UI);
	}
	Object* pObj = new Enemy;
	pObj->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	pObj->SetSize({ 100.f,100.f });
	pObj->SetName(L"Enemy");
	pObj->Init();
	AddObject(pObj, LAYER::STATIC);

	//Object* pObj2 = new Enemy;
	//pObj2->SetPos({(float)SCREEN_WIDTH,150.f });
	//pObj2->SetSize({ 100.f,100.f });
	//pObj2->SetName(L"Enemy");
	//AddObject(pObj2, LAYER::ENEMY);

	Object* pObj3 = new Stone(true);
	pObj3->SetPos({ (float)SCREEN_WIDTH,150.f });
	pObj3->SetSize({ 100.f,100.f });
	pObj3->SetName(L"Stone");
	pObj3->Init();
	AddObject(pObj3, LAYER::PLAYER);

	Stone* pObj4 = new Stone(false);
	pObj4->SetPos({ 0,150.f });
	pObj4->SetSize({ 100.f,100.f });
	pObj4->SetName(L"Stone");
	pObj4->Init();
	pObj4->GetComponent<Collider>()->mass = 30;
	AddObject(pObj4, LAYER::PLAYER);

	//Object* pPlayer6 = new Player;
	//pPlayer6->SetPos({ SCREEN_WIDTH / 2.f,500.f });
	//pPlayer6->SetSize({ 100.f,100.f });
	//pPlayer6->Init();
	//AddObject(pPlayer6, LAYER::PLAYER);

	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::STATIC, LAYER::STATIC);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::PLAYER);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::PROJECTILE);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::OBSTACLE);
	/*GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"BGM");*/

}

void TitleScene::Update()
{
	Scene::Update();
	if (GET_KEYDOWN(KEY_TYPE::ENTER))
		GET_SINGLE(SceneManager)->LoadScene(L"GameScene");
}
