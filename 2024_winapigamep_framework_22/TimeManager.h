#pragma once
#include <functional>
#include <vector>

struct DelayedTask
{
    std::function<void()> func; // ������ �Լ�
    float remainingTime;        // ���� ��� �ð�
};

class TimeManager
{
    DECLARE_SINGLE(TimeManager);

public:
    void Init();
    void Update();

    void AddDelayedTask(std::function<void()> func, float delay);

    const float& GetDT() const { return m_dT; }

private:
    // Delta time
    LARGE_INTEGER m_llPrevCnt = {};
    LARGE_INTEGER m_llCurCnt = {};
    LARGE_INTEGER m_llFrequency = {};
    double         m_dT = 0.f;

    // FPS(Frame Per Second)
    UINT          m_fps = 0;
    UINT          m_framecnt = 0;
    float         m_frametime = 0.f;

    std::vector<DelayedTask> m_delayedTasks; // ���� �۾� ����Ʈ
};
