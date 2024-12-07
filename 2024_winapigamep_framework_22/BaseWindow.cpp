#pragma once
#include "pch.h"
#include "BaseWindow.h"
#include "Resource.h"
#include "Core.h"
#include <thread>
#include <atomic>
#include <condition_variable>
#include <chrono>
#include"ResourceManager.h";

// 전역 변수
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
    //    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
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
        L"2-2 Gamep", // 윈도우 클래스 식별자
        L"RATTACK_WAR",   // 제목
        WS_OVERLAPPEDWINDOW, // 윈도우 어떤 스타일로 만들것인가
        Winposx,  // ★ 띄울 위치의 LEFT
        Winposy,             // ★ 띄울 위치의 TOP
        SCREEN_WIDTH,             // ★ 해상도X
        SCREEN_HEIGHT,             // ★ 해상도Y
        nullptr,       // 부모 윈도우 어쩌구라서 무시
        nullptr,       // 메뉴쓸꺼냐
        m_hInst,     // 내 프로그램 인스턴스 값 
        nullptr);      // 자식 윈도우 관련된것 무시

    // 윈도우 사이즈 조정(타이틀, 메뉴 계싼하지 않도록)
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
void GameLoopv2() {

    while (isPlaying) {

        GET_SINGLE(Core)->GameLoop();
    }
}

void Rendering() {
    while (isPlaying) {
        GET_SINGLE(Core)->GameLoop2();
    }
}
//int BaseWindow::MessageLoop()
//{
//    
//
//    MSG msg;
//    memset(&msg, 0, sizeof(msg)); // 0 초기화
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
//            // 메인 코드
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
void AllTextureLoad()
{
GET_SINGLE(ResourceManager)->TextureLoad(L"MoveTx", L"Texture\\Move_HaveImg.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"GrenadeTx", L"Texture\\ShinGranade.bmp");
 GET_SINGLE(ResourceManager)->TextureLoad(L"OilGrTx", L"Texture\\Oil_HaveImg.bmp");
 GET_SINGLE(ResourceManager)->TextureLoad(L"TrowManTx", L"Texture\\Magnet_HaveImg.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"MGnTx", L"Texture\\MegaMagnet_HaveImg.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"BoomTNTTx", L"Texture\\Tnt_HaveImg.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"PortalButtonTX", L"Texture\\Teleport_HaveImg.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"treeSeedItemTx", L"Texture\\Seed2.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"Gun_TX", L"Texture\\Gun_HaveImg2.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"bullet2", L"Texture\\Bullet.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"Seed12", L"Texture\\Seed2.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"Tree2", L"Texture\\Tree2.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"Granade", L"Texture\\ShinGranade.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"Texture\\Map.bmp", L"Texture\\Map.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"Texture\\TITLE.bmp", L"Texture\\TITLE.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"Texture\\BlackWin.bmp", L"Texture\\BlackWin.bmp");
GET_SINGLE(ResourceManager)->TextureLoad(L"Texture\\WhiteWin.bmp", L"Texture\\WhiteWin.bmp");
}

int BaseWindow::MessageLoop() {
    MSG msg;

    AllTextureLoad();

    std::thread gameThread(GameLoopv2); // GameLoop 실행 스레드
    std::thread renderThread(Rendering); // Rendering 실행 스레드

    while (isPlaying) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                isPlaying = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // 메시지 큐가 비었을 때도 계속 루프
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    // 스레드 종료
    isPlaying = false;
    if (gameThread.joinable()) gameThread.join();
    if (renderThread.joinable()) renderThread.join();

    GET_SINGLE(Core)->CleanUp();
    return static_cast<int>(msg.wParam);
}
