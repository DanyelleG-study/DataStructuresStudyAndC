// 中介者模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Country;
class UnitedNations
{
public:
	virtual void declare(string message, Country* colleage) = 0;
};
class Country
{
public:
	Country(UnitedNations *n):nation(n)
	{

	}
protected:
	UnitedNations *nation;
};
class USA :public Country
{
public:
	USA(UnitedNations *n)
		:Country(n)
	{

	}
	void declare(string message)
	{
		nation->declare(message, this);
	}
	void getMessage(string message)
	{
		cout << message.c_str() << endl;
	}
};
class Iraq :public Country
{
public:
	Iraq(UnitedNations *n)
		:Country(n)
	{

	}
	void declare(string message)
	{
		nation->declare(message, this);
	}
	void getMessage(string message)
	{
		cout << message.c_str() << endl;
	}
};
class peace :public UnitedNations
{
public:
	void setUSA(USA *u)
	{
		usa = u;
	}
	void setIraq(Iraq *i)
	{
		iraq = i;
	}
	virtual void declare(string message, Country* colleage)
	{
		if (colleage == usa)
			usa->getMessage(message);
		else
			iraq->getMessage(message);
	}
private:
	USA *usa;
	Iraq *iraq;
};
int main()
{
	peace *p = new peace();
	USA *u = new USA(p);
	Iraq *i = new Iraq(p);
	u->declare("你说什么PP话");
	i->declare("说你咋地");
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
