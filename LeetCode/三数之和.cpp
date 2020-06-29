#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum1(vector<int>& nums) {

	sort(nums.begin(), nums.end());
	
	vector<vector<int>> array;

	vector<int> vec;
	for (int i = 0; i < nums.size(); i++)
	{
		
	}


	return array;

}



vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	vector<vector<int>> ans = {};
	for (int i = 0; i < len; ++i) {
		//去重
		if (i != 0 && nums[i] == nums[i - 1]) 
			continue;

		int j = (i + 1 < len) ? i + 1 : len - 1;
		int k = len - 1;
		while (j < k) {
			if (nums[j] + nums[k] == -(nums[i])) {
				vector<int> tmp = { nums[i],nums[j],nums[k] };
				ans.push_back(tmp);
				j++;
				while (j < len - 1 && nums[j] == nums[j - 1]) j++;
			}
			else if (nums[j] + nums[k] < -(nums[i])) {
				j++;
			}
			else {
				k--;
			}
		}
	}
	return ans;
}







int main()
{
	vector<vector<int>> a;
	vector<int> num{ -1, 0, 1, 2, -1, -4 };
	a = threeSum(num);
	

	for (auto Iter = a.begin(); Iter != a.end(); Iter++)
	{
		for (auto i=(*Iter).begin();i!=(*Iter).end();i++)
		{
			cout << *i << " ";
		}
		cout << endl;
	}

}