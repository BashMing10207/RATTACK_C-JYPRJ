#include "pch.h"
#include "Stone.h"
#include "Collider.h"
#include "RigidBody.h"
#include "InputManager.h"
#include "Projectile.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GamePlayManager.h"
#include "EventManager.h"

#include "LineComponent.h"
//Stone::Stone()
//{
//	this->AddComponent<LineComponent>();
//	this->AddComponent<RigidBody>();
//	this->AddComponent<Collider>();
//	m_hp = 10;
//	Init();
//}
Stone::Stone(bool isBlack)
{
	this->m_hp = 100;
	this->AddComponent<LineComponent>();
	this->AddComponent<RigidBody>();
	this->AddComponent<Collider>();
	this->isBlack = isBlack;
	Init();
}
Stone::~Stone()
{

}

void Stone::Init()
{
	this->GetComponent<Collider>()->SetSize(GetSize());
}
void Stone::Update()
{
	//if (GET_KEYDOWN(KEY_TYPE::A))
	//	GetComponent<RigidBody>()->AddForce(Vec2(-speed,0));
	//if (GET_KEYDOWN(KEY_TYPE::D))
	//	GetComponent<RigidBody>()->AddForce(Vec2(speed, 0));
}



void Stone::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	HBRUSH brush = CreateSolidBrush(isBlack ? RGB(25, 25, 25) : RGB(120, 120, 120));
	HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

	ELLIPSE_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

	DeleteObject(brush);
	SelectObject(_hdc, oldbrush);


	ComponentRender(_hdc);
}

void Stone::CreateProjectile()
{
	Projectile* pProj = new Projectile;
	Vec2 vPos = GetPos();
	vPos.y -= GetSize().y / 2.f;
	pProj->SetPos(vPos);
	pProj->SetSize({ 30.f,30.f });
	// �� -> ����: PI / 180
	//pProj->SetAngle(PI / 4 * 7.f); // 1
	//static float angle = 0.f;
	//pProj->SetAngle(angle * PI / 180); // 2
	//angle += 10.f;
	pProj->SetDir({ 0.f, -1.f });
	pProj->SetName(L"PlayerBullet");
	//Vec2 a = { 10.f, 10.f };
	//Vec2 b = { 0.f, 0.f };
	//Vec2 c = a / b;

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::STATIC);
}

void Stone::Die()
{
	GET_SINGLE(EventManager)->DeleteObject(this);
}

void Stone::EnterCollision(Collider* _other)
{
}

void Stone::StayCollision(Collider* _other)
{
	GetComponent<RigidBody>()->StayCollision(_other);
}

void Stone::ExitCollision(Collider* _other)
{

}
