/*
 *554. 砖墙
你的面前有一堵矩形的、由 n 行砖块组成的砖墙。这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和应该相等。

你现在要画一条 自顶向下 的、穿过 最少 砖块的垂线。如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。

给你一个二维数组 wall ，该数组包含这堵墙的相关信息。其中，wall[i] 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线 穿过的砖块数量最少 ，并且返回 穿过的砖块数量 。

 

示例 1：


输入：wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
输出：2
示例 2：

输入：wall = [[1],[1],[1]]
输出：3
 
提示：

n == wall.length
1 <= n <= 104
1 <= wall[i].length <= 104
1 <= sum(wall[i].length) <= 2 * 104
对于每一行 i ，sum(wall[i]) 应当是相同的
1 <= wall[i][j] <= 231 - 1
通过次数37,734提交次数76,915
 */

/*
解题思考过程
观察垂直线的特点, 如果穿过每行砖块对齐的缝隙越多, 那么穿过砖块的数量就会越少!

1.怎么找到每行的砖块都恰好对齐的那些缝隙呢?
可以用额外的存储空间来辅助一下~, 比如 Hashmap

2.怎么把计算对齐的缝隙转化成可操作的代码呢?
计算每一行砖块宽度的前缀和! 在计算某一行砖块的时候, 将砖块的宽度和进行累计, 每一个累计砖块的宽度和都作为 hashmap 的 key, value就是这个key出现的次数.

3.怎么求穿过的最少砖块数?
一个垂直的线最多穿过的砖块数就是这堵墙的行数, 减去出现次数/频数最高的砖块的宽度和, 就相当于找到了砖块对齐的缝隙最多的那一条垂直线了!
 */


#include <vector>
#include <map>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    std::map<int, int> ans;
    int len = wall.size();
    for (int i = 0; i < len; ++i) {
        int num = 0;
        for (int n = 0; n < wall[i].size() - 1; ++n) {
            num += wall[i][n];
            ans[num] += 1;
        }
    }
    int max = 0;
    for (auto k_v : ans) {
        if (k_v.second > max) {
            max = k_v.second;
        }
    }

    return len - max;
}
