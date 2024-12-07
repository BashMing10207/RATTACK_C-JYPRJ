#include "pch.h"
#include "OilGranade.h"
#include "OilSplash.h"
#include "Explosion.h"
#include "SceneManager.h"
#include "Collider.h"
#include "Scene.h"
#include "EventManager.h"
#include"ResourceManager.h"

OilGranade::OilGranade()
{
	GET_SINGLE(ResourceManager)->LoadSound(L"Oil", L"Sound\\MCBow.mp3", false);
	GET_SINGLE(ResourceManager)->Play(L"Oil");
}

OilGranade::~OilGranade()
{
}

void OilGranade::Render(HDC hdc)
{
	Vec2 vPos = GetPos();

	Vec2 vSize = GetSize();

	//HBRUSH brush = CreateSolidBrush(RGB(255, 1, 1));
	//HPEN hpen = CreatePen(PS_DOT, 10, RGB(220, 220, 5));
	//SelectObject(hdc, hpen);
	//HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

	ELLIPSE_RENDER(hdc, vPos.x, vPos.y
		, vSize.x, vSize.y);

	//DeleteObject(brush);
	//DeleteObject(hpen);
	//SelectObject(hdc, oldbrush);
}

void OilGranade::Summoner()
{
	OilSplash* pProj = new OilSplash;
	Vec2 vPos = GetPos();
	vPos.y -= GetSize().y / 2.f;
	pProj->SetPos(vPos);
	pProj->SetSize({ 300.f,300.f });
	pProj->GetComponent<Collider>()->SetSize({ 300,300 });
	pProj->SetName(L"OilSplash");

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::OBSTACLE);

	if (!GetIsDead())
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}
