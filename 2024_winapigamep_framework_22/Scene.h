#pragma once
#include "UI.h"
//#include "Object.h"
class Object; // Ŭ���� ���漱��
class Scene
{
public:
	Scene();
	virtual ~Scene(); // ���� �Ҹ���
public:
	virtual void Init() abstract;
	virtual void Update();
	virtual void DeleteLoop();
	virtual void LateUpdate();
	virtual void Render(HDC _hdc);
	virtual void Release();

public:
	void AddObject(Object* _obj, LAYER _type)
	{
		m_vecObj[(UINT)_type].push_back(_obj);
	}
	const vector<Object*>& GetLayerObjects(LAYER _type)
	{
		return m_vecObj[(UINT)_type];
	}

	void AddUI(UI* _ui, LAYER _type)
	{
		m_vecUI.push_back(_ui);
	}

	const vector<UI*>& GetLayerUIs(LAYER _type)
	{
		return m_vecUI;
	}

private:
	//Object m_obj;
	//Object* m_pObj;
	vector<Object*> m_vecObj[(UINT)LAYER::END];
	vector<UI*> m_vecUI;
};

