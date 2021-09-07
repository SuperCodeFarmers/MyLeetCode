/*
17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 
示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]
 
提示：
0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。
*/

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

#include <vector>
#include <string>

using namespace std;

vector<string> res;

string getPosStr(int pos)
{
    switch (pos)
    {
    case 2:
        return string("abc");
        break;
    case 3:
        return string("def");
        break;
    case 4:
        return string("ghi");
        break;
    case 5:
        return string("jkl");
        break;
    case 6:
        return string("mno");
        break;
    case 7:
        return string("pqrs");
        break;
    case 8:
        return string("tuv");
        break;
    case 9:
        return string("wxyz");
        break;
    }
    return string("");
}

// nums:路径，track:选择列表
void backtrack(vector<int> &nums, string &track, int pos)
{
    if (track.size() == nums.size())
    {
        res.push_back(track);
        return;
    }

    string subStr = getPosStr(nums[pos]);
    int len = subStr.size();
    for (int i = 0; i < len; ++i)
    {
        track.push_back(subStr[i]);
        backtrack(nums, track, pos + 1);
        track.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    int len = digits.size();
    if (len == 0)
        return res;
    vector<int> globalDigits;
    for (int i = 0; i < len; ++i)
    {
        globalDigits.push_back(digits[i] - '0');
    }
    string track;
    backtrack(globalDigits, track, 0);

    return res;
}
