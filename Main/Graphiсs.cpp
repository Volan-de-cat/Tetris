#include "Constants.h"
#include "Graphics.h"

void Graphics::Field(int xSize, int ySize) 
{
	for (int x = 0; x < xSize + 1; x++)
	{
		for (int y = 0; y < ySize+ 1; y++)
		{
			if (y < ySize)
			{
				SetChar(0, y, getBorder());
				SetChar(xSize - 1, y, getBorder());
				if (y < getInnerBorder())
				{
					SetChar(getLine() + 1, y, getBorder());
				}
			}
			SetChar(x, y, getEmpty());
		}
		string Score_ = getScore();
		if (x <= Score_.length())
		{
			SetChar(x, getInnerBorder() + 1, Score_[x]);
		}
		if (x < xSize)
		{
			SetChar(x, 0, getBorder());
			SetChar(x, getInnerBorder() - 1, getBorder());
			SetChar(x, ySize, getBorder());
		}
	}
}

void Graphics::Start(int** Object, int z)
{
	
	if (z == 0)
	{
		for (int j = 0; j < getLineSize(); j++)
		{
			for (int i = 0; i < getLineSize(); i++)
			{
				if (Object[i][j] == 1)
				{
					SetChar(getStartPozition() + i, j + 1, getObject());
				}
			}
		}
	}
	else if (z == 3)
	{
		for (int j = 0; j < getSquareSize(); j++)
		{
			for (int i = 0; i < getSquareSize(); i++)
			{
				if (Object[i][j] == 1)
				{
					SetChar(getStartPozition() + i, j + 1, getObject());
				}
			}
		}
	}
	else
	{
		for (int j = 0; j < getOtherSize(); j++)
		{
			for (int i = 0; i < getOtherSize(); i++)
			{
				if (Object[i][j] == 1)
				{
					SetChar(getStartPozition() + i, j + 1, getObject());
				}
			}
		}
	}
}
