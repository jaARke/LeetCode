#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool flag = false;
        int currStart, currEnd;
        intervals.push_back({INT32_MAX, INT32_MAX});    // So that the algorithm inserts the final interval into result
        // See which interval to start with -> intervals[0] or newInterval (based on minimum starting position)
        if (newInterval[0] < intervals[0][0]) {
            currStart = newInterval[0];
            currEnd = newInterval[1];
            flag = true;
        }
        else {
            currStart = intervals[0][0];
            currEnd = intervals[0][1];
        }
        for (auto& x : intervals) {
            if (!flag && currEnd >= newInterval[0]) {   // newInterval has not been used and it starts before the current interval ends (potential overlap)
                flag = true;
                if (currStart > newInterval[1]) {   // The newInterval starts and ends completely before the current one -> add it whole to the result
                    res.push_back({newInterval[0], newInterval[1]});
                }
                else {  // The newInterval could be used to extend either the beginning or end of the current interval
                    currStart = min(newInterval[0], currStart);
                    currEnd = max(newInterval[1], currEnd);
                }
            }
            if (currEnd >= x[0]) {  // The current interval can be extended
                currEnd = max(currEnd, x[1]);
            }
            else {  // The current interval cannot be extended any further -> add it to the result and start over
                res.push_back({currStart, currEnd});
                currStart = x[0];
                currEnd = x[1];
            }
        }
        if (!flag) {    // There was never any potential for overlap -> the newInterval's start is greater than the end of any of the original intervals -> add it whole to the result
            res.push_back({newInterval[0], newInterval[1]});
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1,5}};
    vector<int> newInterval = {6,8};
    auto res = s.insert(intervals, newInterval);
    cout << "Done!" << endl;
    return 0;
}