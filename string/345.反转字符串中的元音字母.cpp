/*
345. 反转字符串中的元音字母
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

 

示例 1：

输入："hello"
输出："holle"
示例 2：

输入："leetcode"
输出："leotcede"
 

提示：

元音字母不包含字母 "y" 。

*/

#include <iostream>
#include <string>

using namespace std;

string reverseVowels(string s) {
auto iter = s.begin();
    auto endIter = s.end();
    string ret;
    while(iter != endIter) {
        switch(*iter) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                ret.push_back(*iter);
        }
        iter = iter + 1;
    }
    iter = s.begin();
    auto subStrREnd = ret.rend();
    auto subStrRBgin = ret.rbegin();
    while(iter != endIter) {
        switch(*iter) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': {
                *iter = *subStrRBgin;
                subStrRBgin++;
            }
        }
        iter = iter + 1;
    }
    return s;
}