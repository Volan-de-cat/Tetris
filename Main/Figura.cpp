#include "Figura.h"
#include "Constants.h"

int** Figura::Randomizer(int z)
{
	switch (z)
	{
	case 0://I
	{
		const int Size = 4;
		int** Object = new int* [Size];
		int* Object = new int [Size];
		int Object[Size][Size] =
		{
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 }
		};
		return Object;
	}
	case 1:// S
	{
		const int Size = getOtherSize();
		int** Object = new int*[Size];
		int* Object = new int[Size];
		int Object[Size][Size] =
		{
			{ 0, 1, 1 },
			{ 1, 1, 0 },
			{ 0, 0, 0 }
		};
		return Object;
	}
	case 2://reverse S
	{
		int Object[][getOtherSize()] =
		{
			{ 1, 1, 0 },
			{ 0, 1, 1 },
			{ 0, 0, 0 }
		};
		return Object;
	}
	

	case 3://square
	{
		const int Size = 2;
		int** Object = new int*[Size];
		int* Object = new int[Size];
		int Object[Size][Size] =
		{
			{ 1, 1 },
			{ 1, 1 }
		};
		return Object;
	}
	case 4:// L
	{
	
		const int Size = 3;
		int** Object = new int*[Size];
		int* Object = new int[Size];
		int Object[Size][Size] =
		{
			{ 0, 1, 0 },
			{ 0, 1, 0 },
			{ 0, 1, 1 }
		};
		return Object;
	
	}
	case 5://J
	{
		const int Size = 3;
		int** Object = new int*[Size];
		int* Object = new int[Size];
		int Object[Size][Size] =
		{
			{ 0, 1, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 }
		};
		return Object;
	}
	case 6://T
	{
		const int Size = 3;
		int** Object = new int*[Size];
		int* Object = new int[Size];
		int Object[Size][Size] =
		{
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 1, 0 },
		};
		return Object;
	}
	}

}

int** Figura::Rotation(int z, int** Object)
{
	if (z == 0)
	{
		for (int j = 0; j < getLineSize(); j++)
		{
			for (int t = 0; t < getLineSize(); t++)
			{
				for (int i = getLineSize() - 1; i >= 0; i--)
				{
					int rotor = Object[i][j];
					Object[i][j] = Object[j][t];
					Object[j][t] = rotor;
				}
			}
		}
	}
	else if (z == 3)
	{
		for (int j = 0; j < getSquareSize(); j++)
		{
			for (int t = 0; t < getSquareSize(); t++)
			{
				for (int i = getSquareSize() - 1; i >= 0; i--)
				{
					int rotor = Object[i][j];
					Object[i][j] = Object[j][t];
					Object[j][t] = rotor;
				}
			}
		}
	}
	else
	{
		for (int j = 0; j < getOtherSize(); j++)
		{
			for (int t = 0; t < getOtherSize(); t++)
			{
				for (int i = getOtherSize() - 1; i >= 0; i--)
				{
					int rotor = Object[i][j];
					Object[i][j] = Object[j][t];
					Object[j][t] = rotor;
				}
			}
		}
	}
}
