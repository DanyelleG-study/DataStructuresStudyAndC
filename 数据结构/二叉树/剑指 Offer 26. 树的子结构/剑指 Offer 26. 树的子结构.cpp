// 剑指 Offer 26. 树的子结构.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//思路：查找A中出现B根节点的位置
//比较对应A子树是否与B相等，相等则返回true，不相等则在A中再查找出现B子树跟节点
bool have(TreeNode *a, TreeNode *b)
{
	if (b == nullptr)
		return true;
	if (a == nullptr)
		return false;
	if (a->val != b->val)
		return false;
	return have(a->left, b->left) && have(a->right, b->right);
}
bool isSubStructure(TreeNode* A, TreeNode* B) {
	bool result=false;
	if (A != nullptr&&B != nullptr)
	{
		if (A->val == B->val)
			result=have(A, B);
		if (!result)
			result=isSubStructure(A->left, B);
		if (!result)
			result=isSubStructure(A->right, B);
	}
	return result;
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
