#include "pch.h"
#include "Trigger.h"
#include "pch.h"
#include "NewPorjectile.h"
#include "RigidBody.h"
#include "Collider.h"
#include "time.h"

Trigger::Trigger()
{
	this->AddComponent<Collider>();
	SetSize(Vec2(800, 800));
	this->GetComponent<Collider>()->SetSize(GetSize());
}

Trigger::~Trigger()
{
}

void Trigger::Update()
{

}

void Trigger::Render(HDC _hdc)
{
}

void Trigger::Init()
{
}

void Trigger::EnterCollision(Collider* _other)
{
}

void Trigger::StayCollision(Collider* _other)
{
	
}

void Trigger::ExitCollision(Collider* _other)
{
}
