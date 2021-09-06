/*
470. 用 Rand7() 实现 Rand10()
已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。

不要使用系统的 Math.random() 方法。

 

示例 1:

输入: 1
输出: [7]
示例 2:

输入: 2
输出: [8,4]
示例 3:

输入: 3
输出: [8,1,10]
 

提示:

rand7 已定义。
传入参数: n 表示 rand10 的调用次数。
 

进阶:

rand7()调用次数的 期望值 是多少 ?
你能否尽量少调用 rand7() ?
*/


/*
解题思路
想到很久之前面试一家有趣的公司 老板（清华大佬）问过一个很简单的题目，大概意思是： 一个不均匀的硬币，怎么抛硬币可以让我们得到50% 50%的概率事件
可能由于小时候做过类似的思考 几乎秒答：抛两次，先正后反记为1，先反后正记为2。 1和2就是等可能事件。 那么我们是如何避开硬币不均匀的事情的呢，本质就是我们拒绝了一部分事件，比如两次都是正面，或者都是反面。 如果碰到这样的情况，我们需要做的就是重新抛就行啦～

这道题我们当然可以用同样的想法来解决。比如，我们有一个rand7的函数，希望实现rand5。 我们只需要不断的采样，如果得到的值是小于等于5的，我们直接return就行。如果是大于等于5的，我们拒绝重新采样就行。 这样1-5出现的概率一定是一样的（rand7里也是一样的，只不过概率是1/7），又我们拒绝了6，7，那么1-5出现的概率就都是20%啦。
现在我们需要实现rand10，一种我觉得比较巧妙的想法就是。
我们rand7采样两次。第一次决定数字是1-5还是6-10，第二次做一个rand5即可。
第一次我们拒绝7，1-6里奇数决定是1-5，偶数决定是6-10。 第二次我们用自制的rand5采样。 结果用rand5()+rand2()*5即可。

代码
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int five = 0;
        int r = rand7();
        while (r == 7) {
            r = rand7(); 
        } 
        five = r % 2;

        r = rand7();
        while (r >= 6) {
            r = rand7();
        }

        return r + five * 5;
    }
};

作者：wfnuser
链接：https://leetcode-cn.com/problems/implement-rand10-using-rand7/solution/wei-rao-li-lun-yi-ge-bu-jun-yun-ying-bi-fo4ei/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

// rand7()是已知的随机函数
int rand10() {
        int five = 0;
        int r = rand7();
        while (r == 7) {
            r = rand7(); 
        } 
        five = r % 2;

        r = rand7();
        while (r >= 6) {
            r = rand7();
        }

        return r + five * 5;
}