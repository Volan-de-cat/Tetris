#ifndef H_Graphics
#define H_Graphics

#include "BaseApp.h"

class Graphics : public BaseApp
{
	typedef BaseApp Parent;

//private:

public:
	virtual void Field(int xSize, int ySize);
	virtual void Start(int** Object, int z);

};

#endif
