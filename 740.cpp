#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freq;
        int mx = INT32_MIN;
        for (auto& x : nums) {
            freq[x]++;
            mx = max(mx, x);
        }
        vector<int> dp(mx + 1, 0);
        dp[1] = freq[1];
        for (int i = 2; i <= mx; i++) {
            dp[i] = max((i * freq[i]) + dp[i - 2], dp[i - 1]); 
        }
        return dp[mx];
    }
};