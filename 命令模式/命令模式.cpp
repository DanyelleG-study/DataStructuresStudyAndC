// 命令模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
class BarbecueMaster
{
public:
	void makeMutton()
	{
		cout << "烤羊腿" << endl;
	}
	void makeChiken()
	{
		cout << "烤羊肉" << endl;
	}
};
class command
{
public:
	command(BarbecueMaster *b)
	{
		master = b;
	}
	virtual void show() = 0;
protected:
	BarbecueMaster *master;
};
class commandChiken :public command
{
public:
	commandChiken(BarbecueMaster *b)
		:command(b)
	{

	}
	virtual void show()
	{
		master->makeChiken();
	}
};
class waiter
{
public:
	~waiter()
	{
		for (int i = 0; i < vc.size(); i++)
		{
			delete vc[i];
		}
		vc.clear();
	}
	void add(command *c)
	{
		vc.push_back(c);
	}
	void dele(command *c)
	{
		vector<command *>::iterator iter= find(vc.begin(), vc.end(), c);
		if (iter != vc.end())
			vc.erase(iter);
	}
	void show()
	{
		for (int i = 0; i < vc.size(); i++)
			vc[i]->show();
	}
private:
	vector<command*> vc;
};
class commandMutton :public command
{
public:
	commandMutton(BarbecueMaster *b)
		:command(b)
	{

	}
	virtual void show()
	{
		master->makeMutton();
	}
};
int main()
{
	waiter *w = new waiter();
	BarbecueMaster *pmaster = new BarbecueMaster();
	w->add(new commandChiken(pmaster));
	w->add(new commandMutton(pmaster));
	w->add(new commandChiken(pmaster));
	w->show();
	delete w;
	delete pmaster;
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
