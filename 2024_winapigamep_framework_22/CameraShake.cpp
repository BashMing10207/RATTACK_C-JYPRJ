#include "pch.h"
#include "CameraShake.h"
#include "TimeManager.h"
#include "Core.h"

void CameraShake::Update()
{
	if (shakeTime > 0)
	{
		AddTime(-fDT);
		Shake();
	}
	else {
		GET_SINGLE(Core)->camx =0;
		GET_SINGLE(Core)->camy = 0;
	}
}

void CameraShake::Shake()
{
	GET_SINGLE(Core)->camx = rand() % shakePower;
	GET_SINGLE(Core)->camy = rand() % shakePower;
}

void CameraShake::AddTime(float time)
{
	shakeTime += time;
}
void CameraShake::SetTIME(float time)
{
	shakeTime = time;
}
void CameraShake::SetPower(int power)
{
	shakePower = power;
}
void CameraShake::AddPower(int power)
{
	shakePower += power;
}