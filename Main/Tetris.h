#ifndef H_Tetris
#define H_Tetris
#include "BaseApp.h"

class Tetris : public BaseApp
{
	typedef BaseApp Parent;

private:

	int** GameObject;
	int h;
	int r;
	int z;


	int g, k, f;

	bool mDirection;


public:
	Tetris();
	virtual void KeyPressed(int btnCode);
	virtual void UpdateF(float deltaTime);
	virtual bool Check();
	virtual int** Randomizer(int z) {}
	virtual int** Rotation(int z, int** Object) {}
	int CheckLine();
};
#endif