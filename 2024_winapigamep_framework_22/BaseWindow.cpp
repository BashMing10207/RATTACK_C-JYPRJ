#pragma once
#include "pch.h"
#include "BaseWindow.h"
#include "Resource.h"
#include "Core.h"
#include <thread>
#include <atomic>
#include <condition_variable>
#include <chrono>

// ���� ����
std::atomic<bool> isPlaying(true);
std::mutex renderMutex;
std::condition_variable renderCV;

BaseWindow::BaseWindow()
	: m_hWnd(nullptr)
	, m_hInst(nullptr)
{
}

BaseWindow::~BaseWindow()
{
}

int BaseWindow::Run(HINSTANCE _hInst, LPWSTR _lpCmdline, int _CmdShow)
{
    this->m_hInst = _hInst;
    this->MyRegisterClass();
    this->createWindow();
    this->showWindow(_CmdShow);
    this->updateWindow();
    if (!GET_SINGLE(Core)->Init(m_hWnd))
        MessageBox(m_hWnd, L"Core Init Error", L"Error", MB_OK);
    return this->MessageLoop();
}

LRESULT BaseWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    //case WM_PAINT:
    //{
    //    PAINTSTRUCT ps;
    //    HDC hdc = BeginPaint(hWnd, &ps);
    //    
    //    // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
    //    EndPaint(hWnd, &ps);
    //}
    //break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

ATOM BaseWindow::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = BaseWindow::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_MY2024WINAPIGAMEPFRAMEWORK22));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = L"2-2 Gamep";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

void BaseWindow::createWindow()
{
    int ResolutionX = GetSystemMetrics(SM_CXSCREEN);
    int ResolutionY = GetSystemMetrics(SM_CYSCREEN);

    int Winposx = 0;//ResolutionX / 2 - SCREEN_WIDTH / 2;
    int Winposy = 0;//ResolutionY / 2 - SCREEN_HEIGHT / 2;

    m_hWnd = CreateWindowW(
        L"2-2 Gamep", // ������ Ŭ���� �ĺ���
        L"�ؿ��� ������",   // ����
        WS_OVERLAPPEDWINDOW, // ������ � ��Ÿ�Ϸ� ������ΰ�
        Winposx,  // �� ��� ��ġ�� LEFT
        Winposy,             // �� ��� ��ġ�� TOP
        SCREEN_WIDTH,             // �� �ػ�X
        SCREEN_HEIGHT,             // �� �ػ�Y
        nullptr,       // �θ� ������ ��¼���� ����
        nullptr,       // �޴�������
        m_hInst,     // �� ���α׷� �ν��Ͻ� �� 
        nullptr);      // �ڽ� ������ ���õȰ� ����

    // ������ ������ ����(Ÿ��Ʋ, �޴� ������� �ʵ���)
    RECT rt = { Winposx , Winposy,
                 Winposx + SCREEN_WIDTH,
                 Winposy + SCREEN_HEIGHT };
    AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
    MoveWindow(m_hWnd, Winposx, Winposy,
        rt.right - rt.left, rt.bottom - rt.top, false);
}

void BaseWindow::showWindow(int _CmdShow)
{
    // global namespace
    ::ShowWindow(m_hWnd, _CmdShow);
}

void BaseWindow::updateWindow()
{
    ::UpdateWindow(m_hWnd); // WM_PAINT
}
using namespace std::chrono;
const milliseconds frameTime(16); // �� 60 FPS
void GameLoopv2() {
    auto lastTime = steady_clock::now();


    while (isPlaying) {
        //auto currentTime = steady_clock::now();
        //auto deltaTime = duration_cast<milliseconds>(currentTime - lastTime);

        //if (deltaTime >= frameTime) {
        //    lastTime = currentTime;

        //    // ���� ������Ʈ �� ������ ȣ��

        //}
        GET_SINGLE(Core)->GameLoop();
        // CPU ��뷮 ���� (Optional)
        std::this_thread::sleep_for(milliseconds(2));
    }
}

void Rendering() {
    while (isPlaying) {
        GET_SINGLE(Core)->GameLoop2(); // ������ �Լ� ȣ��

        //std::this_thread::sleep_for(std::chrono::milliseconds(16)); // �� 60 FPS
    }
}


//int BaseWindow::MessageLoop()
//{
//    
//
//    MSG msg;
//    memset(&msg, 0, sizeof(msg)); // 0 �ʱ�ȭ
//    while (true)
//    {
//        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
//        {
//            if (msg.message == WM_QUIT)
//                break;
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//        else
//        {
//            cout << "aa";
//            // ���� �ڵ�
//            //GET_SINGLE(Core)->GameLoop();
//            //GET_SINGLE(Core)->GameLoop2();
//            vector<std::thread> threads;
//
//            threads.push_back(std::thread(GameLoopv2));
//            threads.push_back(std::thread(Rendering));
//            //gamethread.join();
//            //std::thread renderthread(Rendering);
//            //renderthread.join();
//            for (auto& t : threads) 
//            {
//                t.join();
//            }
//
//        }
//    }
//    isPlaying = false;
//
//    //renderthread.detach();
//    GET_SINGLE(Core)->CleanUp();
//    return (int)msg.wParam;
//}
//
int BaseWindow::MessageLoop() {
    MSG msg;
    std::thread gameThread(GameLoopv2); // GameLoop ���� ������
    std::thread renderThread(Rendering); // Rendering ���� ������

    while (isPlaying) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                isPlaying = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // �޽��� ť�� ����� ���� ��� ����
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    // ������ ����
    isPlaying = false;
    if (gameThread.joinable()) gameThread.join();
    if (renderThread.joinable()) renderThread.join();

    GET_SINGLE(Core)->CleanUp();
    return static_cast<int>(msg.wParam);
}
