#pragma once
#include "Trigger.h"
class BlackHole : public Trigger
{
public:
	virtual void EnterCollision(Collider* _other) override;
	virtual void StayCollision(Collider* _other) override;
	virtual void ExitCollision(Collider* _other) override;
	

};

