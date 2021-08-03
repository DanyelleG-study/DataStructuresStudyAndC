// 26. 删除有序数组中的重复项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//解题思路：双指针
#include <iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) 
{
	int temp = nums.size();
	for (int i = 1; i < temp; )
	{
		if (nums[i] == nums[i - 1])
		{
			nums.erase(nums.begin() + i, nums.begin() + i+1);
			temp = nums.size();
		}
		else
			i++;
	}
	return nums.size();
}
int main()
{
	vector<int> v({ 0,0,1,1,1,2,2,3,3,4 });
	int nu = removeDuplicates(v);
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
