#pragma once

class CameraShake
{
	DECLARE_SINGLE(CameraShake);
public:
	void Update();
	void AddTime(float time);
	void SetTIME(float time);
	void SetPower(int power);
	void AddPower(int power);
	void Shake();
	// todo..
	float shakeTime=0;
	int shakePower=25;
private:

public:
	void Init();
};

