#include "pch.h"
#include "Collider.h"
#include "OilSplash.h"
#include "RigidBody.h"



OilSplash::OilSplash()
{
	
}

OilSplash::~OilSplash()
{
}

void OilSplash::EnterCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Stone")
	{
		_other->GetOwner()->GetComponent<RigidBody>()->friction /= 2;
	}
}

void OilSplash::StayCollision(Collider* _other)
{
}

void OilSplash::ExitCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Stone")
	{
		_other->GetOwner()->GetComponent<RigidBody>()->friction *= 2;
	}
}

void OilSplash::Update()
{

}

void OilSplash::Render(HDC hdc)
{
	Vec2 pos = GetPos();
	Vec2 size = GetSize();

	HBRUSH brush = CreateSolidBrush(RGB(130, 120, 10));
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

	ELLIPSE_RENDER(hdc, pos.x, pos.y, size.x, size.y);

	DeleteObject(brush);
	SelectObject(hdc, oldbrush);

}
