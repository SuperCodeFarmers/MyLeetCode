#include <iostream>
#include <vector>
using namespace std;

/*
 * 给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。
 *
 * 水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。
 *
 * 反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。
 *
 * 示例 1:
 *
 * 输入: [[1,1,0],[1,0,1],[0,0,0]]
 * 输出: [[1,0,0],[0,1,0],[1,1,1]]
 * 解释: 首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
 *      然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
 *      示例 2:
 *
 *      输入: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 *      输出: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 *      解释: 首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
 *           然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 *           说明:
 *
 *           1 <= A.length = A[0].length <= 20
 *           0 <= A[i][j] <= 1
 *
 */

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    vector<vector<int>> ret;
    size_t size = A.size();
    for (size_t i = 0; i < size; ++i) {
        vector<int> row = A[i];
        size_t size2 = row.size();
        for (int j = 0, k = size2 - 1; j <= k; ++j, --k) {
            if (j == k) {
                row[j] = (row[j] == 0) ? 1 :0;
            } else {
                row[j] = (row[j] == 0) ? 1 :0;
                row[k] = (row[k] == 0) ? 1 :0;

                int t = row[j];
                row[j] = row[k];
                row[k] = t;
            }
        }
        ret.push_back(row);
    }

    return ret;
}

