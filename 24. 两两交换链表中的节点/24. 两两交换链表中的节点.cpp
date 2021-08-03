// 24. 两两交换链表中的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* swapPairs(ListNode* head) 
{
	ListNode *p = head;
	int length = 0;
	while (p)
	{
		length++;
		p = p->next;
	}//计算链表长度
	ListNode *newhead = new ListNode(0);
	ListNode *h = newhead;
	ListNode *l = newhead;
	p = head;
	for (int i = 0,temp=0; i < length - length % 2; i++,temp++)
	{
		if (temp == 2)
		{
			h = l;
			temp = 0;
		}
		ListNode *m = p;
		p = p->next;
		m->next = h->next;
		h->next = m;
		if (temp == 0)
			l = l->next;
	}
	l->next = p;
	p = newhead->next;
	delete newhead;
	newhead = NULL;
	return p;
}
int main()
{
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
