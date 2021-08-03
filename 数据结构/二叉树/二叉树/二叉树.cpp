// 二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<queue>
#include<stack>
#include<fstream>
#include<assert.h>
#include<string>
using namespace std;
template<class T>struct BinTreeNode
{
	T data;
	BinTreeNode<T> *leftChild;
	BinTreeNode<T> *rightChild;
	BinTreeNode() :leftChild(NULL), rightChild(NULL)
	{}
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)
	{
		leftChild = l;
		rightChild = r;
		data = x;
	}
};
template <class T> class BinaryTree
{
public:
	BinaryTree() :root(NULL) {}
	BinaryTree(T x) :root(NULL), RefValue(x) {}
	BinaryTree(const BinaryTree<T> &p)
	{
		if (this != &p)
		{
			root = Copy(p.root);
		}
	}
	~BinaryTree()
	{
		destroy(root);
	}
	int maxDepth(BinTreeNode<T>* root) {
		if (root == NULL)
			return 0;
		else
		{
			int i = maxDepth(root->leftChild);
			int j = maxDepth(root->rightChild);
			return i > j ? i + 1 : j + 1;
		}
	}
	bool IsEmpty()
	{
		if (root == NULL)
			return true;
		else
			return false;
	}
	bool Find(T &x)
	{
		return Find(root, x);
	}
	int Height()
	{
		return Height(root);
	}
	int Size()
	{
		return size(root);
	}
	BinTreeNode<T> *Parent(BinTreeNode <T> *t) {
		return (root == NULL || root == t) ? NULL : Parent(root, t);
	}
	BinTreeNode<T> *LeftChild(BinTreeNode<T> *t) {
		if (t == NULL)
			return NULL;
		return t->leftChild;
	}
	BinTreeNode<T> *rightChild(BinTreeNode<T> *t) {
		if (t == NULL)
			return NULL;
		return t->rightChild;
	}
	BinTreeNode<T> *getRoot() const {
		return root;
	}
	void PreOrder(void(*visit)(BinTreeNode<T> *t)) {
		PreOrder(root, visit);
	}
	void InOrder(void(*visit)(BinTreeNode<T> *t)) {
		InOrder(root, visit);
	}
	void PostOrder(void(*visit)(BinTreeNode<T> *t)) {
		PostOrder(root, visit);
	}
	bool Insert(T item) {
		return Insert(root, item);
	}
	bool insert(T item) {
		return	Insert(root, item);
	}
	void CreateCompBinTree(T *CBT, int num) {//建立完全二叉树
		CreateCompBinTree(CBT, num, 0, root);
	}
	void printBinTree(ostream &out = cout) {//按广义表打印
		printBinTree(root, out);
	}
	void levelOrder(void(*visit) (BinTreeNode<T> *t)) {//层次序遍历,借用队列来实现
		if (root == NULL)
			return;
		queue<BinTreeNode<T>*> q;
		BinTreeNode<T> *p = root;
		visit(p);
		q.push(p);
		while (q.size()>0)
		{
			p = q.front();
			q.pop();
			if (p->leftChild != NULL)
			{
				visit(p->leftChild);
				q.push(p->leftChild);
			}
			if (p->rightChild != NULL)
			{
				visit(p->rightChild);
				q.push(p->rightChild);
			}
		}
		
	}
	void PreOrder1(void(*visit) (BinTreeNode<T> *t))
	{
		stack<BinTreeNode<T>*> s;
		BinTreeNode<T> *p = root;
		s.push(NULL);
		while (p!=NULL)
		{
			visit(p);
			if (p->rightChild != NULL)
				s.push(p->rightChild);
			if (p->leftChild != NULL)
				p = p->leftChild;
			else
			{
				p = s.top();
				s.pop();
			}
		}
	}
	void InOrder1(void(*visit) (BinTreeNode<T> *t)) {//非递归中序遍历
		stack<BinTreeNode<T>*> S;
		BinTreeNode<T> *p = root;
		do {
			while (p != NULL) {	//遍历指针向左下移动
				S.push(p); 		//该子树沿途结点进栈
				p = p->leftChild;
			}
			if (S.size()>0) {	
				p = S.top();//栈不空时退栈
				S.pop();  visit(p);	//退栈, 访问
				p = p->rightChild;	//遍历指针进到右子女
			}
		} while (p != NULL || S.size() > 0);
	}
	void levelOrder1(void(*visit) (BinTreeNode<T> *t)) {//层次序遍历
		if (root == NULL) return;
		queue<BinTreeNode<T> * > Q;
		BinTreeNode<T> *p = root;
		visit(p);   Q.push(p);
		while (!Q.IsEmpty()) {
			p=Q.front();
			Q.pop();
			if (p->leftChild != NULL) {
				visit(p->leftChild);
				Q.push(p->leftChild);
			}
			if (p->rightChild != NULL) {
				visit(p->rightChild);
				Q.push(p->rightChild);
			}
		}
	}
	template <typename T>struct stkNode {
		BinTreeNode<T> *ptr;      //树结点指针	        
		enum { L, R }tag;               //退栈标记，必须说明为枚举变量，tag移到最右边。这里最好用bool量
		stkNode(BinTreeNode<T> *N = NULL) {
			ptr = N;
			tag = L;
		}	           //构造函数
	};

	void PostOrder1(void(*visit) (BinTreeNode<T> *t)) {//非递归后序遍历
		stack<stkNode<T> > S;
		stkNode<T> w;
		BinTreeNode<T> * p = root;     //p是遍历指针
		do {
			while (p != NULL) {
				w.ptr = p;
				w.tag = stkNode<T>::L;//枚举类型定义在struct stkNode中，如定义为全局性就简单了
				S.push(w);
				p = p->leftChild;
			}
			int continue1 = 1;	    //继续循环标记, 用于R
			while (continue1 && !S.IsEmpty()) {
				w = S.top();
				S.pop();  p = w.ptr;
				switch (w.tag) {   	//判断栈顶的tag标记
				case stkNode<T>::L:  w.tag = stkNode<T>::R;
					S.push(w);
					continue1 = 0;
					p = p->rightChild;  break;
				case stkNode<T>::R:  visit(p);   break;
				}
			}
		} while (!S.IsEmpty());	//继续遍历其他结点
		cout << endl;
	}
	friend istream& operator >> (istream &in, BinaryTree<T> &Tree) {//输入二叉树
		Tree.CreateBinTree(in, Tree.root);
		return in;
	}
	// show bintree in the form of genlist
	friend ostream& operator << (ostream& out, BinaryTree<T>& Tree) {//按广义表输出
		Tree.printBinTree(out);
		out << endl;
		return out;
	}
	void Output(ostream &out = cout) {//按缩格文本输出
		out << "The structure of the binary tree is:\n";
		Output(root, string(" "), out);
		out << endl;
	}
protected:
	bool Find(BinTreeNode<T> *p, T &x)
	{
		if (!p)
			return false;
		if (p->data == x)
			return true;
		bool s = Find(p->leftChild, x);
		if (s)
			return true;
		else
			return Find(p->rightChild, x);
	}
	int Height(BinTreeNode<T> *subTree) const
	{
		if (subTree == NULL)
			return 0;
		else
		{
			int j = Height(subTree->rightChild);
			int i = Height(subTree->leftChild);
			return i < j ? j + 1:i + 1;
		}	
	}
	int Size(BinTreeNode<T> *subTree)const
	{
		if (subTree == NULL)
			return 0;
		else
		{
			int i = Size(subTree->leftChild);
			int j = Size(subTree->rightChild);
			return i + j + 1;
		}
	}
	BinTreeNode<T> *Copy(BinTreeNode<T> *r)
	{
		if (r == NULL)
			return NULL;
		BinTreeNode<T> *node = new BinTreeNode<T>(r->data);
		node->leftChild = Copy(r->leftChild);
		node->rightChild = Copy(r->rightChild);
		return node;
	}
	BinTreeNode<T> *Parent(BinTreeNode<T> *subtree, BinTreeNode<T> *t)
	{
		if (subtree == NULL)
			return NULL;
		if (subtree->leftChild == t || subtree->rightChild == t)
			return subtree;
		BinTreeNode<T> *p;
		if ((p == parent(subtree->leftChild, t) != NULL))
			return p;
		else
			return Parent(subtree->rightChild, t);
	}
	void PreOrder(BinTreeNode<T> *subtree, void(*visit)(BinTreeNode<T> *t))
	{
		if (subtree != NULL)
		{
			visit(subtree);
			PreOrder(subtree->leftChild, visit);
			PreOrder(subtree->rightChild, visit);
		}
	}
	void InOrder(BinTreeNode<T> *subtree, void(*visit)(BinTreeNode<T> *t))
	{
		if (subtree != NULL)
		{
			InOrder(subtree->leftChild, visit);
			visit(subtree);
			InOrder(subtree->rightChild, visit);
		}
	}
	void PostOrder(BinTreeNode<T> *subtree, void(*visit)(BinTreeNode<T> *t))
	{
		if (subtree != NULL)
		{
			PostOrder(subtree->leftChild, visit);
			PostOrder(subtree->rightChild, visit);
			visit(subtree);
		}
	}
	bool Insert(BinTreeNode<T> *& subTree, T& x)//在节点的某子树插入数据为X的节点
	{
		if (!subTree) {
			subTree = new BinTreeNode<T>(x);
			assert(subTree);
			return true;
		}
		else {
			return Insert(subTree->leftChild, x) || Insert(subTree->rightChild, x);//如果左子树插入成功，不会再去右子树
		}
	}
	void CreateCompBinTree(T *CBT, int num, int rt, BinTreeNode<T> *&subTree)
	{
		if (rt >= num)
			subTree = NULL;
		else
		{
			subTree = new BinTreeNode<T>(CBT[rt]);
			if (subTree == NULL)
			{
				exit(1);
			}
			CreateCompBinTree(CBT, num, 2 * rt + 1, subTree->leftChild);
			CreateCompBinTree(CBT, num, 2 * rt + 2, subTree->leftChild);
		}
	}
	void printBinTree(BinTreeNode<T> *subTree, ostream &out) {//按广义表打印
		if (subTree) {
			out << subTree->data;
			if (subTree->leftChild || subTree->rightChild) {
				out << "(";
				printBinTree(subTree->leftChild, out);
				if (subTree->rightChild) {
					out << ",";
				}
				printBinTree(subTree->rightChild, out);
				out << ")";
			}
		}
	}

	void Output(BinTreeNode<T> *subTree, string str, ostream &out);
	void destroy(BinTreeNode<T> *& subTree) {//清除子二叉树
		if (subTree != NULL) {
			destroy(subTree->leftChild);
			destroy(subTree->rightChild);
			delete subTree;
		}
	}
private:
	void CreateBinTree(istream &in, BinTreeNode<T> *& subTree) {//私有函数: 以递归方式建立二叉树。
		T item;
		if (in >> item) {
			if (item != RefValue) {
				subTree = new BinTreeNode<T>(item);		//Create Root
				assert(subTree);
				CreateBinTree(in, subTree->leftChild);	// Create left child tree
				CreateBinTree(in, subTree->rightChild);	// Create reght child tree
			}
			else
			{
				subTree = NULL;
			}
		}
	}
	BinTreeNode<T> *root;
	T RefValue;
};
template<class T>
void BinaryTree<T>::Output(BinTreeNode<T> *subTree, string str, ostream &out)
{
	if (!subTree) {
		return;
	}
	out << str << subTree->data;
	if (subTree->leftChild) {
		out << "─┐" << endl;
		if (subTree->rightChild) {
			Output(subTree->leftChild, str + "│　", out);
		}
		else {
			Output(subTree->leftChild, str + "　　", out);
		}
	}
	if (subTree->rightChild) {
		out << endl << str << "└─┐" << endl;
		Output(subTree->rightChild, str + "　　", out);
	}
}

void visit(BinTreeNode<int> *t)
{
	cout << t->data << endl;
}
int main()
{
	ifstream fin("D:\\0_code\\数据结构\\数据结构\\二叉树\\二叉树\\data.txt");
	assert(fin);
	BinaryTree<int> binTree(0);
	assert(fin >> binTree);
	fin.close();
	cout << "The binary tree is: \n" << binTree << endl;
	binTree.InOrder1(visit);
	/*binTree.Output();
	ofstream fout("output.txt");
	assert(fout);
	binTree.Output(fout);
	fout.close();
	BinaryTree<int> binTree1(binTree);
	cout << "The copy binary tree is: \n" << binTree1 << endl;
	binTree1.Output();

	cout << "\nThe preorder of the binary tree is:\n";
	binTree.PreOrder(visit);*/
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
