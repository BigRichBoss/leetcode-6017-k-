// leetcode 6017向数组中追加k个整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	long long minimalKSum(vector<int>& nums, int k) {
		long long res = 0;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int tmp1 = 0;
		for (int it : nums) { tmp1 += it; }

		//在右边界添加数据
		if (k >= nums[n - 1])
		{
			long long tmp0 = nums[n - 1] * (nums[n - 1] + 1) / 2;
			res = tmp0 - tmp1;
			//剩下n个
			res += (2 * nums[n - 1] + 1 + n)*n / 2;


		}
		else if (k < nums[0]) //在左边界添加k 个
		{
			res = (k + 1)*k / 2;

		}
		else if (k >= nums[0] && k < nums[n - 1])   //k在这个中间
		{
			//最大值- 个数， 大于等于k ，在里面取，
			int tmp = nums[n - 1] - n;
			int count = k;

			for (int i = 1, j = 0; i < nums[n - 1] && count>0;)
			{
				if (i == nums[j])
				{
					++i;
					++j;
				}
				else if (i < nums[j])
				{

					res += i;
					++i;
					--count;
				}
				else if (i > nums[j])
				{
					++j;
				}
			}

			if (count>0)  //最大值-个数， 小于k,在外面取；
			{
				//int coun = k - count;
				res += (2 * nums[n - 1] + 1 + count)*count / 2;

			}
		}
		return res;


	}
};
int main()
{
	Solution ss;
	vector<int> vec = { 53, 41, 90, 33, 84, 26, 50, 32, 63, 47, 66, 43, 29, 88, 71, 28, 83 };
	int k = 76;

	long long res = ss.minimalKSum(vec, k);
    std::cout << res<<endl;
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
