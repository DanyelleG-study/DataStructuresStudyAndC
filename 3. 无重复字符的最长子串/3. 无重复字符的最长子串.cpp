// 3. 无重复字符的最长子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace  std;
void test()
{
	unordered_set<int> test1(55);
	int bc=test1.bucket_count();
	int bc0=test1.bucket_size(0);
	int bc1=test1.bucket(0);
	test1.insert(3);
	test1.insert(4);
	int bc3 = test1.bucket(3);
	bc0 = test1.bucket_size(3);
	int bc4 = test1.bucket(4);
	bc4 = test1.bucket(3);
	bc0 = test1.bucket_size(bc4);
	bc=test1.bucket_count();
	int a=333;
}
int lengthOfLongestSubstring(string s)
{
	unordered_set<char> m;
	int j = 0;
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i != 0)
		{
			m.erase(*m.begin());
		}
		while (j < s.length()&& !m.count(s[j]))
		{
				m.insert(s[j]);
				++j;
		}
		result = max(result, j - i);
	}
	return result;
}
int main()
{
	string s("pwwkew");
	int length=lengthOfLongestSubstring(s);
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
