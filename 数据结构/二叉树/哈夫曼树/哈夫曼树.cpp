// 哈夫曼树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
template <typename T, typename E>struct HuffmanNode {
	E data;
	HuffmanNode<T, E> *leftChild, *rightChild, *parent;
	HuffmanNode() :leftChild(NULL), rightChild(NULL), parent(NULL) {}//构造函数
	HuffmanNode(E elem, HuffmanNode<T, E> * pr, HuffmanNode<T, E> *left, HuffmanNode<T, E>*right)
		:data(elem), parent(pr), leftChild(left), rightChild(right) {}
	bool operator >(HuffmanNode<T, E> right)
	{	
		if (data > right.data)
			return true;
		else
			return false;
	}
	bool operator >= (HuffmanNode<T, E> right) {
		return (data > right.data) || (data == right.data);
	}
	bool operator < (HuffmanNode<T, E> right) {
		return data < right.data;
	}
	bool operator <= (HuffmanNode<T, E> right) {
		return (data < right.data) || (data == right.data);
	}
	bool operator == (HuffmanNode<T, E> right) {
		return data == right.data;
	}
};
template <typename T, typename E> class HuffmanTree {
public:
	HuffmanTree(E w[], int n)
	{

	}
	~HuffmanTree()
	{
		deleteTree(root);
	}
	HuffmanNode<T, E>* getRoot()
	{
		return root;
	}
	void output(HuffmanNode<T, E> * t, string str, ostream &out)
	{
		if (!t) {
			return;
		}
		out << str << t->data;
		if (t->leftChild) {
			out << "─┐" << endl;
			if (t->rightChild) {
				output(t->leftChild, str + "│　", out);
			}
			else {
				output(t->leftChild, str + "　　", out);
			}
		}
		if (t->rightChild) {
			out << endl << str << "└─┐" << endl;
			output(t->rightChild, str + "　　", out);
		}if (!t) {
			return;
		}
		out << str << t->data;
		if (t->leftChild) {
			out << "─┐" << endl;
			if (t->rightChild) {
				output(t->leftChild, str + "│　", out);
			}
			else {
				output(t->leftChild, str + "　　", out);
			}
		}
		if (t->rightChild) {
			out << endl << str << "└─┐" << endl;
			output(t->rightChild, str + "　　", out);
		}
	}
protected:
	HuffmanNode<T, E> *root;
	void deleteTree(HuffmanNode<T, E> * t)
	{
		if (t != NULL)
		{
			deleteTree(t->leftChild);
			deleteTree(t->rightChild);
			delete t;
		}
	}
	void mergeTree(HuffmanNode<T, E> *ht1, HuffmanNode<T, E> *ht2,HuffmanNode<T, E> *& parent);
};
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
