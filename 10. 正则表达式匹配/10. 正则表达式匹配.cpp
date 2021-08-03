// 10. 正则表达式匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
//所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串
#include "pch.h"
#include <iostream>
#include<string>
#include<stack>
using namespace std;
bool isMatch(string s, string p) 
{
	stack<char> com;
	int is = 0;
	for (int ip = 0; ip<p.size();)
	{
		if (p[ip] == '.')
		{
			com.push(s[is]);
			is++;
			ip++;
		}
		else if (p[ip] == '*')
		{
			if (com.size() <= 0)
				return false;
			char c=com.top();
			while (is<s.size()&&s[is]==c)//可以是0,1,2个
			{
				is++;
			}
			com.pop();
			ip++;
		}
		else
		{
			com.push(p[ip]);
			ip++;
			is++;
		}
	}
	if (is == s.size())
		return true;
	else
		return false;
}
int main()
{
	bool b=isMatch("aab", "c*a*b");
    std::cout << "Hello World!\n"; 
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
