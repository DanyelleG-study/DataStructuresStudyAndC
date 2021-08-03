// KMP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;
void getNext(const string &s, int *next)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i<s.length()-1)
	{
		if (j == -1 || s[i] == s[j])
		{
			next[++i] = ++j;
		}
		else
		{
			j = next[j];
		}
	}
}
int KMP(const string& s1, const string &s2)
{
	int i = 0;
	int j = 0;
	int *next=new int[s2.length()];
	getNext(s2, next);
	while (i<s2.length())
	{
		cout << next[i] << endl;
		i++;
	}
	i = 0;
	int s1l=s1.length();
	int s2l = s2.length();
	while (i< s1l&&j< s2l)
	{
		if (j == -1 || s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= s2l)
		return i- s2l;
	else
		return -1;
}
int main()
{
	string s1("ABACDA");
	string s2("abcabcbb");
	int result=KMP(s1, s2);
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
