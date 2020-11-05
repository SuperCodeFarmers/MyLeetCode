#include <iostream>
#include <vector>

using namespace std;

/*
 *给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

 示例:

 输入: [0,1,0,3,12]
 输出: [1,3,12,0,0]
 说明:

 必须在原数组上操作，不能拷贝额外的数组。
 尽量减少操作次数。
 */

void moveZeroes(vector<int>& nums) {
    int cnt = 0;
    for (int i : nums) {
        if (i == 0) {
            ++cnt;
        }
    }

    for (int i = 0; i < cnt; ++i) {
        for (auto it = nums.begin(); it < nums.end() - 1; ++it) {
            if (*it == 0) {
                int t = *it;
                *it = *(it + 1);
                *(it + 1) = t;
            }
        }
    }

}

int main()
{
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(auto i : nums) {
        cout << i << " ";
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

