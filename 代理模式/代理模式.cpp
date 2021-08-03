// 代理模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;
class Givegift
{
public:
	virtual void giveDolls()=0;
	virtual void giveFlowers()=0;
	virtual void giveChocolate()=0;
};
class Pursuit :public Givegift
{
public:
	Pursuit(string n) :name(n)
	{

	}
	virtual void giveDolls()
	{
		cout << name.c_str() << ",giveDolls" << endl;
	}
	virtual void giveFlowers()
	{
		cout << name.c_str() << ",giveFlowers" << endl;

	}
	virtual void giveChocolate()
	{
		cout << name.c_str() << ",giveChocolate" << endl;

	}
private:
	string name;
};
class Proxy :public Givegift
{
public:
	Proxy(string name)
	{
		gg = new Pursuit(name);
	}
	virtual void giveDolls()
	{
		gg->giveDolls();
	}
	virtual void giveFlowers()
	{
		gg->giveFlowers();
	}
	virtual void giveChocolate()
	{
		gg->giveChocolate();
	}
private:
	Pursuit *gg;
};
int main()
{
	Proxy *p = new Proxy("lijiaojiao");
	p->giveChocolate();
	p->giveDolls();
	p->giveFlowers();
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
