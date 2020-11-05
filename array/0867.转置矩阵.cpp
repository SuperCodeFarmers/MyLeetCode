#include <iostream>
#include <vector>
using namespace std;

/*
 * 给定一个矩阵 A， 返回 A 的转置矩阵。
 *
 * 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：[[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[1,4,7],[2,5,8],[3,6,9]]
 * 示例 2：
 *
 * 输入：[[1,2,3],[4,5,6]]
 * 输出：[[1,4],[2,5],[3,6]]
 *  
 *
 * 提示：
 *
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 *
 */

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

vector<vector<int>> transpose(vector<vector<int>>& A) {
    vector<vector<int>> ret;
    size_t rowsize = A.size();
    size_t colsize = A[0].size();
    if (rowsize == 1 && colsize == 1) {
        return A;
    }
    for(size_t i = 0; i < colsize; ++i) {
        vector<int> nowrow;
        for (size_t j = 0; j < rowsize; ++j) {
            nowrow.push_back(A[j][i]);
        }
        ret.push_back(nowrow);
    }
    return ret;
}
