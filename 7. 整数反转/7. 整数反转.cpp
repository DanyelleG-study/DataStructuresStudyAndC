// 7. 整数反转.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stack>
#include<string>
//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//
//如果反转后整数超过 32 位的有符号整数的范围 [−231, 231 − 1] ，就返回 0。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reverse-integer
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
using namespace std;

int reverse(int x) {
	int res = 0;
	while (x!=0)
	{
		if (res<INT_MIN / 10 || res>INT_MAX / 10)
			return 0;
		int digit = x % 10;
		x /= 10;
		res = res * 10 + digit;
	}
	return res;
}
int main()
{
	int test = INT_MAX;
	string s(to_string(test + 1));
	int test1 = test + 1;
	int x = reverse(-2147483412);
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
