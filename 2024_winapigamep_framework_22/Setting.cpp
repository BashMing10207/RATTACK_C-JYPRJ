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
	btn->SetText({ L"������" });
	btn->Init();
	AddUI(btn, LAYER::UI);

    Button* btn2 = new Button;
    btn2->SetActive(true);
    btn2->SetPos({ 800,100 });
    btn2->SetSize({ 300, 200 });
    btn2->SetText({ L"�����ٿ�" });
    btn2->Init();
    AddUI(btn2, LAYER::UI);

    if (btn->IsMouseDown())
    {
        float volumeStep = 0.1f; // ���� ���� ���� (10%)
        AdjustSystemVolume(volumeStep);
    }
    if (btn2->IsMouseDown())
    {
        float volumeStep = -0.1f; // ���� ���� ���� (10%)
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
    CoInitialize(nullptr); // COM ���̺귯�� �ʱ�ȭ

    IMMDeviceEnumerator* pDeviceEnumerator = nullptr;
    IMMDevice* pDevice = nullptr;
    IAudioEndpointVolume* pEndpointVolume = nullptr;

    // IMMDeviceEnumerator ����
    HRESULT hr = CoCreateInstance(
        __uuidof(MMDeviceEnumerator),
        nullptr,
        CLSCTX_ALL,
        __uuidof(IMMDeviceEnumerator),
        (void**)&pDeviceEnumerator
    );

    if (FAILED(hr))
    {
        std::cerr << "IMMDeviceEnumerator ���� ����." << std::endl;
        return;
    }

    // �⺻ ����� ��ġ ��������
    hr = pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
    if (FAILED(hr))
    {
        std::cerr << "����� ��ġ �������� ����." << std::endl;
        pDeviceEnumerator->Release();
        return;
    }

    // IAudioEndpointVolume �������̽� ��������
    hr = pDevice->Activate(
        __uuidof(IAudioEndpointVolume),
        CLSCTX_ALL,
        nullptr,
        (void**)&pEndpointVolume
    );

    if (FAILED(hr))
    {
        std::cerr << "IAudioEndpointVolume �������̽� Ȱ��ȭ ����." << std::endl;
        pDevice->Release();
        pDeviceEnumerator->Release();
        return;
    }

    // ���� ���� ��������
    float currentVolume = 0.0f;
    hr = pEndpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
    if (SUCCEEDED(hr))
    {
        std::cout << "���� ����: " << currentVolume * 100 << "%" << std::endl;

        // ���� ���̱�
        float newVolume = currentVolume - volumeStep;
        if (newVolume < 0.0f) newVolume = 0.0f;

        hr = pEndpointVolume->SetMasterVolumeLevelScalar(newVolume, nullptr);
        if (SUCCEEDED(hr))
        {
            std::cout << "������ " << newVolume * 100 << "%�� �����߽��ϴ�." << std::endl;
        }
        else
        {
            std::cerr << "���� ���� ����." << std::endl;
        }
    }
    else
    {
        std::cerr << "���� ���� �������� ����." << std::endl;
    }

    // �޸� ����
    pEndpointVolume->Release();
    pDevice->Release();
    pDeviceEnumerator->Release();
    CoUninitialize();
}