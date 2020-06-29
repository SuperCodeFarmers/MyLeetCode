#include <iostream>
#include <string>
#include <map>
using namespace std;

//可以使用string中的substr进行子串的构建
//1--3999
int romanToInt(string s) {
	
	if (s.size() == 0)
	{
		return 0;
	}
	int num = 0;
	map<string, int> keyValue = {
		{"I",1},{"IV",4} ,{"V",5},{"IX",9},
		{"X",10},{"XL",40},{"L",50},{"XC",90},
		{"C",100},{"CD",400},{"D",500},{"CM",900}, {"M",1000}
	};
	string::iterator item = s.begin();
	//MCMXCIV
	for (int i = 0; i < s.size();)
	{
		string str;
		if (i + 1 < s.size())
		{
			str = string(item + i, item + i + 2);
		}
		else
		{
			str = string(item + i, s.end());
		}
		auto search1 = keyValue.find(str);
		if (search1 != keyValue.end())
		{
			num += keyValue[str];
			i += 2;
		}
		else
		{
			str = string(item + i, item + i + 1);
			num += keyValue[str];
			i++;
		}

	}

	return num;

}