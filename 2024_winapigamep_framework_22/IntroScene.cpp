#include "pch.h"
#include "IntroScene.h"
#include "MapManager.h"
#include "SceneManager.h"
#include "UI.h"
#include "Button.h"

void IntroScene::Init()
{
	UI* btn = new Button;
	btn->SetActive(true);
	btn->SetPos({ 100,100 });
	btn->SetSize({ 100.f, 100.f });
	btn->SetText({ L"¾È³çÇÏ¼¼¿ä" });
	btn->Init();
	AddUI(btn, LAYER::UI);
}

void IntroScene::Update()
{

}

void IntroScene::Render(HDC _hdc)
{
	GET_SINGLE(MapManager)->RenderMing(_hdc);
}
