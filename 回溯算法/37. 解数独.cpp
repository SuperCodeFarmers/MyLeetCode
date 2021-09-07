/*
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

示例：
输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
解释：输入的数独如上图所示，唯一有效的解决方案如下所示：

提示：
board.length == 9
board[i].length == 9
board[i][j] 是一位数字或者 '.'
题目数据 保证 输入数独仅有一个解

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

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

bool isValid(int row, int col, char val, vector<vector<char> >& board) {
    // 遍历行
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == val)
        {
            return false;
        }
    }

    // 遍历列
    for (int i = 0; i < 9; ++i) {
        if (board[i][col] == val) {
            return false;
        }
    }
    
    // 遍历小方块
    int newRow = (row + 1) / 3;
    int newCol = (col + 1) / 3;

    for (int i = newRow * 3; i < newRow * 3 + 3; ++i) {
        for (int j = newCol * 3; j < newCol * 3 + 3; ++j) {
            if (board[i][j] == val) {
                return false;
            }
        }
    }


    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val ) {
                return false;
            }
        }
    }

    return true;
}

bool backtrack(vector<vector<char> > &board)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                continue;
            }
            // 尝试每个数字
            for (char k = '1'; k <= '9'; ++k) {
                if (isValid(i, j, k, board)) {
                    board[i][j] = k;
                    if (backtrack(board))
                    {
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
            // 9个数都尝试了，都不可以，就返回false
            return false;
        }
    }

    // 走到这个return时，说明已经把所有的行和列都填上了数字
    return true;
}


void solveSudoku(vector<vector<char> > &board)
{
    backtrack(board);
}

