// 剑指 Offer 24. 反转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//解题思路：每次调整相邻两个节点的顺序
ListNode* reverseList1(ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* curr = head;
	while (curr) {
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
//解题思路：利用栈实现数据的倒转
ListNode* reverseList(ListNode* head) 
{
	stack<ListNode*> temp;
	while (head!=nullptr)
	{
		temp.push(head);
		head = head->next;
	}
	if (temp.size() > 0)
	{
		head = temp.top();
		ListNode* node;
		while (temp.size() > 1)
		{
			node = temp.top();
			temp.pop();
			node->next = temp.top();
		}
		node = temp.top();
		temp.pop();
		node->next = NULL;
	}
	return head;
	
}
int main()
{
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
