// 冒泡排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#define maxsize 100
using namespace std;
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
//冒泡排序的思想：每次将最小的元素置于最前端,时间复杂度n平方（最简单的冒泡排序）
//每回第i个元素和后面的的每一个元素比较如果大于比较元素则换位置
void BubbleSort(SqList &l)
{
	for (int i = 0; i < l.length; i++)
	{
		for (int j = i + 1; j < l.length; j++)
		{
			if (l.r[i] > l.r[j])
				swap(l, i, j);
		}
	}
}
//冒泡排序思想：两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为止
void BubbleSort1(SqList &l)
{
	for (int i = 0; i < l.length; i++)
	{
		for (int j = l.length - 1; j >= i; j--)
		{
			if (l.r[j] > l.r[j + 1])
				swap(l, j, j + 1);
		}
	}
}
//冒泡排序优化,flag判断
void BubbleSort2(SqList &l)
{
	bool flag = true;
	for (int i = 0; i < l.length&&flag; i++)
	{
		flag = false;
		for (int j = l.length - 1; j >= i; j--)
		{
			if (l.r[j] > l.r[j + 1])
			{
				swap(l, j, j + 1);
				flag = true;
			}
		}
	}
}
//冒泡排序思想：
void BubbleSort(vector<int> &v)
{
	bool flag = true;
	for (int i = 0; i < v.size() && flag; i++)
	{
		flag = false;
		for (int j = v.size() - 2; j >= i; j--)
		{
			if (v.at(j) > v.at(j+1))
			{
				int temp = v.at(j + 1);
				v.at(j + 1) = v.at(j);
				v.at(j) = temp;
				flag = true;
			}
		}
	}
}
int main()
{
	vector<int> v({1,3,2,4,5});
	BubbleSort(v);
	//SqList l;
	//for (int i = 55,j=0; i >= 0; i--,j++)
	//{
	//	l.r[j] = i;
	//}
	//l.length = 56;
	////BubbleSort(l);
	////BubbleSort1(l);
	//BubbleSort2(l);
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
