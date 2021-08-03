// 大顶堆.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<assert.h>
using namespace std;
const int DefaultSize = 50;
template<typename T> class MaxHeap
{
public:
	MaxHeap<T>()
	{
		heap = new T[DefaultSize];
		assert(heap);
		currentSize = 0;
	}
	MaxHeap<T>(int sz)
	{
		maxHeapSize=sz < DefaultSize ? sz : DefaultSize;
		heap = new T[maxHeapSize];
		assert(heap);
		currentSize = 0;
	}
	~MaxHeap<T>()
	{
		delete[]heap;
		currentSize = 0;
	}
	MaxHeap(T arr[], int n)//创建后构建大顶堆
	{
		maxHeapSize = n < DefaultSize ? n: DefaultSize;
		heap = new T[maxHeapSize];
		assert(heap);
		for (int i = 0; i < maxHeapSize; i++)
			heap[i] = arr[i];
		int current = (n - 2) / 2;
		while (current>=0)
		{
			siftDown(current, n - 1);
			current--;
		}
	}
	void printfMaxHeap()
	{
		for (int i = 0; i < maxHeapSize; i++)
		{
			cout << heap[i];
		}
		cout << endl;
	}
	bool RemoveMax(T &x)//删除最大值
	{
		if (!currentSize)
		{
			cout << "大顶堆为空" << endl;
			return false;
		}
		x = heap[0];
		heap[0] = heap[currentSize - 1];
		currentSize--;
		siftDown(0, currentSize-1);
		return true;
	}
	bool Insert(const T &x) {
		if (currentSize == maxHeapSize) {	//堆满	
			cout << "大顶堆满" << endl;
			return false;
		}
		heap[currentSize] = x;	//插入
		siftUp(currentSize);	//向上调整
		currentSize++;			//堆计数加1
		return true;
	}
private:
	T *heap;
	int currentSize;
	int maxHeapSize;
	void siftUp(int start)
	{
		int i = start;
		int j = (start - 1) / 2;
		T temp = heap[i];
		while (j>0)
		{
			if (heap[j] >= temp)
				break;
			else
			{
				heap[i] = heap[j];
				i = j;
				j = (j - 1) / 2;
			}
		}
		heap[i] = temp;
	}
	void siftDown(int strat, int m)
	{
		int i = strat;//该节点
		int j = i * 2 + 1;//左子树
		T temp = heap[strat];
		while (j<=m)
		{
			if (j < m&&heap[j] < heap[j + 1])
				j++;
			if (temp > heap[j])
				break;
			else
			{
				heap[i] = heap[j];
				i = j;
				j = j * 2 + 1;
			}
		}
		heap[i] = temp;
	}
};
int main()
{
	int a[] = {9,4,8,3,5,1,2,6,7,0};
	MaxHeap<int> test(a,10);
	test.printfMaxHeap();
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
