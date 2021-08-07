// 30. 串联所有单词的子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
//思路：将words出现的string 和次数记录下来
//取s中words.size()*words[0].size()的子串为temp
//取temp中的每一个words[0].size()去map中查找，查不到就break，查的到，map中对应value就-1,
vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> res;
	if (s == "" || words.size() == 0)
		return res;
	map<string, int> wordsize;
	for (int i = 0; i < words.size(); i++)
	{
		auto iter = wordsize.find(words.at(i));
		if (iter == wordsize.end())
			wordsize.insert(pair<string, int>(words.at(i), 1));
		else
			iter->second += 1;
	}
	int size = words.size();
	int lenth = words.at(0).size();
	if (s.length() < size*lenth)
		return res;
	for (int i = 0; i <= s.length() - size * lenth; i++)
	{
		map<string, int> temp(wordsize);
		string temp1 = s.substr(i, size*lenth);
		int j = 0;
		while (j < temp1.size())
		{
			string temp2 = temp1.substr(j, lenth);
			auto iter = temp.find(temp2);
			if (iter == temp.end())
				break;
			else
			{
				iter->second -= 1;
				if (iter->second == 0)
					temp.erase(iter->first);
			}
			j += lenth;
		}
		if (temp.size() == 0)
			res.push_back(i);
	}

	return res;
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
