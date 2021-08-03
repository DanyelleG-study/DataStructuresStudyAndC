// 堆排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//堆排序：先将L中的所有的有子节点的树构建成大顶堆
//1和i交换，再调整堆结构
void heapAdjust(SqList &l, int s, int m)
{
	int temp, j;
	temp = l.r[s];
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m&&l.r[j] < l.r[j + 1])
			++j;
		if (temp >= l.r[j])
			break;
		l.r[s] = l.r[j];
		s = j;
	}
	l.r[s] = temp;
}
void heapSort(SqList &l)
{
	for (int i = l.length / 2; i > 0; i--)
		heapAdjust(l, i, l.length);
	for (int i = l.length; i > 1; i--)
	{
		swap(l, 1, i);
 	}

}
void adjust(vector<int> &v,int legth, int i)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int mid = i;
	if (left<legth&& v.at(left) > v.at(mid))
		mid = left;
	if (right<legth && v.at(right) > v.at(mid))
		mid = right;
	if (mid != i)
	{
		int temp = v.at(mid);
		v.at(mid) = v.at(i);
		v.at(i) = temp;
		adjust(v, legth, mid);
	}
}
void heapSort(vector<int> &v)
{
	for (int i = v.size() / 2 - 1; i >= 0; i--)
	{
		adjust(v,v.size(), i);
	}
	for (int i = v.size() - 1; i >= 1; i--)
	{
		int temp = v.at(i);
		v.at(i) = v.at(0);
		v.at(0) = temp;
		adjust(v,i,0);
	}
}
int main()
{
	vector<int> arr = { 8, 1, 14, 3, 21, 5, 7, 10 };
	heapSort(arr);
	/*SqList l{ {0,50,10,90,30,70,40,80,60,20},10 };
   
	heapSort(l);*/
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
