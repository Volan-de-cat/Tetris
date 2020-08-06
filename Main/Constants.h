#ifndef H_CONSTANTS
#define H_CONSTANTS

#include <windows.h>
#include <string>

inline const string getScore()
{
	return "     Score:  ";
};

inline const char getBorder()
{
	return '@';
};

inline const char getObject()
{
	return '$';
};
 
inline const char getEmpty()
{
	return ' ';
};

inline const int getInnerBorder()
{
	return 23;
};

inline const int getLine()
{
	return 15;
};

inline const int getRotationKey()
{
	return 32;
};

inline const int getDownKey()
{
	return 80;
};

inline constexpr int getLineSize()
{
	return 4;
};

inline constexpr int getSquareSize()
{
	return 2;
};

inline constexpr int getOtherSize()
{
	return 3;
};

inline const int getLeftKey()
{
	return 75;
};

inline const int getStartPozition()
{
	return 10;
};

inline const int getNextPozition()
{
	return 20;
};

inline const int getRightKey()
{
	return 77;
};
#endif
