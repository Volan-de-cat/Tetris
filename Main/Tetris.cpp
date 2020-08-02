#include <cstdlib>
#include "Tetris.h"
#include "Constants.h"


Tetris::Tetris() : Parent(26, 27)
{
	while (Check())
	{
		z = rand() % 7;
		Randomizer(z);
		mDirection = true;
		r = rand() % 7;
		Next(r);
	}
}


void Tetris::KeyPressed(int btnCode)
{
	if (btnCode == getSpaceKey()) //пробел
	{

		if (!(GetChar(mObj3X + 1, mObj3Y) == getBorder()) && !(GetChar(mObj3X - 1, mObj3Y) == getBorder()) && !(GetChar(mObj3X, mObj3Y - 1) == getBorder()) && !(GetChar(mObj3X, mObj3Y + 1) ==getBorder()) && !(GetChar(mObj3X + 1, mObj3Y + 1) == getBorder()) && !(GetChar(mObj3X - 1, mObj3Y - 1) == getBorder()))
		{
			SetChar(mObj1X, mObj1Y, getSpace());
			SetChar(mObj2X, mObj2Y, getSpace());
			SetChar(mObj3X, mObj3Y, getSpace());
			SetChar(mObj4X, mObj4Y, getSpace());
			Rotation(z, k);
			SetChar(mObj1X, mObj1Y, getObject());
			SetChar(mObj2X, mObj2Y, getObject());
			SetChar(mObj3X, mObj3Y, getObject());
			SetChar(mObj4X, mObj4Y, getObject());
			k++;
			if (k > 3)
			{
				k = 0;
			}
		}
	}
	else if (btnCode == getDownKey()) //s
	{
		h = 9;
	}
	else if (btnCode == getLeftKey()) //a
	{
		if ((mObj1X > 1) && (mObj2X > 1) && (mObj3X > 1) && (mObj4X > 1))
		{
			SetChar(mObj1X, mObj1Y, getSpace());
			mObj1X--;
			SetChar(mObj1X, mObj1Y, getObject());
			SetChar(mObj2X, mObj2Y, getSpace());
			mObj2X--;
			SetChar(mObj2X, mObj2Y, getObject());
			SetChar(mObj3X, mObj3Y, getSpace());
			mObj3X--;
			SetChar(mObj3X, mObj3Y, getObject());
			SetChar(mObj4X, mObj4Y, getSpace());
			mObj4X--;
			SetChar(mObj4X, mObj4Y, getObject());
		}
	}
	else if (btnCode == getRightKey()) //d
	{
		if ((mObj1X < getLine()) && (mObj2X < getLine()) && (mObj3X < getLine()) && (mObj4X < getLine()))
		{
			SetChar(mObj1X, mObj1Y, getSpace());
			mObj1X++;
			SetChar(mObj1X, mObj1Y, getObject());
			SetChar(mObj2X, mObj2Y, getSpace());
			mObj2X++;
			SetChar(mObj2X, mObj2Y, getObject());
			SetChar(mObj3X, mObj3Y, getSpace());
			mObj3X++;
			SetChar(mObj3X, mObj3Y, getObject());
			SetChar(mObj4X, mObj4Y, getSpace());
			mObj4X++;
			SetChar(mObj4X, mObj4Y, getObject());
		}
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
					SetChar(x, y, getSpace());
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
	SetChar(mObj1X, mObj1Y, getSpace());
	SetChar(mObj2X, mObj2Y, getSpace());
	SetChar(mObj3X, mObj3Y, getSpace());
	SetChar(mObj4X, mObj4Y, getSpace());
	h++;
	if (mDirection)
	{
		if ((h % 10) == 0)
		{
			mObj1Y++;
			mObj2Y++;
			mObj3Y++;
			mObj4Y++;
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
	SetChar(mObj1X, mObj1Y, getObject());
	SetChar(mObj2X, mObj2Y, getObject());
	SetChar(mObj3X, mObj3Y, getObject());
	SetChar(mObj4X, mObj4Y, getObject());
	SetChar(a1, b1, getObject());
	SetChar(a2, b2, getObject());
	SetChar(a3, b3, getObject());
	SetChar(a4, b4, getObject());
	if ((!mDirection) && Check())
	{
		Next(r);
		if ((GetChar(a1 - 10, b1 - 2) == getSpace()) && (GetChar(a2 - 10, b2 - 2) == getSpace()) && (GetChar(a3 - 10, b3 - 2) == getSpace()) && (GetChar(a4 - 10, b4 - 2) == getSpace()))
		{
			Randomizer(z);
			mDirection = true;
			k = 0;
			r = rand() % 7;
			SetChar(a1, b1, getSpace());
			SetChar(a2, b2, getSpace());
			SetChar(a3, b3, getSpace());
			SetChar(a4, b4, getSpace());
			Next(r);
			SetChar(a1, b1, getObject());
			SetChar(a2, b2, getObject());
			SetChar(a3, b3, getObject());
			SetChar(a4, b4, getObject());
		}
		else
		{
			exit(0);
		}
	}
}

bool Tetris::Check()
{
	if ((GetChar(mObj1X, mObj1Y + 1) == getBorder()) || (GetChar(mObj2X, mObj2Y + 1) == getBorder()) || (GetChar(mObj3X, mObj3Y + 1) == getBorder()) || (GetChar(mObj4X, mObj4Y + 1) == getBorder()))
	{
		return true;
	}
	else if ((GetChar(mObj1X, mObj1Y + 1) == getObject()) || (GetChar(mObj2X, mObj2Y + 1) == getObject()) || (GetChar(mObj3X, mObj3Y + 1) == getObject()) || (GetChar(mObj4X, mObj4Y + 1) == getObject()))
	{
		return true;
	}
	else return false;

}

int Tetris::Randomizer(int z)
{
	switch (z)
	{
	case 0://I
	{
		mObj1X = 10;
		mObj1Y = 4;
		mObj2X = 10;
		mObj2Y = 3;
		mObj3X = 10;
		mObj3Y = 2;
		mObj4X = 10;
		mObj4Y = 1;
		return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
	}
	case 1:// S
	{
		mObj1X = 11;
		mObj1Y = 1;
		mObj2X = 10;
		mObj2Y = 1;
		mObj3X = 10;
		mObj3Y = 2;
		mObj4X = 9;
		mObj4Y = 2;
		return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
	}
	case 2://reverse S
	{
		mObj1X = 9;
		mObj1Y = 1;
		mObj2X = 10;
		mObj2Y = 1;
		mObj3X = 10;
		mObj3Y = 2;
		mObj4X = 11;
		mObj4Y = 2;
		return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
	}
	case 3://square
	{
		mObj1X = 9;
		mObj1Y = 2;
		mObj2X = 10;
		mObj2Y = 2;
		mObj3X = 10;
		mObj3Y = 1;
		mObj4X = 9;
		mObj4Y = 1;
		return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
	}
	case 4:// reverse Г
	{
		mObj1X = 9;
		mObj1Y = 1;
		mObj2X = 10;
		mObj2Y = 1;
		mObj3X = 10;
		mObj3Y = 2;
		mObj4X = 10;
		mObj4Y = 3;
		return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
	}
	case 5://Г
	{
		mObj1X = 11;
		mObj1Y = 1;
		mObj2X = 10;
		mObj2Y = 1;
		mObj3X = 10;
		mObj3Y = 2;
		mObj4X = 10;
		mObj4Y = 3;
		return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
	}
	case 6://T
	{
		mObj1X = 10;
		mObj1Y = 1;
		mObj2X = 9;
		mObj2Y = 2;
		mObj3X = 10;
		mObj3Y = 2;
		mObj4X = 10;
		mObj4Y = 3;
		return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
	}
	}

}

int Tetris::Next(int z)
{
	switch (z)
	{
	case 0://I
	{
		a1 = 20;
		b1 = 6;
		a2 = 20;
		b2 = 5;
		a3 = 20;
		b3 = 4;
		a4 = 20;
		b4 = 3;
		return (a1, b1, a2, b2, a3, b3, a4, b4);
	}
	case 1:// S
	{
		a1 = 21;
		b1 = 3;
		a2 = 20;
		b2 = 3;
		a3 = 20;
		b3 = 4;
		a4 = 19;
		b4 = 4;
		return (a1, b1, a2, b2, a3, b3, a4, b4);
	}
	case 2://reverse S
	{
		a1 = 19;
		b1 = 3;
		a2 = 20;
		b2 = 3;
		a3 = 20;
		b3 = 4;
		a4 = 21;
		b4 = 4;
		return (a1, b1, a2, b2, a3, b3, a4, b4);
	}
	case 3://квадрат
	{
		a1 = 19;
		b1 = 4;
		a2 = 20;
		b2 = 4;
		a3 = 20;
		b3 = 3;
		a4 = 19;
		b4 = 3;
		return (a1, b1, a2, b2, a3, b3, a4, b4);
	}
	case 4:// reverse Г
	{
		a1 = 19;
		b1 = 3;
		a2 = 20;
		b2 = 3;
		a3 = 20;
		b3 = 4;
		a4 = 20;
		b4 = 5;
		return (a1, b1, a2, b2, a3, b3, a4, b4);
	}
	case 5://Г
	{
		a1 = 21;
		b1 = 3;
		a2 = 20;
		b2 = 3;
		a3 = 20;
		b3 = 4;
		a4 = 20;
		b4 = 5;
		return (a1, b1, a2, b2, a3, b3, a4, b4);
	}
	case 6://T
	{
		a1 = 20;
		b1 = 3;
		a2 = 19;
		b2 = 4;
		a3 = 20;
		b3 = 4;
		a4 = 20;
		b4 = 5;
		return (a1, b1, a2, b2, a3, b3, a4, b4);
	}
	}
}

int Tetris::Rotation(int z, int k)
{
	switch (z)
	{
	case 0://I
	{
		if (k == 0)
		{
			mObj1X += (-2);
			mObj1Y += (-2);
			mObj2X += (-1);
			mObj2Y += (-1);
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 1)
		{
			mObj1X += 2;
			mObj1Y += 2;
			mObj2X += 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += (-1);
			mObj4Y += (-1);
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 2)
		{
			mObj1X += (-2);
			mObj1Y += (-2);
			mObj2X += (-1);
			mObj2Y += (-1);
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 3)
		{
			mObj1X += 2;
			mObj1Y += 2;
			mObj2X += 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += (-1);
			mObj4Y += (-1);
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
	}
	case 1://S
	{
		if (k == 0)
		{
			mObj1X -= 2;
			mObj1Y += 0;
			mObj2X -= 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 1)
		{
			mObj1X += 2;
			mObj1Y += 0;
			mObj2X += 1;
			mObj2Y += (-1);
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += (-1);
			mObj4Y -= 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 2)
		{
			mObj1X -= 2;
			mObj1Y += 0;
			mObj2X -= 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 3)
		{
			mObj1X += 2;
			mObj1Y += 0;
			mObj2X += 1;
			mObj2Y += (-1);
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += (-1);
			mObj4Y -= 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
	}
	case 2://reverse S
	{
		if (k == 0)
		{
			mObj1X += 0;
			mObj1Y += 2;
			mObj2X -= 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X -= 1;
			mObj4Y -= 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 1)
		{
			mObj1X += 0;
			mObj1Y -= 2;
			mObj2X += 1;
			mObj2Y -= 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 2)
		{
			mObj1X += 0;
			mObj1Y += 2;
			mObj2X -= 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X -= 1;
			mObj4Y -= 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 3)
		{
			mObj1X += 0;
			mObj1Y -= 2;
			mObj2X += 1;
			mObj2Y -= 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
	}
	case 3://квадрат
	{
		mObj1X += 0;
		mObj1Y += 0;
		mObj2X += 0;
		mObj2Y += 0;
		mObj3X += 0;
		mObj3Y += 0;
		mObj4X += 0;
		mObj4Y += 0;
		return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
	}
	case 4:// reverse Г
	{
		if (k == 0)
		{
			mObj1X += 0;
			mObj1Y += 2;
			mObj2X += (-1);
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += (-1);
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 1)
		{
			mObj1X += 2;
			mObj1Y += 0;
			mObj2X += 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += (-1);
			mObj4Y += (-1);
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 2)
		{
			mObj1X += 0;
			mObj1Y += (-2);
			mObj2X += 1;
			mObj2Y += (-1);
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += (-1);
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 3)
		{
			mObj1X += (-2);
			mObj1Y += 0;
			mObj2X += (-1);
			mObj2Y += (-1);
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
	}
	case 5://Г
	{
		if (k == 0)
		{
			mObj1X += (-2);
			mObj1Y += 0;
			mObj2X += (-1);
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += (-1);
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 1)
		{
			mObj1X += 0;
			mObj1Y += 2;
			mObj2X += 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += (-1);
			mObj4Y += (-1);
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 2)
		{
			mObj1X += 2;
			mObj1Y += 0;
			mObj2X += 1;
			mObj2Y += (-1);
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += (-1);
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 3)
		{
			mObj1X += 0;
			mObj1Y += (-2);
			mObj2X += (-1);
			mObj2Y += (-1);
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
	}
	case 6://T
	{
		if (k == 0)
		{
			mObj1X -= 1;
			mObj1Y += 1;
			mObj2X += 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y -= 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 1)
		{
			mObj1X += 1;
			mObj1Y += 1;
			mObj2X += 1;
			mObj2Y -= 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X -= 1;
			mObj4Y -= 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 2)
		{
			mObj1X += 1;
			mObj1Y -= 1;
			mObj2X -= 1;
			mObj2Y -= 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X -= 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
		else if (k == 3)
		{
			mObj1X -= 1;
			mObj1Y -= 1;
			mObj2X -= 1;
			mObj2Y += 1;
			mObj3X += 0;
			mObj3Y += 0;
			mObj4X += 1;
			mObj4Y += 1;
			return (mObj1X, mObj1Y, mObj2X, mObj2Y, mObj3X, mObj3Y, mObj4X, mObj4Y);
		}
	}
	}

}

