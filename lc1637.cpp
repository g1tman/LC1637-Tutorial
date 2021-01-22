#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> xAxis;
        for(auto &x: points) {
            xAxis.insert(x[0]);
        }
        int ans = 0;
        int prev = INT32_MAX;
        for(auto x: xAxis) {
            ans = max(ans, x - prev);
            prev = x;
        }
        return ans;
    }
};

int main() {

    Solution solution;
    
    vector<vector<int>> testCase = {
        {3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}
    };
    
    std::cout << solution.maxWidthOfVerticalArea(testCase) << std::endl;

}
