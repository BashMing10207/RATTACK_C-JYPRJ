#include "pch.h"
#include "Explosion.h"
#include "Collider.h"
#include "TimeManager.h"
#include "EventManager.h"

void Explosion::Init()
{

	this->GetComponent<Collider>()->bounce = 0.1f;

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
	if (existTime < 0)
	{
		if (!GetIsDead())
		{
			GET_SINGLE(EventManager)->DeleteObject(this);
		}
	}
}

void Explosion::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

	//HPEN brush2 = CreatePen(PS_SOLID, isBlack ? 4:2, isBlack? RGB(80, 200, 255): RGB(255,150,0));
	//HPEN oldbrush2 = (HPEN)SelectObject(_hdc, brush2);
	HPEN brush2 = CreatePen(PS_DASHDOTDOT, 5, RGB(255, 100, 0));
	HPEN oldbrush2 = (HPEN)SelectObject(_hdc, brush2);

	ELLIPSE_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

	DeleteObject(brush2);
	SelectObject(_hdc, oldbrush2);


	DeleteObject(brush);
	SelectObject(_hdc, oldbrush);
}
