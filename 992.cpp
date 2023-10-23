#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int subArraysWithAtMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        int ans = 0;

        for (int i = 0, j = 0; j < nums.size(); j++) {
            if (!freqs[nums[j]]) k--;
            
            freqs[nums[j]]++;

            while (k < 0) {
                if (--freqs[nums[i++]] == 0) k++;
            }

            ans += j - i + 1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subArraysWithAtMostK(nums, k) - subArraysWithAtMostK(nums, k - 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,1,3,4};
    int k = 3;
    cout << s.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}