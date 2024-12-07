#include "pch.h"
#include "BlackHole.h"
#include "Collider.h"
#include"TimeManager.h"
#include"EventManager.h"
#include"ResourceManager.h"

void BlackHole::Init()
{
	GetComponent<Collider>()->bounce = -1.01f;
	existTime = 4;

	GET_SINGLE(ResourceManager)->LoadSound(L"flush", L"Sound\\toiletflushing.mp3", false);
	GET_SINGLE(ResourceManager)->Play(L"flush");
}
void BlackHole::Update()
{
	existTime -= fDT;
	if (existTime <= 0)
	{
		if (!GetIsDead())
		{
			GET_SINGLE(EventManager)->DeleteObject(this);
		}
	}

}

void BlackHole::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

	//HPEN brush2 = CreatePen(PS_SOLID, isBlack ? 4:2, isBlack? RGB(80, 200, 255): RGB(255,150,0));
	//HPEN oldbrush2 = (HPEN)SelectObject(_hdc, brush2);
	HPEN brush2 = CreatePen(PS_DASHDOTDOT, 5, RGB(10, 5, 15));
	HPEN oldbrush2 = (HPEN)SelectObject(_hdc, brush2);

	ELLIPSE_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

	DeleteObject(brush2);
	SelectObject(_hdc, oldbrush2);


	DeleteObject(brush);
	SelectObject(_hdc, oldbrush);
}
