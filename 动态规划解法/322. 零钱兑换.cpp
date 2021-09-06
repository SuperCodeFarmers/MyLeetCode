/*
322. 零钱兑换
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

示例 1：
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
示例 2：
输入：coins = [2], amount = 3
输出：-1
示例 3：
输入：coins = [1], amount = 0
输出：0
示例 4：
输入：coins = [1], amount = 1
输出：1
示例 5：
输入：coins = [1], amount = 2
输出：2
 
提示：
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

#include <vector>

using namespace std;

//解法一：直接动态规划
int *arr;
int coinChange(vector<int>& coins, int amount) {
        arr = new int[amount + 1];
        for (int i = 0; i <= amount; ++i)
            arr[i] = 999999999;
        arr[0] = 0;
        return dp(coins, amount);
}

int dp(vector<int>& conis, int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    if (arr[amount] != 999999999) return arr[amount];
    int ret = 99999999;
    for (int i = 0; i < conis.size(); ++i) {
        int sub = dp(conis, amount - conis[i]);
        if (sub < 0) continue;
        ret = min(ret, sub + 1);
    }
    arr[amount] = ret == 99999999 ? -1 : ret;
    return arr[amount];
}

// 解法二：使用dp数组，数组i代表金额，arr[i]代表次数
int coinChange2(vector<int>& coins, int amount) {
    int *dp = new int[amount + 1];
    for (int i = 0; i <= amount; ++i) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    // i代表金额,coins[i]代表硬币数
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            if (i - coins[j] < 0) {
                continue;
            }
            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}