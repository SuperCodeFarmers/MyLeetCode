/*
31. 下一个排列
实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须 原地 修改，只允许使用额外常数空间。


示例 1：
输入：nums = [1,2,3]
输出：[1,3,2]

示例 2：
输入：nums = [3,2,1]
输出：[1,2,3]

示例 3：
输入：nums = [1,1,5]
输出：[1,5,1]

示例 4：
输入：nums = [1]
输出：[1]
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

/*
解题思路：
1、判断按照字典序有没有下一个，如果完全降序就没有下一个大于当前序列的集合了。
2、判断有没有下一个。只要存在nums[i - 1] < nums[i]的升序结构，就存在下一个大于当前序列的集合。我们从后往前找
3、当发现nums[i - 1] < nums[i]时，在从[i, ∞]中找到最接近a[i-1]并且又大于a[i - 1]的数字，由于是降序，所以从右往左遍历就可以得到K，
4、然后交换nums[i - 1]和K，然后在对[i, ∞]排序即可，排序只需要收尾不停交换即可，因为已经是降序了。
例如：[0,5,4,3,2,1]，下一个是[1,0,2,3,4,5]
*/

#include<vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int len = nums.size();
    for (int i = len - 1; i > 0; --i) {
        if (nums[i] > nums[i - 1]) {
            for (int j = len - 1; j >= i; --j) {
                if (nums[j] > nums[i - 1]) {
                    int temp = nums[i - 1];
                    nums[i - 1] = nums[j];
                    nums[j] = temp;
                    sort(nums.begin() + i, nums.end());
                    return;
                }
            }
        }
    }
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}