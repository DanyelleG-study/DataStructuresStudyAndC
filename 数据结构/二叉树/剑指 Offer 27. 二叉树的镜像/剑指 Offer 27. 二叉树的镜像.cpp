// 剑指 Offer 27. 二叉树的镜像.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
//思路：采用递归交换左右节点的顺序，左右节点只要存在一方就交换左右节点顺序
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void change(TreeNode* node)
{
	if (node->left != NULL || node->right != NULL)
	{
		TreeNode *temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
	if (node->left != NULL)
		change(node->left);
	if (node->right != NULL)
		change(node->right);
}
TreeNode* mirrorTree(TreeNode* root) {
	if (root == NULL)
		return NULL;
	else
	{
		TreeNode *node = root;
		change(node);
		return root;
	}
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
