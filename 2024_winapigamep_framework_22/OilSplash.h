#pragma once
#include "Trigger.h"
class OilSplash :
    public Trigger
{
public:
	OilSplash() :Trigger()
	{
		Init();
	};
	~OilSplash();

	void Init() override;
	virtual void EnterCollision(Collider* _other) override;
	virtual void StayCollision(Collider* _other) override;
	virtual void ExitCollision(Collider* _other) override;
	void Update() override;
	void Render(HDC hdc) override;

};

