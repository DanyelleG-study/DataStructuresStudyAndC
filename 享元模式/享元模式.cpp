// 享元模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<map>
using namespace std;
class User
{
public:
	User(string n) :name(n)
	{

	}
	~User()
	{

	}
	string getName()
	{
		return name;
	}
private:
	string name;
};
class WebSite
{
public:
	virtual void coutUser(User* user)=0;
};
class  ConcreteWebSite:public WebSite
{
public:
	ConcreteWebSite(string n):name(n)
	{

	}
	virtual void coutUser(User* user)
	{

		cout <<name.c_str()<< user->getName() << endl;
	}
private:
	string name;
};
class WebFactory
{
public:
	WebSite *getWebSite(string key)
	{
		auto iter = sites.find(key);
		if (iter == sites.end())
			sites.insert(pair<string, WebSite*>(key, new ConcreteWebSite(key)));
		return sites[key];
	}
	int size()
	{
		return sites.size();
	}
private:
	map<string, WebSite*> sites;
};
int main()
{
	WebFactory *f = new WebFactory();
	WebSite *fx = f->getWebSite("产品展示");
	fx->coutUser(new User("guo"));
	WebSite *fx1 = f->getWebSite("产品展示");
	fx1->coutUser(new User("guo1"));
	WebSite *fx3 = f->getWebSite("博客");
	fx3->coutUser(new User("guo"));
	WebSite *fx4 = f->getWebSite("博客");
	fx4->coutUser(new User("guo1"));
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
