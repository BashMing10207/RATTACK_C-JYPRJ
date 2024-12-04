#include "pch.h"
#include "TreeSeed.h"
#include "EventManager.h"
#include "Explosion.h"
#include"SceneManager.h"
#include"Collider.h"
#include "Scene.h"
#include "OilSplash.h"
#include "CameraShake.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "TreeWood.h"


void TreeSeed::Init()
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Seed", L"Texture\\Bullet.bmp");
	GET_SINGLE(ResourceManager)->LoadSound(L"Seed", L"Sound\\SeedThrow.mp3", false);
	GET_SINGLE(ResourceManager)->Play(L"Seed");
}

void TreeSeed::Render(HDC hdc)
{
	Vec2 vPos = GetPos();

	Vec2 vSize = GetSize();

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

void TreeSeed::Summoner()
{
	GET_SINGLE(ResourceManager)->LoadSound(L"TreeSpawn", L"Sound\\TreeGrow.mp3", false);
	GET_SINGLE(ResourceManager)->Play(L"TreeSpawn");

	TreeWood* pProj = new TreeWood;
	Vec2 vPos = GetPos();
	vPos.y -= GetSize().y / 2.f;
	pProj->SetPos(vPos);
	pProj->SetSize({ 300.f,300.f });
	pProj->GetComponent<Collider>()->SetSize({ 100,100 });
	pProj->SetName(L"Tree");

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);

	GET_SINGLE(CameraShake)->SetPower(10);
	GET_SINGLE(CameraShake)->SetTIME(0.3f);

	if (!GetIsDead())
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}
