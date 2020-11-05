#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 二分查找
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        }
    }

    return -1;
}


int left_bound(vector<int>& arr, int target) {
    if (arr.size() == 0)
        return -1;

    int left = 0;
    int right = arr.size();

    while(left < right) {
        int mid = (left + right) / 2;
        if(arr[mid] == target) {
            right = mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid;
        }
    }

    if (left == arr.size())
        return -1;

    if (arr[left] == target)
        return left;
    else
        return -1;
}

int main()
{
    vector<int> arr = {1, 2,4,4,4,4,4,4,4,4,4,4};
    sort(arr.begin(), arr.end());
    for (auto a : arr) {
       std::cout << a << " ";
    }   
    cout << endl;
    int ret = binarySearch(arr, 23);
    cout << ret << endl;
    ret = binarySearch(arr, 4);
    cout << ret << endl;
    return 0;
}

