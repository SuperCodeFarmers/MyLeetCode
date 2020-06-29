#include<iostream>

/*
方法：弹出和推入数字 & 溢出前进行检查

思路

我们可以一次构建反转整数的一位数字。在这样做的时候，我们可以预先检查向原整数附加另一位数字是否会导致溢出。

算法

反转整数的方法可以与反转字符串进行类比。

我们想重复“弹出” xx 的最后一位数字，并将它“推入”到 \text{rev}rev 的后面。最后，\text{rev}rev 将与 xx 相反。
要在没有辅助堆栈 / 数组的帮助下 “弹出” 和 “推入” 数字，我们可以使用数学方法。
//pop operation:
pop = x % 10;
x /= 10;
//push operation:
temp = rev * 10 + pop;
rev = temp;
但是，这种方法很危险，因为当 temp = rev * 10 + pop 时会导致溢出。

幸运的是，事先检查这个语句是否会导致溢出很容易。

为了便于解释，我们假设 {rev} 是正数。

如果 temp=rev*10+pop 导致溢出，那么一定有 rev >= INT_MAX/10。
如果 rev>INT_MAX/10 ，那么temp = rev * 10 + pop一定会溢出。
如果 rev == INT_MAX/10 ，那么只要 pop>7,temp = rev*10+pop就会溢出。
当 rev 为负时可以应用类似的逻辑。

*/

class Solution {
public:
	int reverse(int x) {
		int  value = 0;
		int temp = x;

		while (temp != 0)
		{
			int i = temp % 10;
			temp /= 10;

			if (value > (INT_MAX / 10) || (value == INT_MAX / 10 && i > 7))
			{
				return 0;
			}

			if (value < (INT_MIN / 10) || (value == INT_MIN / 10 && i < -8))
			{
				return 0;
			}

			value = value * 10;
			value += i;
		}
		return value;
	}
};