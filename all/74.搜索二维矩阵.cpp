/*
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 *
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *  
 */


#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int row, col;
    row = matrix.size();
    col = matrix[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                continue;
            } else if (matrix[i][j] > target) {
                col = j;
            }
        }
    }
    return false;
}
