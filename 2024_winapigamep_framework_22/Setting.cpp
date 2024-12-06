#include "pch.h"
#include "Setting.h"
#include "MapManager.h"
#include "Button.h"
#include "SceneManager.h"
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

#pragma comment(lib, "ole32.lib")

void AdjustSystemVolume(float volumeStep);

void Setting::Init()
{

}

void Setting::Update()
{
	Button* btn = new Button;
	btn->SetActive(true);
	btn->SetPos({ 100,100 });
	btn->SetSize({ 300, 200 });
	btn->SetText({ L"볼륨업" });
	btn->Init();
	AddUI(btn, LAYER::UI);

    Button* btn2 = new Button;
    btn2->SetActive(true);
    btn2->SetPos({ 800,100 });
    btn2->SetSize({ 300, 200 });
    btn2->SetText({ L"볼륨다운" });
    btn2->Init();
    AddUI(btn2, LAYER::UI);

    if (btn->IsMouseDown())
    {
        float volumeStep = 0.1f; // 줄일 볼륨 스텝 (10%)
        AdjustSystemVolume(volumeStep);
    }
    if (btn2->IsMouseDown())
    {
        float volumeStep = -0.1f; // 줄일 볼륨 스텝 (10%)
        AdjustSystemVolume(volumeStep);
    }




	if (INPUT->GetKey(KEY_TYPE::ESC) == KEY_STATE::DOWN)
	{
		GET_SINGLE(SceneManager)->LoadScene(L"IntroScene");
	}
}

void Setting::Render(HDC _hdc)
{
	GET_SINGLE(MapManager)->RenderMing(_hdc);

	if (GET_SINGLE(MapManager)->canStart)
	{
		Scene::Render(_hdc);
	}


	for (size_t i = 0; i < m_vecUI.size(); ++i)
	{
		if (m_vecUI[i]->GetActive() == true)
			m_vecUI[i]->Render(_hdc);
	}
}

void AdjustSystemVolume(float volumeStep)
{
    CoInitialize(nullptr); // COM 라이브러리 초기화

    IMMDeviceEnumerator* pDeviceEnumerator = nullptr;
    IMMDevice* pDevice = nullptr;
    IAudioEndpointVolume* pEndpointVolume = nullptr;

    // IMMDeviceEnumerator 생성
    HRESULT hr = CoCreateInstance(
        __uuidof(MMDeviceEnumerator),
        nullptr,
        CLSCTX_ALL,
        __uuidof(IMMDeviceEnumerator),
        (void**)&pDeviceEnumerator
    );

    if (FAILED(hr))
    {
        std::cerr << "IMMDeviceEnumerator 생성 실패." << std::endl;
        return;
    }

    // 기본 오디오 장치 가져오기
    hr = pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
    if (FAILED(hr))
    {
        std::cerr << "오디오 장치 가져오기 실패." << std::endl;
        pDeviceEnumerator->Release();
        return;
    }

    // IAudioEndpointVolume 인터페이스 가져오기
    hr = pDevice->Activate(
        __uuidof(IAudioEndpointVolume),
        CLSCTX_ALL,
        nullptr,
        (void**)&pEndpointVolume
    );

    if (FAILED(hr))
    {
        std::cerr << "IAudioEndpointVolume 인터페이스 활성화 실패." << std::endl;
        pDevice->Release();
        pDeviceEnumerator->Release();
        return;
    }

    // 현재 볼륨 가져오기
    float currentVolume = 0.0f;
    hr = pEndpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
    if (SUCCEEDED(hr))
    {
        std::cout << "현재 볼륨: " << currentVolume * 100 << "%" << std::endl;

        // 볼륨 줄이기
        float newVolume = currentVolume - volumeStep;
        if (newVolume < 0.0f) newVolume = 0.0f;

        hr = pEndpointVolume->SetMasterVolumeLevelScalar(newVolume, nullptr);
        if (SUCCEEDED(hr))
        {
            std::cout << "볼륨을 " << newVolume * 100 << "%로 설정했습니다." << std::endl;
        }
        else
        {
            std::cerr << "볼륨 설정 실패." << std::endl;
        }
    }
    else
    {
        std::cerr << "현재 볼륨 가져오기 실패." << std::endl;
    }

    // 메모리 해제
    pEndpointVolume->Release();
    pDevice->Release();
    pDeviceEnumerator->Release();
    CoUninitialize();
}