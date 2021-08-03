// 快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
int Partiton(int* data, int begin, int end)
{
	int temp = data[begin];
	while (begin<end)
	{
		while (begin<end&&data[end]>=temp)
		{
			end--;
		}
		data[begin] = data[end];
		while (begin<end&&data[begin]<=temp)
		{
			begin++;
		}
		data[end] = data[begin];
	}
	data[begin] = temp;
	return begin;
}
void quickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int index = Partiton(arr, low, high);
		if (index > low)
			quickSort(arr, low, index);
		if (index < high)
			quickSort(arr, index + 1, high);
	}

}
int main()
{
	int a[] = { 49, 38, 65, 97, 23, 22, 76, 1, 5, 8, 2, 0, -1, 22 };
	int low = 0;
	int high = 13;
	quickSort(a, low, high);
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
