#pragma once
#include "Trigger.h"
class BlackHole : public Trigger
{
public:
	BlackHole() :Trigger()
	{
		Init();
	};
	void Init();

	void Update() override;
	void Render(HDC hdc) override;
	

};

