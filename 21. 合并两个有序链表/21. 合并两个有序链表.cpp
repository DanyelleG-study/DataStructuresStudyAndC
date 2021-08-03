// 21. 合并两个有序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//题解递归调用

#include <iostream>
#include<string>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			p->next = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	if (l1)
		p->next = l1;
	if (l2)
		p->next = l2;
	p = head->next;
	delete head;
	head = NULL;
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
