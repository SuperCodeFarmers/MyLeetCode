/*
1109. 航班预订统计
这里有 n 个航班，它们分别从 1 到 n 进行编号。

有一份航班预订表 bookings ，表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi] 意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。

请你返回一个长度为 n 的数组 answer，其中 answer[i] 是航班 i 上预订的座位总数。

 

示例 1：

输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]
解释：
航班编号        1   2   3   4   5
预订记录 1 ：   10  10
预订记录 2 ：       20  20
预订记录 3 ：       25  25  25  25
总座位数：      10  55  45  25  25
因此，answer = [10,55,45,25,25]
示例 2：

输入：bookings = [[1,2,10],[2,2,15]], n = 2
输出：[10,25]
解释：
航班编号        1   2
预订记录 1 ：   10  10
预订记录 2 ：       15
总座位数：      10  25
因此，answer = [10,25]
 

提示：

1 <= n <= 2 * 104
1 <= bookings.length <= 2 * 104
bookings[i].length == 3
1 <= firsti <= lasti <= n
1 <= seatsi <= 104

*/

/*
解法：使用查分数组

对于已知有n个元素的离线数列d，我们可以建立记录它每项与前一项差值的差分数组f：显然，f[1]=d[1]-0=d[1];对于整数i∈[2,n]，我们让f[i]=d[i]-d[i-1]。
上面为专业术语，通俗点说就是前面的元素减后面的元素得到差分数组。

比如说：
首先一个数组 
1 2 3 4 5 6 7 
那么差分之后 
1 1 1 1 1 1 1
就是chafen[i]存的是num[i]−num[i−1]

2.应用
先举个例子：
现在有数组a[7]
int a[7];
a[0]=1;a[1]=2;a[2]=3;a[3]=4;a[4]=5;a[5]=6;a[6]=7;a[7]=8;
如果要把a[0]-a[4]都加一，最朴素的方法就是
a[0]++; a[1]++; a[2]++; a[3]++; a[4]++;
时间复杂度为O(n)。

但是如果先有一个神奇的差分数组d[7]，就可以省力得多了！
现在开一个d[7]：

int d[7];
d[0]=a[0];
for(int i=1; i<7; i++) {
    d[i] = a[i]-a[i-1];
}

差分数组就完成啦！
*/

#include<vector>
using namespace std;
vector<int> corpFlightBookings(vector<vector<int> >& bookings, int n) {
    vector<int> answer(n, 0);
    int len = bookings.size();
    for (int i = 0; i < len; ++i) {
        int j = bookings[i][0] - 1;
        int k = bookings[i][1];
        answer[j] += bookings[i][2];
        if (k < n) {
            answer[k] -= bookings[i][2];
        }
    }
    for (int i = 1; i < n; ++i) {
        answer[i] += answer[i - 1];
    }
    return answer;
}