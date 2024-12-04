#include "pch.h"
#include "IntroScene.h"
#include "MapManager.h"
#include "SceneManager.h"

void IntroScene::Init()
{

}

void IntroScene::Update()
{

}

void IntroScene::Render(HDC _hdc)
{
	GET_SINGLE(MapManager)->RenderMing(_hdc);
}
