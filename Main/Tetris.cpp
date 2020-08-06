#include <cstdlib>
#include "Tetris.h"
#include "Figura.h"
#include "Constants.h"


Tetris::Tetris() : Parent(26, 27)
{
	while (Check())
	{
		z = rand() % 7;
		Randomizer(z);
		mDirection = true;

	}
}


void Tetris::KeyPressed(int btnCode)
{ 
	if (btnCode == getRotationKey()) //space
	{
	}
	else if (btnCode == getDownKey()) //s
	{
		h = 9;
	}
	else if (btnCode == getLeftKey()) //a
	{

	}
	else if (btnCode == getRightKey()) //d
	{

	}
}

int Tetris::CheckLine()
{
	char* full = new char[getLine() - 1];
	for (int y = 1; y < getInnerBorder() - 1; y++)
	{
		for (int x = 0; x < getLine() - 1; x++)
		{
			full[x] = GetChar(x + 1, y);
			if (full[x] == getObject())
			{
				f++;
				k = y;
			}
		}
		if (f == (getLine() - 1))
		{
			for (int y = k; y > 1; y--)
			{
				for (int x = 0; x < getLine() - 1; x++)
				{
					SetChar(x, y, getEmpty());
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

void Tetris::UpdateF(float deltaTime)
{
	string score;

	h++;
	if (mDirection)
	{
		if ((h % 10) == 0)
		{

		score = to_string(CheckLine());
		for (int i = 0; i < score.length(); i++)
		{
			SetChar(getScore().length() + i, getInnerBorder() + 1, score[i]);
		}
			if (Check())
			{
				mDirection = false;
				z = r;
			}
		}
	}

	if ((!mDirection) && Check())
	{

	}
}

/*bool Tetris::Check()
{

}*/