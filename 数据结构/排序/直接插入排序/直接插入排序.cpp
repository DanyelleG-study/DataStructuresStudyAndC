// 直接插入排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//直接插入排序：将一个记录插入到已经排好序的有序表中
//0号位为哨兵位
void InsertSort(SqList &l)
{
	for (int i = 2; i <l.length; i++)
	{
		if (l.r[i] < l.r[i - 1])
		{
			l.r[0] = l.r[i];
			int j;
			for (j = i - 1; l.r[j] > l.r[0]; j--)
			{
				l.r[j + 1] = l.r[j];
			}
			l.r[j + 1] = l.r[0];
		}
	}
}
void InsertSort(vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int temp = v.at(i);
		int j = i;
		while (j>0&&v.at(j-1)>temp)
		{
			v.at(j) = v.at(j - 1);
			j--;
		}
		v.at(j) = temp;
	}

}
int main()
{
	/*SqList l;
	for (int i = 1; i < 55; i++)
	{
		l.r[i] = 55-i;
	}
	l.length = 55;
	InsertSort(l);*/
	vector<int> v({ 3,2,1,5,4 });
	InsertSort(v);
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
