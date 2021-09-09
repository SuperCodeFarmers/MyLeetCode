/*
39. 组合总和
给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。

candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。 

对于给定的输入，保证和为 target 的唯一组合数少于 150 个。

 

示例 1：

输入: candidates = [2,3,6,7], target = 7
输出: [[7],[2,2,3]]
示例 2：

输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
示例 3：

输入: candidates = [2], target = 1
输出: []
示例 4：

输入: candidates = [1], target = 1
输出: [[1]]
示例 5：

输入: candidates = [1], target = 2
输出: [[1,1]]
 

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500
*/

#include <vector>
using namespace std;

vector<vector<int> > res; //记录答案
vector<int> path;        //记录路径

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    dfs(candidates, 0, target);
    return res;
}

void dfs(vector<int> &c, int u, int target)
{
    if (target < 0)
        return; //递归边界
    if (target == 0)
    {
        res.push_back(path); //记录答案
        return;
    }
    for (int i = u; i < c.size(); i++) // i从u开始，就可以保证不会出现重复的数组
    {
        if (c[i] <= target)
        {
            path.push_back(c[i]);     //加入路径数组中
            dfs(c, i, target - c[i]); // 因为可以重复使用，所以还是i
            path.pop_back();          //回溯，恢复现场
        }
    }
}
