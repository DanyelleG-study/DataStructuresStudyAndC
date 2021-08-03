// 两数相加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *head = nullptr;
	ListNode *head1 = l1;
	ListNode *head2 = l2;
	ListNode *q = head;
	int add = 0;
	while (head1 != nullptr&&head2 != nullptr)
	{
		int temp = head1->val + head2->val;
		ListNode *p = new ListNode((temp  + add) % 10);
		if (head != nullptr)
		{
			q->next = p;
			q = p;
		}
		else
		{
			head = p;
			q = head;
		}
		add = (temp + add) / 10;
		head1 = head1->next;
		head2 = head2->next;
	}
	while (head1 != nullptr)
	{
		q->next = new ListNode((head1->val + add)%10);
		q = q->next;
		add = (head1->val + add) / 10;
		head1 = head1->next;
	}
	while (head2 != nullptr)
	{
		q->next = new ListNode((head2->val + add) % 10);
		q = q->next;
		add = (head2->val + add) / 10;
		head2 = head2->next;
	}
	q->next = new ListNode(add);
	return  head;
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
