#include "pch.h"
#include "TimeManager.h"
#include "NewPorjectile.h"
#include "RigidBody.h"
#include "Collider.h"
#include "Trigger.h"
#include "EventManager.h"
NewPorjectile::NewPorjectile()
{
	this->AddComponent<RigidBody>();
	this->AddComponent<Collider>();
	GetComponent<RigidBody>()->friction = 1.2f;
	//GetComponent<Collider>()->bounce = 0.5f;
	GetComponent<RigidBody>()->mass = 6.f;
	this->Init();
}

NewPorjectile::~NewPorjectile()
{

}

void NewPorjectile::Update()
{
	GetComponent<RigidBody>()->AddForce(Vec2(0,gravity));

	lifetime -= fDT;
	if (lifetime <= 0)
	{
		Summoner();

		if (!GetIsDead())
		{
			GET_SINGLE(EventManager)->DeleteObject(this);
		}
	}
}

void NewPorjectile::Render(HDC _hdc)
{
	if (renderming)
	{
		Vec2 vPos = GetPos();
		Vec2 vSize = GetSize();
		HBRUSH brush = CreateSolidBrush(RGB(255, 230, 0));
		HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

		//HPEN brush2 = CreatePen(PS_SOLID, isBlack ? 4:2, isBlack? RGB(80, 200, 255): RGB(255,150,0));
		//HPEN oldbrush2 = (HPEN)SelectObject(_hdc, brush2);
		HPEN brush2 = CreatePen(PS_DASH, 2, RGB(255, 100, 0));
		HPEN oldbrush2 = (HPEN)SelectObject(_hdc, brush2);

		ELLIPSE_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

		DeleteObject(brush2);
		SelectObject(_hdc, oldbrush2);


		DeleteObject(brush);
		SelectObject(_hdc, oldbrush);
	}
}

void NewPorjectile::Init()
{
	this->GetComponent<Collider>()->SetSize(GetSize());
}

void NewPorjectile::Summoner()
{
}

void NewPorjectile::EnterCollision(Collider* _other)
{
	//Trigger* pProj = new Trigger;
	//Vec2 vPos = GetPos();
	//vPos.y -= GetSize().y / 2.f;
	//pProj->SetPos(vPos);
	//GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);
}

void NewPorjectile::StayCollision(Collider* _other)
{
	GetComponent<RigidBody>()->StayCollision(_other);
}

void NewPorjectile::ExitCollision(Collider* _other)
{

}

