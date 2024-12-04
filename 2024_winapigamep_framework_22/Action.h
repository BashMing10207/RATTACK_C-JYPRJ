#pragma once
#include "pch.h"
template<typename T, typename... Agrs>
class Action
{
public:
	void Invoke(float _delay = 0.f)
	{
		float dt = g_Engine->GetTimer()->GetDT();
		m_delaytime += dt;
		if (m_delaytime >= _delay)
		{
			for (auto& eve : m_vecEvents)
			{
				if (eve)
				{
					eve();
				}
			}
			m_delaytime = 0.f;
		}
	}
	void RegisterEvent(std::function<void(Agrs...)> _func)
	{
		if (_func != nullptr)
			m_vecEvents.push_back(_func);
	}
	void RemoveEvent(std::function<void(Agrs...)> _func)
	{
		auto iter =
			std::find(m_vecEvents.begin(), m_vecEvents.end(), _func);
		if (iter != m_vecEvents.end())
			m_vecEvents.erase(iter);
	}
private:
	float m_delaytime = 0.f;
	vector<std::function<void(Agrs...)>> m_vecEvents;
};