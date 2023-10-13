#include "yaApplication.h"
#include <WinUser.h>
#include "yaGraphicsDevice_DX11.h"
#include "yaTextManager.h"
#include "yaScene.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaRenderer.h"
#include "yaSceneManager.h"
#include "yaColliderManager.h"
#include "yaCamera.h"
#include "yaWaveManager.h"
#include "..\\YamYamEngine_Windows\yaLoadScene.h"

using namespace ya::graphics;

namespace ya
{
	Application::~Application()
	{
		renderer::Release();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destroy();
	}

	void Application::Initialize()
	{
		Time::Initialize();
		Input::Initialize();
		Camera::Initialize();
		renderer::Initialize();
		ya::InitializeScenes();
		SceneManager::Initialize();
		ColliderManager::CollisionLayerCheck(enums::LAYER::Monster, enums::LAYER::Player, true);
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		Camera::Update();
		WaveManager::Update();
		SceneManager::Update();
		ColliderManager::Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		graphicsDevice->Clear();
		graphicsDevice->AdjustViewport();

		Time::Render();
		SceneManager::Render();
		TextManager::Render();

		//graphicsDevice->Render();
		graphicsDevice->Present();
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::SetWindow(HWND hwnd, HDC dc, UINT width, UINT height)
	{
		if (graphicsDevice == nullptr)
		{
			mHwnd = hwnd;
			mDC = dc;
			mWidth = width;
			mHeight = height;

			graphicsDevice = std::make_unique<GraphicsDevice_DX11>();
			ya::graphics::GetDevice() = graphicsDevice.get();
			//ya::device = graphicsDevice.get();
		}

		RECT rt = { 0, 0, (LONG)width , (LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}
}
