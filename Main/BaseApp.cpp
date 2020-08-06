#include <algorithm>
#include <time.h>
#include <conio.h>
#include <assert.h>
#include <strsafe.h>
#include "Tetris.h"
#include "Constants.h"
#include "Graphics.h"

#include"Timer.h"

BaseApp::BaseApp(int xSize, int ySize) : X_SIZE(xSize), Y_SIZE(ySize)
{
	
	console = GetConsoleWindow();
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 243, 500, TRUE);

	SMALL_RECT windowSize = { 0, 0, X_SIZE, Y_SIZE };
	COORD windowBufSize = { X_SIZE + 1, Y_SIZE + 1 };

	mConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	mConsoleIn = GetStdHandle(STD_INPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(mConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(mConsole, &cursorInfo);

	mChiBuffer = (CHAR_INFO*)malloc((X_SIZE + 1)*(Y_SIZE + 1) * sizeof(CHAR_INFO));

	mDwBufferSize.X = X_SIZE + 1;
	mDwBufferSize.Y = Y_SIZE + 1;		// размер буфера данных

	mDwBufferCoord.X = 0;
	mDwBufferCoord.Y = 0;				// координаты €чейки

	mLpWriteRegion.Left = 0;
	mLpWriteRegion.Top = 0;
	mLpWriteRegion.Right = X_SIZE + 1;
	mLpWriteRegion.Bottom = Y_SIZE + 1;	// пр€моугольник дл€ чтени€

	Field(X_SIZE, Y_SIZE);
}

BaseApp::~BaseApp()
{
	free(mChiBuffer);
}

void BaseApp::SetChar(int x, int y, char c)
{
	mChiBuffer[x + (X_SIZE + 1)*y].Char.UnicodeChar = c;
	mChiBuffer[x + (X_SIZE + 1)*y].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
	if (c == getBorder())
	{
		mChiBuffer[x + (X_SIZE + 1)*y].Attributes = FOREGROUND_BLUE | FOREGROUND_RED;
	}
	if (c == getObject())
	{
		mChiBuffer[x + (X_SIZE + 1)*y].Attributes = FOREGROUND_BLUE;
	}
}

char BaseApp::GetChar(int x, int y)
{
	return mChiBuffer[x + (X_SIZE + 1)*y].Char.AsciiChar;
}

void BaseApp::Render()
{
	if (!WriteConsoleOutput(mConsole, mChiBuffer, mDwBufferSize, mDwBufferCoord, &mLpWriteRegion))
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
	}
}

void BaseApp::Run()
{
	CStopwatch timer;
	int sum = 0;
	int counter = 0;


	int deltaTime = 0;
	while (1)
	{
		timer.Start();
		if (_kbhit())
		{
			KeyPressed(_getch());
			if (!FlushConsoleInputBuffer(mConsoleIn))
				cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
		}
			UpdateF((float)deltaTime / 1000.0f);
			Render();

		while (1)
		{
			deltaTime = timer.Now();
			if (deltaTime > 20)
				break;
		}

		sum += deltaTime;
		counter++;
		if (sum >= 1000)
		{
			TCHAR  szbuff[255];
			StringCchPrintf(szbuff, 255, TEXT("FPS: %d"), counter);
			SetConsoleTitle(szbuff);

			counter = 0;
			sum = 0;
		}
	}
}