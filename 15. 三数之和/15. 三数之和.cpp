// 15. 三数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<algorithm>
//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
//注意：答案中不可以包含重复的三元组。


using namespace std;
//暴力循环

//排序+双指针实现思路
void pu(vector<vector<int>> &vc, vector<int>& nums, int begin, int end, int value)
{
	while (begin < end)
	{
		int num = nums[begin] + nums[end];
		if (num + value == 0)
		{
			vector<int> temp;
			temp.push_back(value);
			temp.push_back(nums[begin]);
			temp.push_back(nums[end]);
			vc.push_back(temp);

			while (begin < end&&nums[begin] == nums[begin + 1])
			{
				begin++;
			}
			begin++;
			while (begin < end&&nums[end] == nums[end - 1])
			{
				end--;
			}
			end--;
		}
		else if (num + value < 0)
			begin++;
		else
			end--;
	}
}
vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		pu(res, nums, i + 1, nums.size() - 1, nums[i]);
	}
	return res;
}
int main()
{
	vector<int> v({ -1,0,1,2,-1,-4 });
	vector<vector<int>>res = threeSum(v);
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
