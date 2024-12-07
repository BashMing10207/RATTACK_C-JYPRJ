#include "pch.h"
#include "IntroScene.h"
#include "MapManager.h"
#include "SceneManager.h"
#include "Panel.h"
#include "Button.h"
#include "BackGroundObject.h"
#include "ResourceManager.h"

void IntroScene::Init()
{
	//{
	//	Button* btn = new Button;
	//	btn->SetActive(true);
	//	btn->SetPos({ 100,100 });
	//	btn->SetSize({ 100.f, 100.f });
	//	btn->SetText({ L"¾È³çÇÏ¼¼¿ä" });
	//	btn->Init();
	//	AddUI(btn, LAYER::UI);
	//}
	Object* obj = new BackGroundObject(L"Texture\\TITLE.bmp",true);
	obj->SetPos({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
	AddObject(obj, LAYER::BACKGROUND);

	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
	GET_SINGLE(ResourceManager)->LoadSound(L"OpenBGM", L"Sound\\Opening.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"OpenBGM");
}

void IntroScene::Update()
{
	Scene::Update();
	if (GET_SINGLE(MapManager)->canStart)
	{
		if (GET_KEY(KEY_TYPE::SPACE))
		{
			GET_SINGLE(SceneManager)->LoadScene(L"GameScene");
			//GET_SINGLE(SceneManager)->LoadScene(L"TitleScene");
		}
	}
}

void IntroScene::Render(HDC _hdc)
{
	GET_SINGLE(MapManager)->RenderMing(_hdc);

	if (GET_SINGLE(MapManager)->canStart)
	{
		Scene::Render(_hdc);
	}


	for (size_t i = 0; i < m_vecUI.size(); ++i)
	{
		if (m_vecUI[i]->GetActive() == true)
			m_vecUI[i]->Render(_hdc);
	}

}
