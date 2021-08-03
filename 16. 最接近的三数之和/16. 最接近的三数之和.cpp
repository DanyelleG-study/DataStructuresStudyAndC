// 16. 最接近的三数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void po(int& res, vector<int> &nums, int begin, int end,int value, int target)
{
	while (begin<end)
	{
		int temp = nums[begin] + nums[end];
		if (abs(target - value - temp) < abs(target - res))
		{
			res = temp + value;
			while (begin<end&&nums[begin]==nums[begin+1])
			{
				begin++;
			}
			begin++;
			while (begin<end&&nums[end]==nums[end-1])
			{
				end--;
			}
			end--;
		}
		else if (target - value - temp > 0)
		{
			begin++;
		}
		else
		{
			end--;
		}
		
	}
}
int threeSumClosest(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	int res = nums[0]+nums[1]+nums[2];
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		po(res, nums, i+1, nums.size() - 1,nums[i], target);
	}
	return res;
};
int main()
{
	//nums = [-1,2,1,-4], target = 1
	vector<int> nums({0,2,1,-3 });
	int res = threeSumClosest(nums, 1);
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
