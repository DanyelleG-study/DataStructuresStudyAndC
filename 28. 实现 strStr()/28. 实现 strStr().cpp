// 28. 实现 strStr().cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//实现 strStr() 函数。
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  - 1 。
#include <iostream>
#include<string>
using namespace std;
int strStr(string haystack, string needle) 
{
	if (haystack.compare(needle) == 0 || needle.compare("") == 0)
		return 0;
	if (haystack.compare("") == 0)
		return -1;
	for (int i = 0; i < haystack.length() - needle.length(); i++)
	{
		if (haystack.substr(i, needle.length()).compare(needle) == 0)
			return i;
	}
	return -1;
}
int main()
{
	int i=strStr("", "a");
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
