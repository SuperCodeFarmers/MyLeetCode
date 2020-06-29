#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/


string charToint(const char *p)
{
	switch (*p)
	{
	case '2':
		return "abc";
		break;
	case '3':
		return "def";
		break;
	case '4':
		return "ghi";
		break;
	case '5':
		return "jkl";
		break;
	case '6':
		return "mon";
		break;
	case '7':
		return "pqrs";
		break;
	case '8':
		return "tuv";
		break;
	case '9':
		return "wxyz";
		break;
	
	}
}

vector<string> letterCombinations(string digits) {
	
	vector<string> v;

	string str2 = "abc";//'a'+0、1、2
	string str3 = "def";//'a'+3、4、5
	string str4 = "ghi";//'a'+6、7、8
	string str5 = "jkl";//'a'+9、10、11
	string str6 = "mon";//'a'+12、13、14
	string str7 = "pqrs";//'a'+15、16、17、18
	string str8 = "tuv";//'a'+19、20、21
	string str9 = "wxyz";//'a'+22、23、24、25

	int len = digits.size();

	for (int i = 0; i < len; i++)
	{

	}


	return v;
}