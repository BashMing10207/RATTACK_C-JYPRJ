#pragma once
#include "Object.h"
class Texture;
class Trigger : public Object
{
public:
	Texture* m_pTex;
	float existTime = 0.2f;
	Trigger();
	~Trigger();
	void Update() override;
 	virtual void Render(HDC _hdc) override;
	void Init() override;
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
	virtual void EnterCollision(Collider* _other ) override;
	virtual void StayCollision(Collider* _other) override;
	virtual void ExitCollision(Collider* _other) override;
private:
	//float m_dir;
	float m_angle;
	Vec2 m_vDir;
};

