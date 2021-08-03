// 访问者模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
class Person;
class Action
{
public:
	virtual void getManConclusion(Person* p) = 0;
	virtual void getWomanConclusion(Person* p) = 0;
};
class Person
{
public:
	virtual void accept(Action *a) = 0;
};
class Man :public Person
{
	virtual void accept(Action *a)
	{
		a->getManConclusion(this);
	}
};
class Woman :public Person
{
	virtual void accept(Action *a)
	{
		a->getWomanConclusion(this);
	}
};
class Success :public Action
{
public:
	virtual void getManConclusion(Person* p)
	{
		cout << "男人成功" << endl;
	}
	virtual void getWomanConclusion(Person* p)
	{
		cout << "女人成功" << endl;

	}
};
class Failing :public Action
{
public:
	virtual void getManConclusion(Person* p)
	{
		cout << "男人失败" << endl;
	}
	virtual void getWomanConclusion(Person* p)
	{
		cout << "女人失败" << endl;

	}
};
class ObjectStructure
{
public:
	void Attach(Person *p)
	{
		elements.push_back(p);
	}
	void Detach(Person *p)
	{
		auto f = find(elements.begin(), elements.end(), p);
		if (f != elements.end())
			elements.erase(f);
	}
	void Display(Action *a)
	{
		for (int i = 0; i < elements.size(); i++)
		{
			elements[i]->accept(a);
		}
	}
private:
	vector<Person*> elements;
};
int main()
{
	ObjectStructure *o = new ObjectStructure();
	o->Attach(new Man());
	o->Attach(new Woman());
	Success *v1 = new Success();
	o->Display(v1);
	Failing *v2 = new Failing();
	o->Display(v2);
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
