#include "pch.h"
#include "SkillExcutor.h"
#include "Object.h"
#include"RigidBody.h"
#include "Granade.h"
#include "OilGranade.h"
#include "BlackHoleGranade.h"
#include "ResourceManager.h"
#include "Explosion.h"
#include"SceneManager.h"
#include"Scene.h"
#include"CameraShake.h"

void SkillExcutor::GetAction(Item item,Vec2 direction)
{

}

void SkillExcutor::Move(Vec2 direction)
{
	GetOwner()->GetComponent<RigidBody>()->AddForce(direction * 5);
}

void SkillExcutor::Gun(Vec2 direction)
{

}

void SkillExcutor::Grenade(Vec2 direction)
{
	Granade* pProj = new Granade;
	Vec2 vPos = GetOwner()->GetPos();
	vPos.y -= GetOwner()->GetSize().y / 2.f;
	pProj->SetPos(vPos + direction.Normalize() * 10);
	pProj->SetSize({ 20.f,20.f });

	pProj->GetComponent<RigidBody>()->AddForce(direction);
	pProj->SetName(L"Granade");
	
}

void SkillExcutor::OilGrenade(Vec2 direction)
{
	OilGranade* pProj = new OilGranade;
	Vec2 vPos = GetOwner()->GetPos();
	vPos.y -= GetOwner()->GetSize().y / 2.f;
	pProj->SetPos(vPos + direction.Normalize() * 10);
	pProj->SetSize({ 20.f,20.f });

	pProj->GetComponent<RigidBody>()->AddForce(direction);
	pProj->SetName(L"Granade");

}

void SkillExcutor::ThrowMagnet(Vec2 direction)
{
	BlackHoleGranade* pProj = new BlackHoleGranade;
	Vec2 vPos = GetOwner()->GetPos();
	vPos.y -= GetOwner()->GetSize().y / 2.f;
	pProj->SetPos(vPos + direction.Normalize() * 10);
	pProj->SetSize({ 20.f,20.f });

	pProj->GetComponent<RigidBody>()->AddForce(direction);
	pProj->SetName(L"Granade");

}

void SkillExcutor::ThrowSeed(Vec2 direction)
{

}

void SkillExcutor::Magnet(Vec2 direction)
{

}

void SkillExcutor::ExplosionSkill(Vec2 direction)
{
	GET_SINGLE(ResourceManager)->LoadSound(L"GrenadeBoom", L"Sound\\TntBoom.wav", false);
	GET_SINGLE(ResourceManager)->Play(L"GrenadeBoom");

	Explosion* pProj = new Explosion;
	Vec2 vPos = GetOwner()->GetPos();
	vPos.y -= GetOwner()->GetSize().y / 2.f;
	pProj->SetPos(vPos);
	float size = min(direction.Length(),450);

	pProj->SetSize({ size,size });
	pProj->GetComponent<Collider>()->SetSize({ size,size });
	pProj->SetName(L"Explostion");

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);

	GET_SINGLE(CameraShake)->SetPower(15);
	GET_SINGLE(CameraShake)->SetTIME(0.3f);

}

void SkillExcutor::JooYoung(Vec2 direction)
{

}

void SkillExcutor::BeWater(Vec2 direction)
{

}

void SkillExcutor::Tetkkai(Vec2 direction)
{

}
