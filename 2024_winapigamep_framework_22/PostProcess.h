#pragma once
#include "pch.h"
class PostProcess
{
	
};

void PostProcess(HDC hdc);

void Bloom(HDC hdc, int blurSize,int threshold,float intersity,float lerp,int threadnum);

void Blur(HDC hdc,int blurSize);

void LagacyPostProcsess(HDC hdc);