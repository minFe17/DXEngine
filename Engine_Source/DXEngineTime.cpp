#include "DXEngineTime.h"

namespace DXEngine 
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};

	float Time::DeltaTimeValue = 0.0f;

	void Time::Init()
	{
		// CPU 고유 진동 수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작했을 때 현재 진동 수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		float fps = 1.0f / DeltaTimeValue;

		wchar_t fpsText[50] = L"";
		swprintf_s(fpsText, 50, L"fps : %d", (int)fps);
		int length = wcsnlen_s(fpsText, 50);

		TextOut(hdc, 0, 0, fpsText, length);
	}
}