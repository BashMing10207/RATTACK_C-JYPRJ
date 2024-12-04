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
	Trigger* pProj = new Trigger;
	Vec2 vPos = GetPos();
	vPos.y -= GetSize().y / 2.f;
	pProj->SetPos(vPos);
	//GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);
}

void NewPorjectile::StayCollision(Collider* _other)
{
	GetComponent<RigidBody>()->StayCollision(_other);
}

void NewPorjectile::ExitCollision(Collider* _other)
{

}

