#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> nums, int target) {
    // 特殊用例判断
    int len = nums.size();
    if (len == 0) {
        return -1;
    }

    // 在[left, right] 区间中查找target
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        // 为了防止left + right 整型溢出，携程如下形式
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            // 下一轮搜索区间:[left, mid - 1]
            right = mid - 1;
        } else {
            // 此时:nums[mid] < target
            // 下一轮搜索区间:[mid + 1, right]
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

