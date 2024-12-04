#include "pch.h"
#include "BlackHole.h"
#include "Collider.h"
#include"TimeManager.h"
#include"EventManager.h"

void BlackHole::Init()
{
	GetComponent<Collider>()->bounce = -1.01f;
	existTime = 3;
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

void BlackHole::Render(HDC hdc)
{
	Vec2 vPos = GetPos();

	Vec2 vSize = GetSize();

	//HBRUSH brush = CreateSolidBrush(RGB(255, 1, 1));
	//HBRUSH defaultbrush = (HBRUSH)SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	//HPEN defaultPen = CreatePen(PS_SOLID, 10, RGB(1, 1, 1));
	//
	//
	//HPEN hpen = CreatePen(PS_SOLID, 10, RGB(220, 220, 5));
	//SelectObject(hdc, hpen);
	//HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

	ELLIPSE_RENDER(hdc, vPos.x, vPos.y
		, vSize.x, vSize.y);

	//DeleteObject(brush);
	//DeleteObject(hpen);


	//SelectObject(hdc, defaultPen);
	//SelectObject(hdc, )
}
