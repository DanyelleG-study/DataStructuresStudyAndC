// 10.斐波那契数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
//递归实现思路：
int fiebonacci(int n)
{
	if (n == 1)
		return 1;
	else if (n == 0)
		return 0;
	else
	{
		return fiebonacci(n - 1) + fiebonacci(n - 2);
	}
} 
//循环实现思路：
int fiebonacci1(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	int one = 1;
	int two = 0;
	int res = 0;
	for (int i = 2; i <= n; i++)
	{
		res = one + two;
		two = one;
		one = res;
	}
	return res;
}
int main()
{
	std::cout << fiebonacci(10) << std::endl;
	std::cout << fiebonacci1(10) << std::endl;
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
