#include <iostream>
#include <vector>
using namespace std;

// [[1,1],[3,4],[-1,0]]
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int len = points.size();
    if(len == 1) {
        return 0;
    }
    int count = 0;
    for (int i = 1; i < len; ++i) {
        int x = points[i][0] - points[i - 1][0];
        x = (x < 0) ? -x:x;
        int y = points[i][1] - points[i - 1][1];
        y = (y < 0) ? -y:y;
        count += max(x,y);
    }
    return count;
}

int main()
{
vector<vector<int>> arr = {{3,2}, {-2,2}};
cout << minTimeToVisitAllPoints(arr);
    return 0;
}

