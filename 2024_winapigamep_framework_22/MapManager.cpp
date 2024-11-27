#include "pch.h"
#include "MapManager.h"

void MapManager::Render(HDC _hdc)
{
	int n = 40; //50
	int m = 10; //10

	int x, y;
	x = rand() % 10;
	y = rand() % 10;

	for (int i = 0; i < mapW; i++)
	{
		for (int j = 0; j < mapH; j++)
		{
			int r = 255; //arr[i][j];

			HBRUSH brush;

			if (i == x && j == y)
			{
				brush = CreateSolidBrush(RGB(rand() % r, rand() % r, rand() % r));
			}
			else
			{
				brush = CreateSolidBrush(RGB(0, 0, 0));
			}
			HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

			
			Rectangle(_hdc, ((n * i) + i * m) + 100, ((n * j) + j * m) + 100, ((n * i) + i * m + 50) + 100, ((n * j) + j * m + 50) + 100);
			SelectObject(_hdc, oldbrush); 

			DeleteObject(oldbrush);
			DeleteObject(brush);

			//PEN_TYPE ePewn = PEN_TYPE::
			
			//Rectangle(_hdc, 10, 10, 500, 500);
		}
	}
}
