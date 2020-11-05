#include <iostream>
#include <vector>

using namespace std;

/*
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
 *
 * 示例 1：
 *
 * 输入：[3,4,5,1,2]
 * 输出：1
 * 示例 2：
 *
 * 输入：[2,2,2,0,1]
 * 输出：0
 *
 *
 */

int minArray(vector<int>& numbers) {
    int len = numbers.size();
    if (len == 1) {
        return numbers[0];
    }
    int first = 0;
    int second = 1;
    while(numbers[first] <= numbers[second]) {
        ++first;
        ++second;
        if (second == len) {
            return numbers[0];
        }
    }
    return numbers[second];
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

