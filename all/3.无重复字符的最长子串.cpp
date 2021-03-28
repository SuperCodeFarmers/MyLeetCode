/*
 *
给定一个字符串，请你找出其中不含有重复字符的"最长子串"的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

示例 4:
输入: s = ""
输出: 0

提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
*/
#include <string>>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int start = 0, end = 0, result = 0;
    int len = 0;
    int sSize = s.size();
    while (end < sSize) {
        for (int index = start; index < end; ++index) {
            if (s[index] == s[end]) {
                len = end - start;
                start = index + 1;
                break;
            }
        }
        ++end;
        ++len;
        result = result > len ? result : len;
    }
    return result;
}

// 使用map来存字符出现的位置，不需要遍历了
int lengthOfLongestSubstring2(string s) {
    int start = 0, end = 0, result = 0, len = 0;
    unordered_map<char, int> hash;
    int sSize = s.size();
    while (end < sSize) {
        char tempChar = s[end];
        if (hash.find(tempChar) != hash.end() && hash[tempChar] >= start) {
            start = hash[tempChar] + 1;
            len = end - start;
        }

        hash[tempChar] = end;
        ++end;
        ++len;
        result = max(result, len);
    }
    return result;
}
