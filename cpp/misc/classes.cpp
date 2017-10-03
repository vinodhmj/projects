#include "stdafx.h"
#include "pointers.h"

class CDate
{
public:
	CDate(int d=0, int m = 0, int y = 0)
	{
	}

	~CDate()
	{}
};

void classes()
{

	 // Destructors for local variables are executed in reverse order of their construction.


	//Assignment can be optimized in some cases, but the general strategy for an assignment operator
//is simple: protect against self-assignment, delete old elements, initialize, and copy in new elements.
//Usually every nonstatic member must be copied 
}
