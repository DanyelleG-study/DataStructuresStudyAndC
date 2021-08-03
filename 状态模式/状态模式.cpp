// 状态模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Context;
class State
{
public:
	virtual void Handle(Context* pContext) = 0;
	~State();
protected:
	State();
private:
};

class ConcreteStateA : public State
{
public:
	ConcreteStateA();
	~ConcreteStateA();
	virtual void Handle(Context* pContext);
protected:
private:
};

class ConcreteStateB : public State
{
public:
	ConcreteStateB();
	~ConcreteStateB();
	virtual void Handle(Context* pContext);
protected:
private:
};

class ConcreteStateC : public State
{
public:
	ConcreteStateC();
	~ConcreteStateC();
	virtual void Handle(Context* pContext);
protected:
private:
};

class Context
{
public:
	Context(State* pState);
	~Context();
	void Request();
	void ChangeState(State* pState);
protected:
private:
	State* _state;
};
State::State()
{}
State::~State()
{}
ConcreteStateA::ConcreteStateA()
{}
ConcreteStateA::~ConcreteStateA()
{}
//执行该状态的行为并改变状态
void ConcreteStateA::Handle(Context* pContext)
{
	cout << "ConcreteStateA" << endl;
	pContext->ChangeState(new ConcreteStateB());
}
ConcreteStateB::ConcreteStateB()
{}
ConcreteStateB::~ConcreteStateB()
{}
//执行该状态的行为并改变状态
void ConcreteStateB::Handle(Context* pContext)
{
	cout << "ConcreteStateB" << endl;
	pContext->ChangeState(new ConcreteStateC());
}
ConcreteStateC::ConcreteStateC()
{}
ConcreteStateC::~ConcreteStateC()
{}
//执行该状态的行为并改变状态
void ConcreteStateC::Handle(Context* pContext)
{
	cout << "ConcreteStateC" << endl;
	pContext->ChangeState(new ConcreteStateA());
}

//定义_state的初始状态
Context::Context(State* pState)
{
	this->_state = pState;
}
Context::~Context()
{}
//对请求做处理，并设置下一状态
void Context::Request()
{
	if (NULL != this->_state)
	{
		this->_state->Handle(this);
	}
}
//改变状态
void Context::ChangeState(State* pState)
{
	this->_state = pState;
}
int main()
{
	State* pState = new ConcreteStateA();
	Context* pContext = new Context(pState);
	pContext->Request();
	pContext->Request();
	pContext->Request();
	pContext->Request();
	pContext->Request();
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
