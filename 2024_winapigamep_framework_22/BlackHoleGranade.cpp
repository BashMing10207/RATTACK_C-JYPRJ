#include "pch.h"
#include "SceneManager.h"
#include "Collider.h"
#include "Scene.h"
#include "EventManager.h"
#include "BlackHoleGranade.h"
#include "BlackHole.h"
#include"ResourceManager.h"

BlackHoleGranade::BlackHoleGranade() 
{
	GET_SINGLE(ResourceManager)->LoadSound(L"mag", L"Sound\\ThrowMagnet.mp3", false);
	GET_SINGLE(ResourceManager)->Play(L"mag");
}

void BlackHoleGranade::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	HBRUSH brush = CreateSolidBrush(RGB(10, 5, 15));
	HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

	//HPEN brush2 = CreatePen(PS_SOLID, isBlack ? 4:2, isBlack? RGB(80, 200, 255): RGB(255,150,0));
	//HPEN oldbrush2 = (HPEN)SelectObject(_hdc, brush2);
	HPEN brush2 = CreatePen(PS_DASHDOTDOT, 5, RGB(0, 0, 0));
	HPEN oldbrush2 = (HPEN)SelectObject(_hdc, brush2);

	ELLIPSE_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

	DeleteObject(brush2);
	SelectObject(_hdc, oldbrush2);


	DeleteObject(brush);
	SelectObject(_hdc, oldbrush);
}

void BlackHoleGranade::Summoner()
{
	BlackHole* pProj = new BlackHole;
	Vec2 vPos = GetPos();
	vPos.y -= GetSize().y / 2.f;
	pProj->SetPos(vPos);
	pProj->SetSize({ 300.f,300.f });
	pProj->GetComponent<Collider>()->SetSize({ 300,300 });
	pProj->SetName(L"BlackHole");

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::OBSTACLE);

	if (!GetIsDead())
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}
