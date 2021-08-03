// 剑指 Offer 07. 重建二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//简便方法：用int*记录前序遍历和中序遍历的分界点，节省内存空间，不用重复存储
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() > 0 && inorder.size() > 0)
	{
		TreeNode *node = new TreeNode(preorder[0]);
		vector<int> inorderleft(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[0]));
		vector<int> inorderleft1(find(inorder.begin(), inorder.end(), preorder[0]) + 1, inorder.end());
		vector<int> preorderleft(preorder.begin() + 1, preorder.begin() + inorderleft.size()+1);
		vector<int> preorderleft1(preorder.begin() + inorderleft.size() + 1, preorder.end());
		node->left = buildTree(preorderleft, inorderleft);
		node->right = buildTree(preorderleft1, inorderleft1);
		return node;
		
	}
	else
		return nullptr;
}
int main()
{
	vector<int> pre({ 1,2,4,7,3,5,6,8 });
	vector<int> inor({ 4,7,2,1,5,3,8,6 });
	TreeNode* head = buildTree(pre, inor);
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
