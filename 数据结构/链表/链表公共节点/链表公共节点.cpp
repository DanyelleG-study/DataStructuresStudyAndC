// 链表公共节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
//如果两个链表没有交点，返回 null.
//在返回结果后，两个链表仍须保持原有的结构。
//可假定整个链表结构中没有循环。
//程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
//解题思路：从相同节点开始后面的节点都相同
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	while (headA!= NULL)
	{
		int temp = headA->val;
		while (headB!=NULL)
		{
			if (temp == headB->val)
				return headA;
			headB = headB->next;
		}
		headA = headA->next;
	}
	return NULL;
}
unsigned int getLength(ListNode *head)
{
	unsigned int size=0;
	while (head!=NULL)
	{
		size++;
		head = head->next;
	}
	return size;
}
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
	unsigned int aLength=getLength(headA);
	unsigned int bLength = getLength(headB);
	int size;
	ListNode *tempL;
	ListNode *tempS;
	if (aLength > bLength)
	{
		tempL = headA;
		tempS = headB;
		size = aLength - bLength;
	}
	else
	{
		tempL = headB;
		tempS = headA;
		size = bLength - aLength;
	}
	for (int i = 0; i < size; i++)
		tempL = tempL->next;
	while (tempL!=NULL&&tempS!=NULL&&tempL!=tempS)
	{
		tempL = tempL->next;
		tempS = tempS->next;
	}
	return tempL;
}
int main()
{
	ListNode *a=new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(4);
	ListNode *b = new ListNode(3);
	b->next = new ListNode(1);
	b->next->next = new ListNode(5);
	ListNode *c= getIntersectionNode(a, b);
	while (a!=NULL)
	{
		ListNode *temp = a->next;
		delete a;
		a = temp;
	}
	while (b != NULL)
	{
		ListNode *temp = b->next;
		delete b;
		b = temp;
	}
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
