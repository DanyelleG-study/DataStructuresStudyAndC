// 剑指 Offer 30. 包含min函数的栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stack>
using namespace std;
//请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。
//思路：1.取一个栈用来存储数据，另一个栈用来存取栈中最小值
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		if (min.empty())
			min.push(x);
		else
		{
			if (min.top() > x)
				min.push(x);
		}
	}

	void pop() {
		if (data.empty())
			return;
		if (!min.empty() && data.top() == min.top())
		{
			min.pop();
		}
		data.pop();
	}

	int top() {
		if (data.empty())
		{
			cerr << "没有数据.\n";
			exit(1);
		}

		return data.top();
	}

	int getMin() {
		if (!min.empty())
		{
			int x = min.top();
			min.pop();
			return x;
		}
		else
		{
			cerr << "没有数据.\n";
			exit(1);
		}
	}
private:
	stack<int> data;
	stack<int> min;
};

int main()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-1);
	minStack.getMin();
	minStack.top();
	minStack.pop();
	minStack.getMin();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
