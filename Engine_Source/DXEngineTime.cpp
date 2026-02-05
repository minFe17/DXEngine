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

	void Time::Render()
	{
		
	}
}