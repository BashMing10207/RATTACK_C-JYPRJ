#pragma once
#include "Object.h"
class Stone :
	public Object
{
public:
	//Stone();
	~Stone();
	Stone(bool isBlack=true);
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void Init() override;
	void CreateProjectile();
	void Die();
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
	float speed =3500;
	bool isBlack = true;
private:
	int m_hp;
};


