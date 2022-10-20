#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


/*
Inuitive solution -> find all subarrays and check if nums2 shares them -> TLE
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        set<vector<int>> s;
        // Find all subarrays of nums1
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i; j >= 0; j--) {
                s.insert(vector<int>(nums1.begin() + j, nums1.begin() + i + 1));
            }
        }
        // Search all subarrays of nums2
        int maxLen = 0;
        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i; j >= 0; j--) {
                auto iter = s.find(vector<int>(nums2.begin() + j, nums2.begin() + i + 1));
                if (iter != s.end()){
                    maxLen = max(maxLen, (int)iter->size());
                }            
            }
        }
        return maxLen;
    }
};
*/

// Top down DP approach
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxLen = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    cout << s.findLength(nums1, nums2) << endl;

    string test = "ddddd";
    string text2 = "dddd";
    cout << test.find(text2) << endl;
    return 0;
}