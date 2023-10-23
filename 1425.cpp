#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> dp(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && i - q.front() > k) q.pop_front();

            dp[i] = (q.empty() ? 0 : dp[q.front()]) + nums[i];

            while (!q.empty() && dp[i] > dp[q.back()]) q.pop_back();

            if (dp[i] > 0) q.push_back(i);
        }
        
        return *max_element(begin(dp), end(dp));
    }
};

int main() {
    Solution s;
    vector<int> nums = {10,2,-10,5,20};
    int k = 2;
    cout << s.constrainedSubsetSum(nums, k) << endl;
    return 0;
}