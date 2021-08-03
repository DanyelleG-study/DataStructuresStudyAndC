// 23. 合并K个升序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给你一个链表数组，每个链表都已经按升序排列。
//
//请你将所有链表合并到一个升序链表中，返回合并后的链表。
#include <iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insert(ListNode *h, ListNode *p)
{
	ListNode *temp = h;
	while (temp)
	{
		if (temp->val <= p->val&&temp->next&&temp->next->val > p->val)
		{
			p->next = temp->next;
			temp->next = p;
			return;
		}
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}

	temp->next = p;
}
ListNode* mergeKLists(vector<ListNode*>& lists)
{
	if (lists.size() == 0)
		return nullptr;
	ListNode *head = new ListNode();
	head->next=lists[0];
	for (int i = 1; i < lists.size(); i++)
	{
		ListNode *p = lists[i];
		while (p)
		{
			ListNode *m = p;
			p = p->next;
			insert(head, m);
		}
	}
	return head;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	vector<ListNode *> vl;
	vl.push_back(head);
	head = new ListNode(1);
	p = head;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	vl.push_back(head);
	head = new ListNode(2);
	p = head;
	p->next = new ListNode(6);
	p = p->next;
	vl.push_back(head);
	p = mergeKLists(vl);
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
