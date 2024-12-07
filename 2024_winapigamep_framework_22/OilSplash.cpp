#include "pch.h"
#include "Collider.h"
#include "OilSplash.h"
#include "RigidBody.h"
#include "ResourceManager.h"




OilSplash::~OilSplash()
{
}

void OilSplash::Init()
{
	GET_SINGLE(ResourceManager)->LoadSound(L"Oil", L"Sound\\»ÒÂï.wav", false);
	GET_SINGLE(ResourceManager)->Play(L"Oil");
	this->GetComponent<Collider>()->mass =0.001f;
}

void OilSplash::EnterCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Stone")
	{
		_other->GetOwner()->GetComponent<RigidBody>()->friction /= 4;
	}
}

void OilSplash::StayCollision(Collider* _other)
{
}

void OilSplash::ExitCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Stone")
	{
		_other->GetOwner()->GetComponent<RigidBody>()->friction *= 4;
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
