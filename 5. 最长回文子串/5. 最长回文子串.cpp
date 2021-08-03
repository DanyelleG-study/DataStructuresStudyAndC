// 5. 最长回文子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;
bool isHuiwen(string s)
{
	string::iterator itr = s.begin();
	string::reverse_iterator itr1 = s.rbegin();
	while (itr!=s.end())
	{
		if (*itr != *itr1)
			return false;
		itr++;
		itr1++;
	}
	return true;
}
string longestPalindrome(string s) 
{
	string result;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i; j < s.length(); j++)
		{
			string temp = s.substr(i,j-i+1);
			if (isHuiwen(temp) && temp.length() > result.length())
				result = temp;
		}
		
	}
	return result;
}
//中心扩散算法
pair<int, int> expandAroundCenter(const string& s, int left, int right) {
	while (left >= 0 && right < s.size() && s[left] == s[right]) {
		--left;
		++right;
	}
	return { left + 1, right - 1 };
}
string longestPalindrome2(string s) {
	int start = 0, end = 0;
	for (int i = 0; i < s.size(); ++i) {
		pair<int,int> p1= expandAroundCenter(s, i, i);
		int left1= p1.first;
		int right1 = p1.second;
		pair<int, int> p2 = expandAroundCenter(s, i, i + 1);
		int left2 = p2.first;
		int right2 = p2.second;
		if (right1 - left1 > end - start) {
			start = left1;
			end = right1;
		}
		if (right2 - left2 > end - start) {
			start = left2;
			end = right2;
		}
	}
	return s.substr(start, end - start + 1);
}
//动态规划，时间复杂度和空间复杂度都为n2
string longestPalindrome1(string s)
{
	int length = s.length();
	int maxlength = 1;//记录回文的最大长度
	int begin = 0;//记录回文的开始位置
	vector<vector<int>> vi(length, vector<int>(length));
	for (int i = 0; i < length; i++)
		vi[i][i] = true;
	for (int le = 2; le <= length; le++)//用于记录回文串的长度从2开始，因为0和1必然是回文串
	{
		for (int i = 0; i < length; i++)
		{
			int j = i + le - 1;
			if (j >= length)
				break;
			if (s[i] != s[j])
				vi[i][j] = false;
			else
			{
				if (j - i < 3)
					vi[i][j] = true;
				else
				{
					vi[i][j] = vi[i + 1][j - 1];
				}
			}
			if (vi[i][j] && j - i + 1 > maxlength)
			{
				maxlength = j - i + 1;
				begin = i;
			}
			
		}
	}
	return s.substr(begin, maxlength);
}
int main()
{
	string s= longestPalindrome2("aba");
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
