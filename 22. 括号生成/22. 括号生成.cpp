// 22. 括号生成.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
#include <iostream>
#include<string>
#include<vector>
using namespace std;
//递归实现，当右括号数大于左括号数就可以添加右括号
//左括号数不为0就可以添加左括号
void para(int left, int right, string s, vector<string> &vs)
{
	if (left == 0 && right == 0)
	{
		vs.push_back(s);
		return;
	}
	if (left > 0)
	{
		s += "(";
		para(left - 1, right, s, vs);
		s.erase(s.size() - 1, 1);
	}
	if (right > 0&&right>left)
	{
		s += ")";
		para(left, right - 1, s, vs);
	}
}
vector<string> generateParenthesis(int n) 
{
	vector<string> vs;
	string s="";
	para(n, n, s, vs);
	return vs;
}
int main()
{
	vector<string> vs=generateParenthesis(3);
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
