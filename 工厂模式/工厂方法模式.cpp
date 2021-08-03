#include<iostream>
#include"gcms.h"
using namespace std;
class IFactory
{
public:
	virtual Operation* CreatOperation()=0;
};
class  AddFactory:public IFactory
{
public:
	Operation* CreatOperation()
	{
		return new OperationAdd();
	}
};
class  SubFactory :public IFactory
{
public:
	Operation* CreatOperation()
	{
		return new OperationSub();
	}
};
int main()
{
	IFactory *fa = new AddFactory();
	Operation*op=fa->CreatOperation();
	op->setNumber(2, 3);
	double resu = op->GetResult();
	std::cout << "Hello World!\n";
}