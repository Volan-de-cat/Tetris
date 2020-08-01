#include <windows.h>
#include "Timer.h"

CStopwatch::CStopwatch()
{
	QueryPerformanceFrequency(&m_liPerfFreq);
	Start();
}

void CStopwatch::Start()
{
	QueryPerformanceCounter(&m_liPerfStart);
}

int CStopwatch::Now()
{
	// возвращает число миллисекунд после вызова Start
	LARGE_INTEGER liPerfNow;
	QueryPerformanceCounter(&liPerfNow);
	return (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000) / m_liPerfFreq.QuadPart);
}

int CStopwatch::Time()
{
	LARGE_INTEGER liPerfNow;
	QueryPerformanceCounter(&liPerfNow);
	return ((liPerfNow.QuadPart * 1000) / m_liPerfFreq.QuadPart);
}