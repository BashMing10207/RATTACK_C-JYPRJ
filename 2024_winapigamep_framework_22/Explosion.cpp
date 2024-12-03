#include "pch.h"
#include "Explosion.h"
#include "Collider.h"
#include "TimeManager.h"
#include "EventManager.h"

void Explosion::Init()
{

	this->GetComponent<Collider>()->bounce = 0.5f;

}

void Explosion::EnterCollision(Collider* _other)
{
}

void Explosion::StayCollision(Collider* _other)
{
}

void Explosion::ExitCollision(Collider* _other)
{
}

void Explosion::Update()
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

void Explosion::Render(HDC hdc)
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
