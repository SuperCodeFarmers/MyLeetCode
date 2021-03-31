/*
 *给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 示例 1：
 输入：nums = [1,2,2]
 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

 示例 2：
 输入：nums = [0]
 输出：[[],[0]]
  

 提示：
 1 <= nums.length <= 10
 -10 <= nums[i] <= 10
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());

    ret.push_back({});
    vector<int> v;
    int left = 0;
    int right = 1;
    int len = 0;
    int nums_size = nums.size();
    for (int i = 0; i < nums_size; ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) {
            left = ret.size() - len;
        } else {
            left = 0;
        }

        right = ret.size();
        len = right - left; // 记录当前的数组长度
        for (int j = left; j < right; ++j) {
            v = ret[j];
            v.push_back(nums[i]);
            ret.push_back(v);
        }
    }

    return ret;
}

int main(int argc, char **argv) {

    vector<int> list = {1, 2, 2};
    vector<vector<int>> ret = subsetsWithDup(list);
    for (auto it : ret) {
        cout << "---------------begin---------------" << endl;
        for (auto v : it) {
            cout << v << "\t";
        }
        cout << endl << "---------------end---------------" << endl;
    }
    return 0;
}
