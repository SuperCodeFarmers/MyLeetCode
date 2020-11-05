#include <iostream>
#include <vector>
using namespace std;

/*
 *
 * 给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。
 *
 * 请返回 nums 的动态和。
 *  
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3,4]
 * 输出：[1,3,6,10]
 * 解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
 * 示例 2：
 *
 * 输入：nums = [1,1,1,1,1]
 * 输出：[1,2,3,4,5]
 * 解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
 * 示例 3：
 *
 * 输入：nums = [3,1,2,10,1]
 * 输出：[3,4,6,16,17]
 *  
 *
 * 提示：
 *
 * 1 <= nums.length <= 1000
 * -10^6 <= nums[i] <= 10^6
 *
 *
 * */


vector<int> runningSum(vector<int>& nums) {
    int len = nums.size();
    cout << len << endl;
    vector<int> sum;
    sum.push_back(nums[0]);
    for (int i = 1; i < len; ++i) {
        int a = sum[i - 1] + nums[i];
        // cout << "a:" << a << ", sum[" << i << "]" << sum[i] << ", nums[" << i << "]" << nums[i] << endl;
        sum.push_back(a);
        // cout << sum[i] << endl;
    }
        
    return sum;
}

int main()
{
    vector<int> nums = {1,1,1,1,1};

    auto ret = runningSum(nums);

    int len = ret.size();
    for (int i = 0; i < len; ++i) {
        cout << ret[i] << endl;
    }
    return 0;
}

