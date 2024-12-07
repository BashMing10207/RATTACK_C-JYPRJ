#pragma once
#include "pch.h"
#include "Object.h"
#include "Stone.h"
#include "CurrentSkillRenderer.h"
#include "GamePlayManager.h"
#include "ResourceManager.h"

CurrentSkillRenderer::CurrentSkillRenderer()
{

}

CurrentSkillRenderer::~CurrentSkillRenderer()
{

}

void CurrentSkillRenderer::LateUpdate()
{

}

void CurrentSkillRenderer::Render(HDC _hdc)
{
	if (dynamic_cast<Stone*>(GetOwner())->isBlack == GET_SINGLE(GamePlayManager)->IsBlackTurn)
	{


		ItemType a = GET_SINGLE(GamePlayManager)->CurrentGamePlayer()->CurrentItem();
		if (a != ItemType::End)
		{
			switch (a)
			{
			case Move:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"MoveTx", L"Texture\\Move_HaveImg.bmp");
				break;
			case Grenade:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"GrenadeTx", L"Texture\\ShinGranade.bmp");
				break;
			case OilGrenade:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"OilGrTx", L"Texture\\Oil_HaveImg.bmp");
				break;
			case ThrowMagnet:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"TrowManTx", L"Texture\\Magnet_HaveImg.bmp");
				break;
			case Magnet:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"MGnTx", L"Texture\\MegaMagnet_HaveImg.bmp");
				break;
			case Boom:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"BoomTNTTx", L"Texture\\Tnt_HaveImg.bmp");
				break;
			case Potal:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"PortalButtonTX", L"Texture\\Teleport_HaveImg.bmp");
				break;
			case Seed:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"treeSeedItemTx", L"Texture\\Seed2.bmp");
				break;
			case Gun:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Gun_TX", L"Texture\\Gun_HaveImg2.bmp");
				break;
			case Joo:
				m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Jiwoo", L"Texture\\jiwoo.bmp");
				break;
			case End:

				break;
			default:
				break;
			}

			Vec2 vPos = GetOwner()->GetPos();

			Vec2 vSize = GetOwner()->GetSize();

			int width = m_pTex->GetWidth();
			int height = m_pTex->GetHeight();
			::TransparentBlt(_hdc
				, (int)(vPos.x - width / 2)
				, (int)(vPos.y - height / 2)
				, width, height,
				m_pTex->GetTexDC()
				, 0, 0, width, height, RGB(255, 0, 255));
		}
	
	}
}
