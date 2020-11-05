#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *1299. 将每个元素替换为右侧最大元素
 给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。

 完成所有替换操作后，请你返回这个数组。

  

 示例：

 输入：arr = [17,18,5,4,6,1]
 输出：[18,6,6,6,1,-1]
  
1.先将最后一个元素设为当前最大值
2.从倒数第二个元素开始遍历，首先先将当前元素保存到零时变量temp
3.将当前位置修改为当前最大值
4.比较如果temp大于当前保存的最大值，则修改当前最大值为tmmp
5.遍历完成为修改最后一个元素为-1

 提示：

 1 <= arr.length <= 10^4
 1 <= arr[i] <= 10^5
 */

vector<int> replaceElements(vector<int>& arr) {
    vector<int> ret;
    int len = arr.size();
    int maxnum = arr[len - 1];
    ret.push_back(-1);
    for(int i = len - 2; i >= 0; --i) {
        ret.push_back(maxnum);
        if (arr[i] > maxnum) {
            maxnum = arr[i];
        }
    }
    return vector<int>(ret.rbegin(), ret.rend());
}

int main()
{
    vector<int> arr = {17,18,5,4,6,1};
    vector<int> arr2 = replaceElements(arr);
    for(int v : arr2) {
        cout << v << "\t";
    }

    return 0;
}

