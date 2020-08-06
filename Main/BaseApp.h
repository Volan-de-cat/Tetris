
#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

class BaseApp
{
private:
	RECT r;
	HWND console;
	HANDLE mConsole;
	HANDLE mConsoleIn;

	CHAR_INFO* mChiBuffer;
	COORD mDwBufferSize;
	COORD mDwBufferCoord;
	SMALL_RECT mLpWriteRegion;



	void Render();

public:
	//dimensions of the output area horizontally and vertically in characters
	const int X_SIZE;
	const int Y_SIZE;
	

	//����������� �������� ������� ������� ������ �� ����������� � ��������� � ��������
	BaseApp(int xSize = 26, int ySize = 27);
	virtual ~BaseApp();
	
	//��������� ��������� �� ����� � � ������ ���������� ������� ����� � ��������� ����

	//��������� ������� ����
	void Run();

	virtual void Field(int xSize, int ySize) {}

	//����� ��������� x,y-������ ������ ������������ ��������, ��� ������� ���
	void SetChar(int x, int y, char c);
	char GetChar(int x, int y);

	/*��� ������� ���������� ������ ������� ��������, � ����� ��������������, � ���������� ������.
	� �� �������� deltaTime - ������� �� ������� ����� ���������� ��������� � ����, � ��������*/
	virtual void UpdateF(float deltaTime) {}
	/*��� ������� ���������� ��� ������� ������� �� ����������, � �� �������� ��� ������� - btnCode.
	���� ������������ ������� ��� �������������� �������, �� ������ ����� ��� ��� �����, �������� 224, � ��������� �� ��� -
	����� ��� ��������������� ��� ����� �������, ��� ����� ��������, ������ ����� getch().
	����� KeyPressed ��� �� ����� �������������� � ����������*/
	virtual void KeyPressed(int btnCode) {}
};