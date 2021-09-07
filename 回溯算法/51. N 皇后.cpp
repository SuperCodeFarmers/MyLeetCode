/*
51. N 皇后
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 

示例 1：


输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：[["Q"]]
 

提示：

1 <= n <= 9
皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

*/

#include <vector>
#include <string>
using namespace std;

vector<vector<string> > res;

/*
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
*/

void backtrack(vector<string> &board, int row)
{
    // 判断是否满足条件
    if (row == board.size()) {
        res.push_back(board);
        return;
    }

    // 遍历列,判断在row行，有没有合适的列
    int len = board[row].size();
    for (int col = 0; col < len; ++col) {
        // 做选择,检查条件
        if (!isValid(board, row, col)) continue;
        board[row][col] = 'Q';
        backtrack(board, row + 1);
        board[row][col] = '.';
    }
}

// 检查皇后的位置是否有效
bool isValid(vector<string>& board, int row, int col) {
    int len = board.size();
    // 检查上下位置
    for (int i = row - 1; i >= 0; --i) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // 检测左上方
    for (int i = row - 1, j = col - 1; i >= 0 && j >=0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // 检测右上方
    for (int i = row -1, j = col + 1; i >= 0 && j < len; --i, ++j) {
        string r = board[i];
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

vector<vector<string> > solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);
    return res;
}