#pragma once
#include <iostream>
#include <vector>
#include <windows.h>

class Timer
{
public:
	Timer();
	~Timer();
	void Update();
	void startTimer();
	void reset();
	float elapsedTimer() { return elapsed; }

private:
	DWORD start = 0.0f;
	DWORD end = 0.0f;
	DWORD elapsed = 0.0f;




};

