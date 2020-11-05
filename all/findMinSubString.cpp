#include <iostream>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int minWindow(string s, string t)
{
    int left = 0;
    int right = 0;
    int start = 0;
    int minLen = INT8_MAX;
    int size = s.size();
    string res = s;
    unordered_map<char,int> window;
    unordered_map<char,int> needs;
    for (char c : t)
        needs[c]++;
    
    // 记录window中有多少个字符符合要求了
    int match = 0;
    while (right < size) {
        char c1 = s[right];
        // 判断字符是否在子串中
        if (needs.count(c1)) {
            window[c1]++;// 加入到window中
            if (window[c1] == needs[c1]) {
                // 字符c1的出现次数符合要求了
                match++;
            }
        }

        right++;

        // window中的字符串符合needs的要求了,移动left缩小窗口
        while(match == needs.size()) {
            if (right - left < minLen) {
                // 更新最小子串的位置和长度
                start = left;
                minLen = right - left;
            }

            char c2 = s[left];
            if (needs.count(c2)) {
                window[c2]--;
                if (window[c2] < needs[c2]) {
                    match--;
                }
            }
            left++;
        }
    }

    return 0;
    // return minLen == INT8_MAX ? "" : s.substr(start, minLen); 
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

