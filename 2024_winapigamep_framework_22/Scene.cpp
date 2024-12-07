#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "CollisionManager.h"
#include "PostProcess.h"
#include "SceneManager.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	Release();
}

void Scene::Update()
{
	//for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	//{
	//	for (size_t j = 0; j < m_vecObj[i].size();)
	//	{
	//		if (!m_vecObj[i][j]->GetIsDead())
	//			m_vecObj[i][j++]->Update();
	//		else
	//			m_vecObj[i].erase(m_vecObj[i].begin() + j);
	//	}
	//}

	if (INPUT->GetKey(KEY_TYPE::ESC) == KEY_STATE::DOWN)
	{
		GET_SINGLE(SceneManager)->LoadScene(L"Setting");
	}

	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			if (!m_vecObj[i][j]->GetIsDead())
				m_vecObj[i][j]->Update();
			else
			{
				delete(m_vecObj[i][j]);
				m_vecObj[i].erase(m_vecObj[i].begin() + j);
			}

		}
	}

	for (size_t i = 0; i < m_vecUI.size(); ++i)
	{
		if (m_vecUI[i]->GetActive() == true)
			m_vecUI[i]->Update();
	}

}

void Scene::DeleteLoop()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size();)
		{
			if (m_vecObj[i][j]->GetIsDead())
				m_vecObj[i].erase(m_vecObj[i].begin() + j);
		}

	}
}

void Scene::LateUpdate()
{
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			if (!m_vecObj[i][j]->GetIsDead())
				m_vecObj[i][j]->LateUpdate();

		}
	}
}

void Scene::Render(HDC _hdc)
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size();)
		{
			if (m_vecObj[i][j] != nullptr)
				if (!m_vecObj[i][j]->GetIsDead())
					m_vecObj[i][j++]->Render(_hdc);

		}

	}

	for (size_t i = 0; i < m_vecUI.size(); ++i)
	{
		if (m_vecUI[i]->GetActive() == true)
			m_vecUI[i]->Render(_hdc);
	}
}

void Scene::Release()
{
	// 오브젝트 삭제.
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			delete m_vecObj[i][j];
		}
		m_vecObj[i].clear();
	}

	for (UINT i = 0; i < m_vecUI.size(); ++i)
	{
		delete m_vecUI[i];
	}
	m_vecUI.clear();

	GET_SINGLE(CollisionManager)->CheckReset();
}
