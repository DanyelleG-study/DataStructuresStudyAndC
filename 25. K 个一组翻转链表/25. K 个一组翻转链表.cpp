// 25. K 个一组翻转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。
//
//如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//进阶：
//
//你可以设计一个只使用常数额外空间的算法来解决此问题吗？
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseKGroup(ListNode* head, int k)
{
	ListNode *p = head;
	int length = 0;
	while (p)
	{
		length++;
		p = p->next;
	}//查找链表的总节点数
	ListNode *newhead = new ListNode(0);
	ListNode *h = newhead;
	ListNode *l = newhead;
	p = head;
	for (int i = 0, cout = 0; i < length - length % k; i++)
	{
		if (cout == k)
		{
			h = l;
			cout = 0;
		}
		ListNode *m = p;
		p = p->next;
		m->next = h->next;
		h->next = m;
		if (cout == 0)
			l = l->next;
		cout++;
	}
	l->next = p;
	p = newhead->next;
	delete newhead;
	newhead = nullptr;
	return p;
}
int main()
{
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	p->next = new ListNode(2);
	p = p->next; 
	p->next = new ListNode(3);
	p = p->next; 
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	ListNode *n= reverseKGroup(head, 2);
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
