#include "pch.h"
#include "GameScene.h"
#include "Enemy.h"
#include"BackGroundObject.h"
#include"Stone.h"
#include"Collider.h"
#include "GamePlayManager.h"
#include "Item.h"
#include"CollisionManager.h"
#include "Panel.h"
#include "Button.h"

void GameScene::Init()
{
	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
	GET_SINGLE(ResourceManager)->LoadSound(L"MainBGM", L"Sound\\MainThema.mp3", true);
	GET_SINGLE(ResourceManager)->Play(L"MainBGM");

	/*for (size_t i = 0; i < 100; i++)
	{
		Object* obj = new Enemy;
		obj->SetPos({ (float)(rand() % SCREEN_WIDTH),
				(float)(rand() % SCREEN_HEIGHT)});
		obj->SetSize({100, 100});
		AddObject(obj, LAYER::ENEMY);

	}*/

	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::PLAYER);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::PROJECTILE);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::OBSTACLE);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::OBSTACLE);

	Object* obj = new BackGroundObject(L"Texture\\Map.bmp", false);
	obj->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 - 80 });
	AddObject(obj, LAYER::BACKGROUND);

	for (int i = 0; i < 5; i++)
	{
		//Object* stone = new Stone;

		Stone* pObj4 = new Stone(true);
		pObj4->SetPos({ 320.f,60.f + 65 * i });
		pObj4->SetSize({ 50.f,50.f });
		pObj4->SetName(L"Stone");
		pObj4->Init();
		pObj4->GetComponent<Collider>()->mass = 20;
		AddObject(pObj4, LAYER::PLAYER);
		GET_SINGLE(GamePlayManager)->gamePlayers[0]->stones.push_back(pObj4);


		//Object* stone2 = new Stone;

		Stone* pObj2 = new Stone(false);
		pObj2->SetPos({ 1100.f,60.f + 65 * i });
		pObj2->SetSize({ 50.f,50.f });
		pObj2->SetName(L"Stone");
		pObj2->Init();
		pObj2->GetComponent<Collider>()->mass = 20;
		AddObject(pObj2, LAYER::PLAYER);
		GET_SINGLE(GamePlayManager)->gamePlayers[1]->stones.push_back(pObj2);
	}

	GET_SINGLE(GamePlayManager)->IsBlackTurn = true;
	GET_SINGLE(GamePlayManager)->gamePlayers[0]->AddItem(ItemType::Move);
	//GET_SINGLE(GamePlayManager)->gamePlayers[1]->AddItem(ItemType::Move);

	for (int i = 0; i < 5; i++)
	{
		Panel* panel = new Panel;
		panel->SetActive(true);
		panel->SetHasPanel(true);
		panel->SetPos({ 465 + i * 150.f, SCREEN_HEIGHT - 80.f });
		panel->SetSize({ 100.f, 150.f });
		panel->Init();
		panel->SetIndex(i);
		AddUI(panel, LAYER::UI);
	}

	GET_SINGLE(GamePlayManager)->isStart = true;
}

void GameScene::Update()
{
	Scene::Update();
	Scene::LateUpdate();

	for (int i = 0; i < 5; i++)
	{
		GamePlayer* gamePlayer = GET_SINGLE(GamePlayManager)->CurrentGamePlayer();
		if (gamePlayer->items.size() >= i + 1)
		{
			ItemType item = gamePlayer->items[i];
			Panel* panel = dynamic_cast<Panel*>(m_vecUI[i]);
			panel->SetTexture(ItemTypeToWString(item), ItemTypeToPath(item));
		}
	}
}
wstring GameScene::ItemTypeToWString(ItemType _item)
{
	switch (_item)
	{
	case Move:
		return L"MoveItem";
		break;
	case Grenade:
		return L"GrenadeItem";
		break;
	case OilGrenade:
		return L"OilGrenadeItem";
		break;
	case ThrowMagnet:
		return L"ThrowMagnetItem";
		break;
	case Magnet:
		return L"MagnetItem";
		break;
	case Boom:
		return L"BoomItem";
		break;
	case Potal:
		return L"PotalItem";
		break;
	case Seed:
		return L"SeedItem";
		break;
	case Gun:
		return L"GunItem";
		break;
	case Joo:
		return L"JooItem";
		break;
	case End:
		break;
	default:
		break;
	}
	return L"";
}

wstring GameScene::ItemTypeToPath(ItemType _item)
{
	switch (_item)
	{
	case Move:
		return L"Texture//MoveSkill.bmp";
		break;
	case Grenade:
		return L"Texture//Grenade_item.bmp";
		break;
	case OilGrenade:
		return L"Texture//OIlShoke.bmp";
		break;
	case ThrowMagnet:
		return L"Texture//ThrowingMagent_itme.bmp";
		break;
	case Magnet:
		return L"Texture//MagnetItem.bmp";
		break;
	case Boom:
		return L"Texture//BoomItem.bmp";
		break;
	case Potal:
		return L"Texture//TeleportItem.bmp";
		break;
	case Seed:
		return L"Texture//SeedItem.bmp";
		break;
	case Gun:
		return L"Texture//gunItem.bmp";
		break;
	case Joo:
		return L"Texture//FreezeChiken.bmp";
		break;
	default:
		break;
	}
	return L"Texture//LemonTree.bmp";
}