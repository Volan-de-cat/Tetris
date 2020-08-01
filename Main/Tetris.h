#pragma once

#include "BaseApp.h"

class Tetris : public BaseApp
{
	typedef BaseApp Parent;

private:
	int mObj1X;
	int mObj1Y;
	int mObj2X;
	int mObj2Y;
	int mObj3X;
	int mObj3Y;
	int mObj4X;
	int mObj4Y;
	int h;
	int k;
	int z;
	int r;
	int p;
	int q;
	int a1;
	int b1;
	int a2;
	int b2;
	int a3;
	int b3;
	int a4;
	int b4;

	bool mDirection;


public:
	Tetris();
	virtual void KeyPressed(int btnCode);
	virtual void UpdateF(float deltaTime);
	int Next(int z);
	int Randomizer(int z);
	int Rotation(int z, int k);
	virtual bool Check();
};
