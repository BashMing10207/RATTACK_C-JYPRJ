#include "pch.h"
#include "Granade.h"
#include "EventManager.h"
#include "Explosion.h"
#include"SceneManager.h"
#include"Collider.h"
#include "Scene.h"
#include "OilSplash.h"
#include "CameraShake.h"
#include "Texture.h"
#include "ResourceManager.h"

void Granade::Init()
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Granade", L"Texture\\ShinGranade.bmp");
	GET_SINGLE(ResourceManager)->LoadSound(L"GrenadeThrow", L"Sound\\GrenadeOut.wav", false);
	GET_SINGLE(ResourceManager)->Play(L"GrenadeThrow");
}
void Granade::Render(HDC hdc)
{
	Vec2 vPos = GetPos();

	Vec2 vSize = GetSize();

	//HBRUSH brush = CreateSolidBrush(RGB(255, 1, 1));
	//HPEN hpen = CreatePen(PS_DOT, 10, RGB(220, 220, 5));
	//SelectObject(hdc, hpen);
	//HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

	//ELLIPSE_RENDER(hdc, vPos.x, vPos.y
	//	, vSize.x, vSize.y);

	//DeleteObject(brush);
	//DeleteObject(hpen);
	//SelectObject(hdc, oldbrush);

	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();
	::TransparentBlt(hdc
		, (int)(vPos.x - width / 2)
		, (int)(vPos.y - height / 2)
		, width, height,
		m_pTex->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));

	ComponentRender(hdc);
}
void Granade::Summoner()
{
	GET_SINGLE(ResourceManager)->LoadSound(L"GrenadeBoom", L"Sound\\TntBoom.wav", false);
	GET_SINGLE(ResourceManager)->Play(L"GrenadeBoom");

	Explosion *pProj = new Explosion;
	Vec2 vPos = GetPos();
	vPos.y -= GetSize().y / 2.f;
	pProj->SetPos(vPos);
	pProj->SetSize({ 300.f,300.f });
	pProj->GetComponent<Collider>()->SetSize({ 300,300 });
	pProj->SetName(L"Explostion");

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);

	GET_SINGLE(CameraShake)->SetPower(10);
	GET_SINGLE(CameraShake)->SetTIME(0.3f);

	if (!GetIsDead())
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}
