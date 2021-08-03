// 迭代器模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
template<class Item>
class Iterator
{
public:
	Iterator() {};
	virtual ~Iterator() {};

	virtual void first() = 0;
	virtual void next() = 0;
	virtual Item *curItem() = 0;
	virtual bool isDone() = 0;
};
template<class Item>
class Aggregate
{
public:
	Aggregate()
	{
	}
	virtual ~Aggregate()
	{
	}
	virtual void pushData(Item item) = 0;
	virtual Iterator<Item>* createIterator() = 0;
	virtual Item& operator[](int index) = 0;
	virtual int getSize() = 0;
};

template<class Item>
class ConcreteIterator :public Iterator<Item>
{
public:
	ConcreteIterator(Aggregate<Item> *a)
		:aggr(a), cur(0)
	{
	}
	virtual ~ConcreteIterator()
	{
	}
	virtual void first()
	{
		cur = 0;
	}
	virtual void next()
	{
		if (cur < aggr->getSize())
			cur++;
	}
	virtual Item *curItem()
	{
		if (cur < aggr->getSize())
			return &aggr->operator[](cur);
		else
			return nullptr;
	}
	virtual bool isDone()
	{
		return cur >= aggr->getSize();
	}
private:
	Aggregate<Item> *aggr;
	int cur;
};
template<class Item>
class ConcreteAggregate :public Aggregate< Item>
{
public:
	ConcreteAggregate()
	{
	}
	virtual ~ConcreteAggregate()
	{
	}
	virtual void pushData(Item item)
	{
		data.push_back(item);
	}
	virtual Iterator<Item>* createIterator()
	{
		return new ConcreteIterator<Item>(this);
	}
	virtual Item& operator[](int index)
	{
		return data.at(index);
	}
	virtual int getSize()
	{
		return data.end() - data.begin();
	}
private:
	vector<Item> data;
};


int main()
{
	Aggregate<int> * aggr = new ConcreteAggregate<int>();
	aggr->pushData(3);
	aggr->pushData(2);
	aggr->pushData(1);
	Iterator<int> * it = aggr->createIterator();

	for (it->first(); !it->isDone(); it->next())
	{
		std::cout << *it->curItem() << std::endl;
	}
	delete it;
	delete aggr;
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
