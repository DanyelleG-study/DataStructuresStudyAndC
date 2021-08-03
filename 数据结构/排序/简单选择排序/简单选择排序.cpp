// 简单选择排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
void swap(SqList &l, int i, int j)
{
	if (i < l.length&&j < l.length)
	{
		int temp = l.r[i];
		l.r[i] = l.r[j];
		l.r[j] = temp;
	}
}
//简单选择排序：第i个元素和后面的n-i+1个元素进行比较，并选出最小的元素进行交换位置
void selectSort(SqList &l)
{
	for (int i = 0; i < l.length; i++)
	{
		int min = i;
		for (int j = i + 1; j < l.length; j++)
		{
			if (l.r[min] > l.r[j])
				min = j;
		}
		if (i != min)
			swap(l, i, min);
	}
}
void selectSort(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		int min = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v.at(min) > v.at(j))
				min = j;
		}
		int temp = v.at(i);
		v.at(i) = v.at(min);
		v.at(min) = temp;
	}
}
int main()
{
	vector<int> v({1,3,2,6,5});
	selectSort(v);
	/*SqList l;
	for (int i = 55, j = 0; i >= 0; i--, j++)
	{
		l.r[j] = i;
	}
	l.length = 56;
	selectSort(l);*/
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
