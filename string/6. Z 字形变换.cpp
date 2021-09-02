/*
6. Z 字形变换
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 

示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：

输入：s = "A", numRows = 1
输出："A"
 

提示：

1 <= s.length <= 1000
s 由英文字母（小写和大写）、',' 和 '.' 组成
1 <= numRows <= 1000

*/

/*
解法：
我们从中可以发现，她相当于把字符串一个一个的分到每一行
0    6      12         18
1  5 7   11 13     17  19
2 4  8 10   14  16     20
3    9      15         21

我们设numRows行字符串为 S1, S2, S3, ... , Sn
则容易发现：按顺序遍历字符串 s 时，每个字符 c 在 Z 字形中对应的 行索引 先从 S1 增大至 Sn，再从 Sn 减小至 S1 .... 如此反复。
因此，解决方案为：模拟这个行索引的变化，在遍历 s 中把每个字符填到正确的行 res[i]

设一个标志位 flag表示我们现在是 

1：res[i] += c， 把每个字符 c 填入对应行 Si
2：i += flag， 更新当前字符 c 对应的行索引；
3：flag = - flag， 在达到 Z 字形转折点时，执行反向。

*/

#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int len = s.size();
        vector<string> rows(numRows, "");
        int flag = -1, count = 0;
        for (int i = 0; i < len; ++i) {
            rows[count].push_back(s[i]);
            if (count == 0 || count == numRows - 1) flag = -flag;
            count += flag;
        }
        string ret = "";
        for (int i = 0; i < numRows; ++i) {
            ret+=rows[i];
        }
        return ret;
    }