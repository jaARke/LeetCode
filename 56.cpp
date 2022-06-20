#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int>& lhs, vector<int>& rhs) {
        if (lhs[0] == rhs[0]) {
            return lhs[1] < rhs[1];
        }
        return lhs[0] < rhs[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        int currMin = intervals[0][0], currMax = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= currMax) {
                currMax = max(currMax, intervals[i][1]);
            }
            else {
                res.push_back({currMin, currMax});
                currMin = intervals[i][0];
                currMax = intervals[i][0];
            }
        }
        res.push_back({currMin, currMax});
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1,4},{0,4}};
    auto result = s.merge(intervals);
    cout << "Done!" << endl;
    return 0;
}