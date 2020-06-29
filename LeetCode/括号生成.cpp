#include <iostream>
#include <string>
#include <vector>
using namespace std;

//我们可以生成所有 2^2n个'('和')'字符构成的序列。然后，我们将检查每一个是否有效。




//k表示已生成了k个左括号
void backtrack(vector<string> &v, string s, int k, int n)
{
	if (k >= n)
	{
		s.append(n * 2 - s.size(), ')');
		v.push_back(s);
	}
	else
	{
		if (k > static_cast<int>(s.size()) - k)    //左括号大于右括号数
		{
			backtrack(v, s + "(", k + 1, n);
			backtrack(v, s + ")", k, n);
		}
		else if (k == s.size() - k)  //左括号等于右括号数
		{
			backtrack(v, s + "(", k + 1, n);
		}
	}
}

vector<string> generateParenthesis(int n) {

	vector<string> v;
	backtrack(v, "", 0, n);
	return v;


}

bool valid(string current)
{
	int l = 0, r = 0;

	auto itr = current.begin();
	while (itr != current.end())
	{
		if (*itr == '(')
		{
			l++;
		}
		if (*itr == ')')
		{
			r++;
		}
		itr++;

	}
	return (l - r) == 0;

}

int main1()
{
	auto a = generateParenthesis(5);
	for (auto v : a)
	{
		cout << v << endl;
	}
	return 1;
}

