#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int currEnd = INT32_MIN;
        int res = 0;

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < currEnd) {
                res++;
                continue;
            }
            currEnd = intervals[i][1];
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};

    cout << s.eraseOverlapIntervals(intervals) << endl;
}