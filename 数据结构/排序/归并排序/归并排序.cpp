// 归并排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l < m - i; l++)
			TR[k + 1] = SR[i + 1];
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + 1];
	}
}
void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[maxsize + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);

	}
}
void MergeSort(SqList &l)
{
	MSort(l.r, l.r, 1, l.length);
}
void merge(vector<int> &v, int left, int mid, int right)
{
	vector<int> temp(v.size());
	int i = left;
	int j = mid + 1;
	int m = 0;
	while (i<mid&&j<right)
	{
		if (v.at(i) < v.at(j))
		{
			temp.at(m) = v.at(i);
			i++;
		}
		else
		{
			temp.at(m) = v.at(j);
			j++;
		}
		m++;
	}
	while (i<mid)
	{
		temp.at(m) = v.at(i);
		m++;
		i++;
	}
	while (j<right)
	{
		temp.at(m) = v.at(j);
		m++;
		j++;
	}
	v = temp;
}
void MSort(vector<int> &v,int left,int right)
{
	if (left >= right)
		return;
	int mid = v.size() / 2;
	MSort(v, left, mid);
	MSort(v, mid + 1, right);
	merge(v, left, mid, right);
}
int main()
{
	vector<int> v({ 0,10,30,50,70,90,20,40,60,80 });
	MSort(v, 0, v.size());
	//SqList l = { {0,10,30,50,70,90,20,40,60,80},11 };
	//MergeSort(l);
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
