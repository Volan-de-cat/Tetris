
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
	

	//аргументами €вл€ютс€ размеры области вывода по горизонтали и вертикали в символах
	BaseApp(int xSize = 26, int ySize = 27);
	virtual ~BaseApp();
	
	//провер€ет заполнена ли лини€ и в случае заполнени€ удал€ет линию и начисл€ет очки

	//запускает игровой цикл
	void Run();

	virtual void Field(int xSize, int ySize) {}

	//можно заполнить x,y-символ экрана определенным символом, или считать его
	void SetChar(int x, int y, char c);
	char GetChar(int x, int y);

	/*эта функци€ вызываетс€ каждую игровую итерацию, еЄ можно переопределить, в наследнике класса.
	в неЄ приходит deltaTime - разница во времени между предыдущей итерацией и этой, в секундах*/
	virtual void UpdateF(float deltaTime) {}
	/*эта функци€ вызываетс€ при нажатии клавиши на клавиатуре, в неЄ приходит код клавиши - btnCode.
	если использовать стрелки или функциональные клавиши, то придет общее дл€ них число, например 224, а следующее за ним -
	будет уже непосредственно код самой клавиши, его можно получить, вызвав метод getch().
	ћетод KeyPressed так же можно переопределить в наследнике*/
	virtual void KeyPressed(int btnCode) {}
};