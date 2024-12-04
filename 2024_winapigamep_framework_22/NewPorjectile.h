#pragma once
#include "Object.h"
class Texture;
class NewPorjectile	: public Object
{
public:
	NewPorjectile();
	~NewPorjectile();
	virtual void Update() override;
	virtual void Render(HDC _hdc) override;
	virtual void Init() override;
	virtual void Summoner();
	float lifetime = 3;
public:
	void SetAngle(float _f)
	{
		m_angle = _f;
	}
	void SetDir(Vec2 _dir)
	{
		m_vDir = _dir;
		m_vDir.Normalize();
	}
public:
	virtual void EnterCollision(Collider* _other) override;
	virtual void StayCollision(Collider* _other) override;
	virtual void ExitCollision(Collider* _other) override;
public:
	//float m_dir;
	float m_angle;
	Vec2 m_vDir;
	Texture* m_pTex;
};