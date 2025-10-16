#include "time.h"
#include <Windows.h>
#include <DxLib.h>
namespace {
	LARGE_INTEGER freq;
	LARGE_INTEGER current;
	float deltaTime;
	float refreshRate;
	// ���߂̏������Ԃ�ۑ�
	const int BUF_SIZE = 30;
	float timeBuf[BUF_SIZE];
	int readP;
	int writeP;
};

void Time::Init()
{
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&current);

	HDC hdc = GetDC(GetMainWindowHandle());	// �f�o�C�X�R���e�L�X�g�̎擾
	refreshRate = (float)GetDeviceCaps(hdc, VREFRESH);	// ���t���b�V�����[�g�̎擾
	ReleaseDC(GetMainWindowHandle(), hdc);	// �f�o�C�X�R���e�L�X�g�̉��

	readP = 0;
	writeP = 0;
}

void Time::Refresh()
{
	LARGE_INTEGER last = current;
	QueryPerformanceCounter(&current);
	float dt = static_cast<float >(current.QuadPart - last.QuadPart) / freq.QuadPart;
	timeBuf[writeP] = dt;
	writeP = (writeP+1) % BUF_SIZE;
	if (writeP == readP) {
		readP = (readP + 1) % BUF_SIZE;
	}
	float sum = 0;
	int num = 0;
	for (int i = readP; i != writeP; i = (i + 1) % BUF_SIZE) {
		sum += timeBuf[i];
		num++;
	}
	if (num>BUF_SIZE/2) {
		float ave = sum / num;
		if (dt >= ave*2)
			deltaTime = ave*2;
		else
			deltaTime = dt;
	}
	else
		deltaTime = dt;
}

float Time::DeltaTime()
{
	return deltaTime;
}

void Time::Release()
{
}