// 12. 整数转罗马数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace  std;
//思路：
string intToRoman(int num) {
	string sout="";
	map<int, string> compareMap({ {4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"},{1,"I"},
		{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"} });
	while (num>0)
	{
		map<int, string>::reverse_iterator reIter = compareMap.rbegin();
		while (num< reIter->first&&reIter!=compareMap.rend())
		{
			reIter++;
		}
		sout += reIter->second;
		num -= reIter->first;
	}
	return sout;
}
int main()
{
	string out=intToRoman(58);
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
