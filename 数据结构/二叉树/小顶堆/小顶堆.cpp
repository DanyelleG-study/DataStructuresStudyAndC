// 小顶堆.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<assert.h>
using namespace std;
const int maxsize = 50;
template <typename T> class MinHeap
{
public:
	MinHeap(int sz = maxsize)
	{
		maxHeapSize=sz > maxsize ? sz:maxsize;
		heap = new T[maxHeapSize];
		currentSize = 0;
		assert(heap);
	}
	MinHeap(T arr[], int n)
	{
		maxHeapSize = n > maxsize ? n : maxsize;
		heap = new T[maxHeapSize];
		assert(heap);
		for (int i = 0; i < n; i++)
		{
			heap[i] = arr[i];
		}
		currentSize = n;
		int curr = (n - 2) / 2;
		while (curr>=0)
		{
			siftDown(curr, n - 1);
			curr--;
		}

	}
	~MinHeap()
	{
		delete[]heap;
		currentSize = 0;
		maxHeapSize = 0;
	}
	void printfMaxHeap()
	{
		for (int i = 0; i < currentSize; i++)
		{
			cout << heap[i];
		}
		cout << endl;
	}
	bool Insert(const T &x);
	bool RemoveMin(T &x);
private:
	T *heap;						//存放最小堆中元素的数组
	int currentSize;				//最小堆中当前元素个数
	int maxHeapSize;				//最小堆最多允许元素个数
	void siftDown(int start, int m);//从start到m下滑调整成为最小堆
	void siftUp(int start);			//从start到0上滑调整成为最小堆
};
template<typename T>
bool MinHeap<T>::Insert(const T &x)
{
	if (currentSize == maxHeapSize){	//堆满	
		cerr << "Heap Full" << endl;
		return false;
	}
	heap[currentSize] = x;	//插入
	siftUp(currentSize);	//向上调整
	currentSize++;			//堆计数加1
	return true;
}
template<typename T>
bool MinHeap<T>::RemoveMin(T &x)
{
	if (!currentSize) {	//堆空, 返回false	
		cout << "Heap empty" << endl;
		return false;
	}
	x = heap[0];		// 返回最小元素
	heap[0] = heap[currentSize - 1];	//最后元素填补到根结点
	currentSize--;
	siftDown(0, currentSize - 1);		//自上向下调整为堆
	return true;
}
template<typename T>
void MinHeap<T>::siftDown(int start, int m)
{
	int i = start;
	int j = start * 2 + 1;
	T temp = heap[i];
	while (j <= m)
	{
		if (j < m&&heap[j + 1] < heap[j])
		{
			j = j + 1;
		}
		if (heap[j] > temp)
			break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}
template<typename T>
void MinHeap<T>::siftUp(int start)
{
	int i = start;
	int j = (start - 1) / 2;//父节点
	T temp = heap[i];
	while (j>0)
	{
		if (heap[j] > temp)
		{
			heap[i] = heap[j];
			i = j;
			j = (j - 1) / 2;
		}
	}
	heap[i] = temp;
}
int main()
{
	int a[] = { 9,4,8,3,5,1,2,6,7,0 };
	MinHeap<int> test(a, 10);
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
