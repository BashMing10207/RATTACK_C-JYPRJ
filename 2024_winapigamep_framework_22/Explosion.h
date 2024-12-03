#pragma once
#include "Trigger.h"
class Explosion : public Trigger
{
public:
	Explosion() :Trigger()
	{
		Init();
	};
	void Init();
	virtual void EnterCollision(Collider* _other) override;
	virtual void StayCollision(Collider* _other) override;
	virtual void ExitCollision(Collider* _other) override;
	void Update() override;
	void Render(HDC hdc) override;
};

