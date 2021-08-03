// 6用栈求解汉诺塔问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
//传统汉诺塔实现思路:
void hanoi(int num, char from, char to, char aux)
{
	if (num == 1)
		cout << num <<"从" << from << "移动到" << aux<<endl;
	else
	{
		hanoi(num - 1, from, aux, to);
		cout << num << "从" << from << "移动到" << aux << endl;
		hanoi(num - 1, to, from  , aux);
	}
}
void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
{
	if (A.size() == 1)
	{
		int temp = A.front();
		A.pop_back();
		C.push_back(temp);
	}
	else
	{
	}
}
//汉诺塔的要求：不能直接从最左侧的塔移动到最右侧，也不能从最右侧直接移动到最左侧，所有的移动必须通过中间

int main()
{
	hanoi(3, 'A', 'B', 'C');
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
