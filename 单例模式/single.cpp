#include "single.h"
single * single::sing = new single();
single::single()
{

}
single::~single()
{

}
single * single::getsingle()
{
	//static single s;
	//return &s;
	return sing;
}

void single::deleteSingle()
{
	if (sing != nullptr)
	{
		delete sing;
		sing = nullptr;
	}
}
