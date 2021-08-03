// 19. 删除链表的倒数第 N 个结点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode *temp = new ListNode(0, head);
	ListNode *p = head;
	ListNode *q = temp;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
	}
	while (p)
	{
		p = p->next;
		q = q->next;
	}
	ListNode *m = q->next;
	q->next = q->next->next;
	delete m;
	m = nullptr;
	m = temp->next;
	delete temp;
	temp = nullptr;
	return m;
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
