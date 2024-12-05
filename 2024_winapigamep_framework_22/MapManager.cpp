#include "pch.h"
#include "MapManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include <chrono> // 시간 측정을 위한 라이브러리

void MapManager::Render(HDC _hdc)
{

}

void MapManager::RenderMing(HDC _hdc)
{
    static auto lastTime = std::chrono::steady_clock::now(); // 이전 난수 생성 시간 저장
    static int x = 0; // 초기 x 난수 값
    static int y = 0; // 초기 y 난수 값

    // 10초 경과 시 x와 y 갱신
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = currentTime - lastTime;

    if (elapsedTime.count() >= 0.1f && isLoadMap) // 10초 이상 경과했는지 확인
    {
        x++;
        y = 10;
        if (x >= mapW)
        {
            isLoadMap = false;
            canStart = true;
            //GET_SINGLE(SceneManager)->LoadScene(L"TitleScene");
        }
        lastTime = currentTime; // 시간 갱신
    }

    if (canStart)
    {
        if (GET_KEY(KEY_TYPE::SPACE))
        {
            GET_SINGLE(SceneManager)->LoadScene(L"TitleScene");
        }
    }

    int n = 40; // 크기
    int m = 10; // 간격

    // mapArr 갱신
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            mapArr[i][j] = 1;
        }
    }

    // 그리기
    for (int i = 0; i < mapW; i++)
    {
        for (int j = 0; j < mapH; j++)
        {
            int r = 255;

            HBRUSH brush;
            if (mapArr[i][j] == 1 && isLoadMap)
            {
                brush = CreateSolidBrush(RGB(rand() % r, rand() % r, rand() % r));
            }
            else if (isLoadMap)
            {
                brush = CreateSolidBrush(RGB(0, 0, 0));
            }
            else
            {
                brush = CreateSolidBrush(RGB(255, 255, 255));
            }
            HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

            Rectangle(_hdc, ((n * i) + i * m) + 100, ((n * j) + j * m) + 100, ((n * i) + i * m + 50) + 100, ((n * j) + j * m + 50) + 100);
            SelectObject(_hdc, oldbrush);

            DeleteObject(oldbrush);
            DeleteObject(brush);
        }
    }

    // mapArr 초기화
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            mapArr[i][j] = 0;
        }
    }
}
