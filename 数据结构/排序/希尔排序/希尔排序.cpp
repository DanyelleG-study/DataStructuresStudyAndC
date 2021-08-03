// 希尔排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
#define maxsize 100
struct SqList
{
	int r[maxsize];
	int length;
};
void ShellSort(SqList &l)
{
	int i, j;
	int increment = l.length;
	do
	{
		increment = increment / 3 + 1;
		for (i = increment + 1; i <= l.length; i++)
		{
			if (l.r[i] < l.r[i - increment])
			{
				l.r[0] = l.r[i];
				for (j = i - increment; j > 0 && l.r[0] < l.r[j]; j -= increment)
					l.r[j + increment] = l.r[j];
				l.r[j + increment] = l.r[0];

			}
		}
	} while (increment > 1);
}
void ShellSort(vector<int> &v)
{
	int d = v.size() / 2;
	while (d>=1)
	{
		for (int i = d; i < v.size(); i++)
		{
			int j = i - d;
			int temp = v.at(i);
			while (j>=0&&v.at(j)>temp)
			{
				v.at(j + d) = v.at(j);
				j -= d;
			}
			if (j != i - d)
				v.at(j + d) = temp;
		}
		d /= 2;
	}
}
int main()
{
	vector<int> l({ 0,9,1,5,8,3,7,4,6,2 });
	ShellSort(l);

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
