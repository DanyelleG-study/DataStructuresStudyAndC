// 9. 回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
#include <iostream>
#include<string>
using namespace std;
bool isPalindrome(int x) {
	string s(to_string(x));
	string::iterator sitr = s.begin();
	string::reverse_iterator sritr = s.rbegin();
	while (sitr!=s.end()&&sritr!=s.rend())
	{
		if (*sitr != *sritr)
			return false;
		sitr++;
		sritr++;
	}
	return true;

}
int main()
{
	bool is= isPalindrome(-121);
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
