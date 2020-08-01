#include "Tetris.h"
#include<cstdlib>

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
	if (btnCode == 32) //пробел
	{

		if (!(GetChar(mObj3X + 1, mObj3Y) == '#') && !(GetChar(mObj3X - 1, mObj3Y) == '#') && !(GetChar(mObj3X, mObj3Y - 1) == '#') && !(GetChar(mObj3X, mObj3Y + 1) == '#') && !(GetChar(mObj3X + 1, mObj3Y + 1) == '#') && !(GetChar(mObj3X - 1, mObj3Y - 1) == '#'))
		{
			SetChar(mObj1X, mObj1Y, L' ');
			SetChar(mObj2X, mObj2Y, L' ');
			SetChar(mObj3X, mObj3Y, L' ');
			SetChar(mObj4X, mObj4Y, L' ');
			Rotation(z, k);
			SetChar(mObj1X, mObj1Y, L'$');
			SetChar(mObj2X, mObj2Y, L'$');
			SetChar(mObj3X, mObj3Y, L'$');
			SetChar(mObj4X, mObj4Y, L'$');
			k++;
			if (k > 3)
			{
				k = 0;
			}
		}
	}
	else if (btnCode == 80) //s
	{
		h = 9;
	}
	else if (btnCode == 75) //a
	{
		if ((mObj1X > 1) && (mObj2X > 1) && (mObj3X > 1) && (mObj4X > 1))
		{
			SetChar(mObj1X, mObj1Y, L' ');
			mObj1X--;
			SetChar(mObj1X, mObj1Y, L'$');
			SetChar(mObj2X, mObj2Y, L' ');
			mObj2X--;
			SetChar(mObj2X, mObj2Y, L'$');
			SetChar(mObj3X, mObj3Y, L' ');
			mObj3X--;
			SetChar(mObj3X, mObj3Y, L'$');
			SetChar(mObj4X, mObj4Y, L' ');
			mObj4X--;
			SetChar(mObj4X, mObj4Y, L'$');
		}
	}
	else if (btnCode == 77) //d
	{
		if ((mObj1X < 15) && (mObj2X < 15) && (mObj3X < 15) && (mObj4X < 15))
		{
			SetChar(mObj1X, mObj1Y, L' ');
			mObj1X++;
			SetChar(mObj1X, mObj1Y, L'$');
			SetChar(mObj2X, mObj2Y, L' ');
			mObj2X++;
			SetChar(mObj2X, mObj2Y, L'$');
			SetChar(mObj3X, mObj3Y, L' ');
			mObj3X++;
			SetChar(mObj3X, mObj3Y, L'$');
			SetChar(mObj4X, mObj4Y, L' ');
			mObj4X++;
			SetChar(mObj4X, mObj4Y, L'$');
		}
	}
}

void Tetris::UpdateF(float deltaTime)
{
	int g;
	SetChar(mObj1X, mObj1Y, L' ');
	SetChar(mObj2X, mObj2Y, L' ');
	SetChar(mObj3X, mObj3Y, L' ');
	SetChar(mObj4X, mObj4Y, L' ');
	h++;
	if (mDirection)
	{
		if ((h % 10) == 0)
		{
			mObj1Y++;
			mObj2Y++;
			mObj3Y++;
			mObj4Y++;
			g = (CheckLine());
			if (g == 10)
			{
				g = 0;
				p++;
				if (p == 10)
				{
					p = 0;
					q++;
					char symbol3 = q + '0';
					SetChar(10, 24, symbol3);
				}
				char symbol2 = p + '0';
				SetChar(11, 24, symbol2);
			}
			char symbol1 = g + '0';
			SetChar(12, 24, symbol1);
			if (Check())
			{
				mDirection = false;
				z = r;
			}
		}
	}
	SetChar(mObj1X, mObj1Y, L'$');
	SetChar(mObj2X, mObj2Y, L'$');
	SetChar(mObj3X, mObj3Y, L'$');
	SetChar(mObj4X, mObj4Y, L'$');
	SetChar(a1, b1, L'$');
	SetChar(a2, b2, L'$');
	SetChar(a3, b3, L'$');
	SetChar(a4, b4, L'$');
	if ((!mDirection) && Check())
	{
		Next(r);
		if ((GetChar(a1 - 10, b1 - 2) == ' ') && (GetChar(a2 - 10, b2 - 2) == ' ') && (GetChar(a3 - 10, b3 - 2) == ' ') && (GetChar(a4 - 10, b4 - 2) == ' '))
		{
			Randomizer(z);
			mDirection = true;
			k = 0;
			r = rand() % 7;
			SetChar(a1, b1, L' ');
			SetChar(a2, b2, L' ');
			SetChar(a3, b3, L' ');
			SetChar(a4, b4, L' ');
			Next(r);
			SetChar(a1, b1, L'$');
			SetChar(a2, b2, L'$');
			SetChar(a3, b3, L'$');
			SetChar(a4, b4, L'$');
		}
		else
		{
			exit(0);
		}
	}
}

bool Tetris::Check()
{
	if ((GetChar(mObj1X, mObj1Y + 1) == '#') || (GetChar(mObj2X, mObj2Y + 1) == '#') || (GetChar(mObj3X, mObj3Y + 1) == '#') || (GetChar(mObj4X, mObj4Y + 1) == '#'))
	{
		return true;
	}
	else if ((GetChar(mObj1X, mObj1Y + 1) == '$') || (GetChar(mObj2X, mObj2Y + 1) == '$') || (GetChar(mObj3X, mObj3Y + 1) == '$') || (GetChar(mObj4X, mObj4Y + 1) == '$'))
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
	case 2://обратное S
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
	case 3://квадрат
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
	case 4:// обратное Г
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
	case 2://обратное S
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
	case 4:// обратное Г
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
	case 2://обратное S
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
	case 4:// обратное Г
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

