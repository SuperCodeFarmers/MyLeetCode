#include <iostream>
#include <vector>
using namespace std;

/*
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 * 请你找出并返回这两个正序数组的中位数。
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

示例 3：
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000

示例 4：
输入：nums1 = [], nums2 = [1]
输出：1.00000

示例 5：
输入：nums1 = [2], nums2 = []
输出：2.00000
 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

// 暴力
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*
    vector<int> v(nums1.begin(), nums1.end());
    v.emplace_back(nums2.begin(), nums2.end());
    */

    vector<int> v;
    merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),v);

    sort(v.begin(), v.end());

    int size = v.size();
    if (size % 2 == 0) {
        int index1 = size / 2;
        int index2 = index1 - 1;
        return (v[index1] + v[index2]) / 2.0;
    } else {
        int index1 = size / 2;
        return v[index1];
    }
}

// 使用二分法
double findMedianSortedArrays_binary(vector<int>& nums1, vector<int>& nums2) {

    return 0.0;
}
int main()
{
    std::cout << 1 / 2.0 << std::endl;
    std::cout << 10.0 / 2 << std::endl;
    return 0;
}

