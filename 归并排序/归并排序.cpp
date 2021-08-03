// 归并排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
void merge(int *arrs, int begin, int mid, int end, int *temp)
{
	int i = begin;
	int j = mid + 1;
	int t = 0;
	while (i <= mid && j <= end)
	{
		if (arrs[i] <= arrs[j])
		{
			temp[t++] = arrs[i++];
		}
		else
		{
			temp[t++] = arrs[j++];
		}
	}
	while (j <= end)
	{
		temp[t++] = arrs[j++];
	}
	while (i <= mid)
	{
		temp[t++] = arrs[i++];
	}
	t = 0;
	while (begin<=end)
	{
		arrs[begin++] = temp[t++];
	}
}
void sort(int* arrs,int begin, int end, int* temp)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		sort(arrs, begin, mid, temp);
		sort(arrs, mid + 1, end, temp);
		merge(arrs, begin, mid, end, temp);
	}
}
int main()
{
	int arrs[] = { 9,8,7,6,5,4,3,2,1 };
	int temp[9];
	sort(arrs, 0, 8, temp);
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
