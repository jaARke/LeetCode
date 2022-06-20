#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    static bool comp(vector<int>& lhs, vector<int>& rhs) {
        // Sort by increasing order of width and, in case of tie, decreasing order of height
        // This ensures that a LIS on the heights gives the maximum number of envelopes that can be fit into one another
        if (lhs[0] == rhs[0]) {
            return lhs[1] > rhs[1];
        }
        return lhs[0] < rhs[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> LIS;
        int result = 0;
        for (auto& envelope : envelopes) {
            auto iter = lower_bound(LIS.begin(), LIS.end(), envelope[1]);
            if (iter == LIS.end()) {
                LIS.push_back(envelope[1]);
                result++;
            }
            else {
                *iter = envelope[1];
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> envelopes = {{4,5},{4,6},{6,7},{2,3},{1,1}};
    cout << s.maxEnvelopes(envelopes) << endl;
    return 0;
}