#ifndef H_Figura
#define H_Figura

class Figura
{
private:
	int** Object;

public:
	virtual int** Randomizer(int z);
	virtual int** Rotation(int z, int** Object);
};
#endif