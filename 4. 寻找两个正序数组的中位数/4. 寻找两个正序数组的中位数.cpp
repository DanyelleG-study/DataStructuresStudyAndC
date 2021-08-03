// 4. 寻找两个正序数组的中位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int jo = nums1.size() + nums2.size();
	int c1, cout;
	if (jo % 2 == 0)//偶数
	{
		c1 = jo / 2 - 1;
		cout = 2;
	}
	else//奇数
	{
		c1 = jo / 2;
		cout = 1;
	}
	int k = 0, i = 0, j = 0;
	int sum = 0;
	while (k < cout &&( i < nums1.size() || j < nums2.size()))
	{
		if (i + j < c1)
		{
			if (i < nums1.size() && j < nums2.size())
			{
				if (nums1.at(i) < nums2.at(j))
					i++;
				else
					j++;
			}
			else if (i < nums1.size())
			{
				i++;
			}
			else
			{
				j++;
			}
		}
		else
		{
			if (i < nums1.size() && j < nums2.size() && nums1.at(i) < nums2.at(j))
			{
				sum += nums1.at(i);
				i++;
			}
			else if (i < nums1.size() && j < nums2.size() && nums1.at(i) >= nums2.at(j))
			{
				sum += nums2.at(j);
				j++;
			}
			else if (i < nums1.size())
			{
				sum += nums1.at(i);
				i++;
			}
			else if (j < nums2.size())
			{
				sum += nums2.at(j);
				j++;
			}
			k++;
		}
		
	}
	return sum * 1.0 / cout;
}
int main()
{
	vector<int> s2;
	vector<int> s1({2});
	double result = findMedianSortedArrays(s1, s2);
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
