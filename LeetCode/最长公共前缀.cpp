#include <iostream>
#include <vector>
#include <string>

using namespace std;

string LCP(string str1, string str2)
{
	string temp;
	auto p1 = str1.begin();
	auto p2 = str2.begin();
	while (p1!=str1.end() && p2!=str2.end() && (*p1) == (*p2))
	{
		temp += (*p1);
		++p1;
		++p2;		
	}

	return temp;
}

string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size()==0)
	{
		return "";
	}
	if (strs.size()==1)
	{
		return strs[0];
	}
	string str = LCP(strs[0], strs[1]);
	for (int i = 2; i < strs.size(); i++)
	{
		str = LCP(str, strs[i]);
	}
	return str;
}


int LCPMAIN()
{
	vector<string> s = {"flower"};
	
	
	string temp;
	cout << longestCommonPrefix(s) << endl;


	cout << "Hello World" << endl;
	return 0;
}