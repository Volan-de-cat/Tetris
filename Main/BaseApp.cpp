#include "Tetris.h"
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <assert.h>
#include <strsafe.h>

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

	if (!SetConsoleScreenBufferSize(mConsole, windowBufSize))
	{
		cout << "SetConsoleScreenBufferSize failed with error " << GetLastError() << endl;
	}
	if (!SetConsoleWindowInfo(mConsole, TRUE, &windowSize))
	{
		cout << "SetConsoleWindowInfo failed with error " << GetLastError() << endl;
	}

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(mConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(mConsole, &cursorInfo);

	mChiBuffer = (CHAR_INFO*)malloc((X_SIZE + 1)*(Y_SIZE + 1) * sizeof(CHAR_INFO));

	mDwBufferSize.X = X_SIZE + 1;
	mDwBufferSize.Y = Y_SIZE + 1;		// ������ ������ ������

	mDwBufferCoord.X = 0;
	mDwBufferCoord.Y = 0;				// ���������� ������

	mLpWriteRegion.Left = 0;
	mLpWriteRegion.Top = 0;
	mLpWriteRegion.Right = X_SIZE + 1;
	mLpWriteRegion.Bottom = Y_SIZE + 1;	// ������������� ��� ������


	for (int x = 0; x < X_SIZE + 1; x++)
	{
		for (int y = 0; y < Y_SIZE + 1; y++)
		{
			if (y < 27)
			{
				SetChar(0, y, L'#');
				SetChar(25, y, L'#');

			}
			if (y < 26)
			{
				if (y < 23)
				{
					SetChar(16, y, L'#');
				}
				else
				{
					SetChar(16, y, L' ');
				}
			}
			SetChar(x, y, L' ');
		}
		if ((x >= 4) &&(x <= 10))
		{
			SetChar(4, 24, L'S');
			SetChar(5, 24, L'C');
			SetChar(6, 24, L'O');
			SetChar(7, 24, L'R');
			SetChar(8, 24, L'E');
			SetChar(9, 24, L':');
		}
		if (x < 26)
		{
			SetChar(x, 0, L'#');
			SetChar(x, 22, L'#');
			SetChar(x, 26, L'#');

		}
	}
}

BaseApp::~BaseApp()
{
	free(mChiBuffer);
}

void BaseApp::SetChar(int x, int y, wchar_t c)
{
	mChiBuffer[x + (X_SIZE + 1)*y].Char.UnicodeChar = c;
	mChiBuffer[x + (X_SIZE + 1)*y].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
	if (c == '#')
	{
		mChiBuffer[x + (X_SIZE + 1)*y].Attributes = FOREGROUND_BLUE | FOREGROUND_RED;
	}
	if (c == '$')
	{
		mChiBuffer[x + (X_SIZE + 1)*y].Attributes = FOREGROUND_BLUE;
	}
}

wchar_t BaseApp::GetChar(int x, int y)
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

int BaseApp::CheckLine()
{
	char t[16];
	for (int y = 1; y < 22; y++)
	{
		for (int x = 0; x < 14; x++)
		{
				t[x] = GetChar(x+1, y);
				if (t[x] == '$')
				{
					f++;
					k = y;
				}
		}
		if (f == 14)
		{
			for (int y = k; y > 1; y--)
			{
				for (int x = 0; x < 14; x++)
				{
					SetChar(x, y, L' ');
					char m;
					m = GetChar(x, y - 1);
					SetChar(x, y, m);
				}
			}
			g += 1;
		}
		f = 0;
	}
	return g;
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