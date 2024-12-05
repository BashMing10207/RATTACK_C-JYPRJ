#include "pch.h"
#include "MapManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include <chrono> // �ð� ������ ���� ���̺귯��

void MapManager::Render(HDC _hdc)
{

}

void MapManager::RenderMing(HDC _hdc)
{
    static auto lastTime = std::chrono::steady_clock::now(); // ���� ���� ���� �ð� ����
    static int x = 0; // �ʱ� x ���� ��
    static int y = 0; // �ʱ� y ���� ��

    // 10�� ��� �� x�� y ����
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = currentTime - lastTime;

    if (elapsedTime.count() >= 0.1f && isLoadMap) // 10�� �̻� ����ߴ��� Ȯ��
    {
        x++;
        y = 10;
        if (x >= mapW)
        {
            isLoadMap = false;
            canStart = true;
            //GET_SINGLE(SceneManager)->LoadScene(L"TitleScene");
        }
        lastTime = currentTime; // �ð� ����
    }

    if (canStart)
    {
        if (GET_KEY(KEY_TYPE::SPACE))
        {
            GET_SINGLE(SceneManager)->LoadScene(L"TitleScene");
        }
    }

    int n = 40; // ũ��
    int m = 10; // ����

    // mapArr ����
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            mapArr[i][j] = 1;
        }
    }

    // �׸���
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

    // mapArr �ʱ�ȭ
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            mapArr[i][j] = 0;
        }
    }
}
