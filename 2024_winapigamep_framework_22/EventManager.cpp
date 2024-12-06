#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Object.h"
#include "Scene.h"

void EventManager::Init()
{
	isRenderFinished = false;
}

void EventManager::Update()
{
	// 이전 프레임에서 등록해둔 
	//if (isRenderFinished)
	//{
	//
	//	for (Object* obj : m_vecDead)
	//	{
	//		if (obj != nullptr)
	//			delete obj;
	//	}
	//	m_vecDead.clear();

	//}

	//for (auto& eve : m_vecEvent)
	//	Excute(eve);
	//m_vecEvent.clear();
}

void EventManager::DeleteObject(Object* _pObj) // 짜피 비동기로 렌더링 돌려서 꼬임. 버그 줄이려면 어거지로 한프레임에 다 지우는 게 이득.
{
	tEvent eve = {};
	eve.eveType = EVENT_TYPE::DELETE_OBJECT;
	eve.obj = _pObj;

	if (std::find(m_vecEvent.begin(), m_vecEvent.end(), eve) == m_vecEvent.end())
	{
		//m_vecEvent.push_back(eve);
		Excute(eve);
	}
}


void EventManager::Excute(const tEvent& _eve)
{
	switch (_eve.eveType)
	{
	case EVENT_TYPE::DELETE_OBJECT:
	{
		Object* pDeadObj = _eve.obj;
		pDeadObj->SetDead();
		//m_vecDead.push_back(pDeadObj);
	}
	break;
	case EVENT_TYPE::CREATE_OBJECT:
		break;
	case EVENT_TYPE::SCENE_CHANGE:
		break;
	}
}
