#include <iostream>
#include <vector>

using namespace std;

/*
 * 给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 
 *
 * 请你统计并返回 grid 中 负数 的数目。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
 * 输出：8
 * 解释：矩阵中共有 8 个负数。
 * 示例 2：
 *
 * 输入：grid = [[3,2],[1,0]]
 * 输出：0
 * 示例 3：
 *
 * 输入：grid = [[1,-1],[-1,-1]]
 * 输出：3
 * 示例 4：
 *
 * 输入：grid = [[-1]]
 * 输出：1
 *  
 *
 * 提示：
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 100
 * -100 <= grid[i][j] <= 100
 */

int main()
{
    std::cout << "Hello world" << std::endl;
vector<vector<int>> p = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    return 0;
}

int countNegatives(vector<vector<int>>& grid) {
    int count = 0;
    size_t size1 = grid.size();
    for(size_t i = 0; i < size1; ++i) {
        vector<int> p = grid[i];
        size_t size2 = p.size();
        for (size_t j = 0; j < size2; ++j) {
            if (p[j] < 0) {
                ++count;
            }
        }
    }

    return count;
}
